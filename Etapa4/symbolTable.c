#include "ast.h"
#include "symbolTable.h"

SymbolTableEntry *createTableEntry(char *key, int line, Nature nature, Type type, int size, LexicalValue data)
{
  SymbolTableEntry *entry = malloc(sizeof(SymbolTableEntry));

  entry->key = key;
  entry->line = line;
  entry->size = size;
  entry->nature = nature;
  entry->type = type;
  entry->lexicalValue = data;
};
SymbolTableEntry *findEntryInTable(SymbolTableEntry *table, char *key){};
void freeSymbolTable(SymbolTableEntry *table){};

SymbolTableStack *createScope(SymbolTableStack *stack){};
SymbolTableEntry *findEntryInStack(SymbolTableStack *stack, char *key){};
SymbolTableEntry *popScope(SymbolTableEntry *stack){};
void freeTableStack(SymbolTableStack *stack){};