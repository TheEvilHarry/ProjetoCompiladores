#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include "errors.h"

extern int get_line_number(void);

SymbolTableStack *stack = NULL;
Type variableListDeclarationType = TYPE_UNDEFINED;

SymbolTableEntry *createTableEntry(char *key, int line, Nature nature, Type type, int size, TokenData *data)
{
  printf("Creating table entry for %s\n", key);
  SymbolTableEntry *entry = malloc(sizeof(SymbolTableEntry));

  entry->key = key;
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
  printf("Looking for %s in scope table\n", key);
  if (table == NULL)
  {
    printf("Table is NULL\n");
  }
  SymbolTableEntry *currentEntry;
  for (currentEntry = table; currentEntry != NULL; currentEntry = currentEntry->nextEntry)
  {
    printf("Current key is %s and target key is %s\n", currentEntry->key, key);
    if (strcmp(currentEntry->key, key) == 0)
    {
      printf("Keys match! Returning entry\n");
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
    printf("[WARNING] Attempted to get current scope but no scope is defined\n");
    createGlobalScope();
  }
  return stack->top;
};

void initiateVariableListDeclaration(Type type)
{
  printf("Starting variable list declaration\n");
  variableListDeclarationType = type;
}

void endVariableListDeclaration()
{
  printf("Ending variable list declaration\n");
  variableListDeclarationType = TYPE_UNDEFINED;
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
    break;
  }
}

//
void createLiteralTableEntry(char *identifier, int line, Type type, TokenData *token);

void createVariableTableEntry(char *identifier, int line, Type type, TokenData *token)
{
  printf("Starting variable table entry creation for %s\n", identifier);
  Type auxType;
  if (type == TYPE_UNDEFINED)
  {
    if (variableListDeclarationType == TYPE_UNDEFINED)
    {
      printf("[WARNING] Created a variable without a type\n");
    }
    auxType = variableListDeclarationType;
  }

  SymbolTableEntry *redeclared = findEntryInTable(getCurrentScope(), identifier);

  if (redeclared != NULL)
  {
    throwDeclaredError(identifier, redeclared->line);
  }
  else
  {
    SymbolTableEntry *entry = createTableEntry(identifier, line, NATURE_variable, auxType, getSizeFromType(auxType), token);
    addEntryToTopScopeTable(entry);
  }
}

void createVectorTableEntry(char *identifier, int line, Type type, int size, TokenData *token);

void createFunctionTableEntry(char *identifier, int line, Type type, TokenData *token)
{
  printf("Starting function table entry creation for %s\n", identifier);
  Type auxType;
  if (type == TYPE_UNDEFINED)
  {
    if (variableListDeclarationType == TYPE_UNDEFINED)
    {
      printf("[WARNING] Created a function without a type\n");
    }
    auxType = variableListDeclarationType;
  }

  SymbolTableEntry *redeclared = findEntryInTable(getCurrentScope(), identifier);

  if (redeclared != NULL)
  {
    throwDeclaredError(identifier, redeclared->line);
  }
  else
  {
    SymbolTableEntry *entry = createTableEntry(identifier, line, NATURE_function, auxType, getSizeFromType(auxType), token);
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