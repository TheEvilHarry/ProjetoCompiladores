#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include "errors.h"

extern int get_line_number(void);

SymbolTableStack *stack = NULL;
int declaringVariableList = 0;
StringList *variableListDeclarationKeys;

StringList *createStringList(char *value)
{
  StringList *list = malloc(sizeof(StringList));

  list->value = strdup(value);
  list->next = NULL;

  return list;
}

void freeStringList(StringList *first)
{
  if (first == NULL)
  {
    return;
  }

  if (first->next != NULL)
  {
    freeStringList(first->next);
  }

  free(first->value);
  free(first);
}

void printTable(SymbolTableEntry *table)
{
  SymbolTableEntry *currentEntry = table;
  while (currentEntry != NULL)
  {
    printf("[KEY: %s][LINE: %d][NATURE: %d][TYPE: %d][SIZE: %d]\n", currentEntry->key, currentEntry->line, currentEntry->nature, currentEntry->type, currentEntry->size);
    currentEntry = currentEntry->nextEntry;
  }
}

SymbolTableEntry *createTableEntry(char *key, int line, Nature nature, Type type, int size, TokenData *data)
{
  SymbolTableEntry *entry = malloc(sizeof(SymbolTableEntry));

  entry->key = strdup(key);
  entry->line = line;
  entry->size = size;
  entry->nature = nature;
  entry->type = type;
  entry->data = data;
  entry->nextEntry = NULL;
};

void addEntryToTopScopeTable(SymbolTableEntry *entry)
{
  if (stack->top == NULL)
  {
    stack->top = entry;
  }
  else
  {
    SymbolTableEntry *aux = stack->top;
    while (aux->nextEntry != NULL)
    {
      aux = aux->nextEntry;
    }

    aux->nextEntry = entry;
  }
}

SymbolTableEntry *findEntryInTable(SymbolTableEntry *table, char *key)
{
  // printf("Looking for %s in scope table\n", key);
  // printTable(getCurrentScope());
  // if (table == NULL)
  // {
  //   printf("Table is NULL\n");
  // }
  SymbolTableEntry *currentEntry;
  for (currentEntry = table; currentEntry != NULL; currentEntry = currentEntry->nextEntry)
  {
    // printf("Current key is %s and target key is %s\n", currentEntry->key, key);
    if (strcmp(currentEntry->key, key) == 0)
    {
      // printf("Keys match! Returning entry\n");
      return currentEntry;
    }
  }

  return NULL;
};

void freeSymbolTable(SymbolTableEntry *table)
{
  if (table == NULL)
  {
    return;
  }

  SymbolTableEntry *next = table->nextEntry;
  table->nextEntry = NULL;

  free(table->key);
  freeSymbolTableEntryArgs(table->arguments);

  // Liberar valor lexico
  freeToken(table->data);

  free(table);
  freeSymbolTable(next);
};

void freeSymbolTableEntryArgs(SymbolTableEntry *arguments)
{
  if (arguments != NULL)
  {
    freeSymbolTableEntryArgs(arguments->nextEntry);
  }

  free(arguments);
}

SymbolTableStack *stackScope(SymbolTableStack *stack, SymbolTableEntry *scope)
{
  SymbolTableStack *newStack = malloc(sizeof(SymbolTableStack));

  newStack->top = scope;
  newStack->rest = stack;

  return newStack;
};

SymbolTableEntry *findEntryInStack(SymbolTableStack *stack, char *key)
{
  SymbolTableStack *currentStackElement = NULL;
  SymbolTableEntry *entry = NULL;

  for (currentStackElement = stack; currentStackElement != NULL; currentStackElement = currentStackElement->rest)
  {
    entry = findEntryInTable(currentStackElement->top, key);
    if (entry != NULL)
    {
      return entry;
    }
  }

  return NULL;
};
SymbolTableStack *popScope(SymbolTableStack *stack)
{
  SymbolTableStack *newStackTop = stack->rest;
  freeSymbolTable(stack->top);
  stack->top = NULL;
  free(stack);

  return newStackTop;
};
void freeTableStack(SymbolTableStack *stack)
{
  if (stack == NULL)
  {
    return;
  }

  freeSymbolTable(stack->top);
  stack->top = NULL;
  free(stack);
};

void createGlobalScope()
{
  if (stack == NULL)
  {
    SymbolTableStack *newStack = malloc(sizeof(SymbolTableStack));

    newStack->top = NULL;
    newStack->rest = NULL;

    stack = newStack;
  }
  else
  {
    printf("[WARNING] Attempted to create global scope but a scope is already defined\n");
  }
}

SymbolTableEntry *getCurrentScope()
{
  if (stack == NULL)
  {
    // printf("[WARNING] Attempted to get current scope but no scope is defined\n");
    createGlobalScope();
  }
  return stack->top;
};

void initiateVariableListDeclaration()
{
  printf("Starting variable list declaration\n");
  declaringVariableList = 1;
}

void endVariableListDeclaration(Type type)
{
  printf("Ending variable list declaration\n");
  StringList *currentKey = variableListDeclarationKeys;
  SymbolTableEntry *currentEntry = NULL;
  while (currentKey != NULL)
  {
    currentEntry = findEntryInTable(getCurrentScope(), currentKey->value);
    if (currentEntry != NULL)
    {
      currentEntry->type = type;
      currentEntry->size = getSizeFromType(type);
    }
    else
    {
      printf("[WARNING] Key %s from variable list declaration is not in current scope. Could not add type.", currentKey->value);
    }

    currentKey = currentKey->next;
  }

  freeStringList(variableListDeclarationKeys);
  variableListDeclarationKeys = NULL;
  declaringVariableList = 0;
}

void addVariableToListDeclaration(char *key)
{
  StringList *currentElement = variableListDeclarationKeys;
  if (currentElement == NULL)
  {
    variableListDeclarationKeys = createStringList(key);
  }
  else
  {
    while (currentElement->next != NULL)
    {
      currentElement = currentElement->next;
    }

    currentElement->next = createStringList(key);
  }
}

int getSizeFromType(Type type)
{
  switch (type)
  {
  case TYPE_INTEGER:
    return 4;
    break;
  case TYPE_FLOAT:
    return 8;
    break;
  case TYPE_STRING:
    return 1;
    break;
  case TYPE_BOOL:
    return 1;
    break;
  default:
    return 0;
    break;
  }
}

//
void createLiteralTableEntry(char *identifier, int line, Type type, TokenData *token);

void createVariableTableEntry(char *identifier, int line, Type type, TokenData *token)
{
  printf("Starting variable table entry creation for %s\n", identifier);
  // printTable(getCurrentScope());
  if (type == TYPE_UNDEFINED)
  {
    printf("[WARNING] Creating a variable without a type\n");
  }

  SymbolTableEntry *redeclared = findEntryInTable(getCurrentScope(), identifier);

  if (redeclared != NULL)
  {
    throwDeclaredError(identifier, redeclared->line);
  }
  else
  {
    SymbolTableEntry *entry = createTableEntry(identifier, line, NATURE_variable, type, getSizeFromType(type), token);
    addEntryToTopScopeTable(entry);
    if (type == TYPE_UNDEFINED)
    {
      addVariableToListDeclaration(identifier);
    }
  }

  printf("Table after variable %s creation:\n", identifier);
  printTable(getCurrentScope());
  printf("\n\n");
}

void createVectorTableEntry(char *identifier, int line, Type type, int size, TokenData *token);

void createFunctionTableEntry(char *identifier, int line, Type type, TokenData *token)
{
  printf("Starting function table entry creation for %s\n", identifier);
  if (type == TYPE_UNDEFINED)
  {
    printf("[WARNING] Created a function without a type\n");
  }

  SymbolTableEntry *redeclared = findEntryInTable(getCurrentScope(), identifier);

  if (redeclared != NULL)
  {
    throwDeclaredError(identifier, redeclared->line);
  }
  else
  {
    SymbolTableEntry *entry = createTableEntry(identifier, line, NATURE_function, type, getSizeFromType(type), token);
    addEntryToTopScopeTable(entry);
  }
}

Type getEntryTypeFromKey(char *key)
{
  SymbolTableEntry *entry;
  entry = findEntryInTable(getCurrentScope(), key);

  if (entry == NULL) // Talvez seja melhor mover essa logica para uma funçao separada mais tarde
  {
    throwUndeclaredError(key);
  }
  else
  {
    return entry->type;
  }
}

//
void throwDeclaredError(char *name, int previousDeclarationLine)
{
  printf("[ERROR][Line %d]: Identifier \"%s\" already declared on line %d\n", get_line_number(), name, previousDeclarationLine);
  exit(ERR_DECLARED);
}

void throwUndeclaredError(char *name)
{
  printf("[ERROR][Line %d]: Identifier \"%s\" was used but was not defined\n", get_line_number(), name);
  exit(ERR_UNDECLARED);
}