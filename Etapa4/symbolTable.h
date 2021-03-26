#include "ast.h"

typedef enum
{
    NATURE_literal,
    NATURE_variable,
    NATURE_vector,
    NATURE_function
} Nature;

typedef enum
{
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_UNDEFINED
} Type;

typedef struct symbolTableEntry
{
    char *key;
    int line;
    Nature nature;
    Type type;
    int size;
    struct symbolTableEntry *args;
    LexicalValue lexicalValue;

    struct symbolTableEntry *nextEntry;
} SymbolTableEntry;

typedef struct symbolTableStack
{
    SymbolTableEntry *top;
    struct symbolTableStack *rest;
} SymbolTableStack;

SymbolTableEntry *createTableEntry(char *key, int line, Nature nature, Type type, int size);
SymbolTableEntry *findEntryInTable(SymbolTableEntry *table, char *key);
void freeSymbolTable(SymbolTableEntry *table);

SymbolTableStack *createScope(SymbolTableStack *stack);
SymbolTableEntry *findEntryInStack(SymbolTableStack *stack, char *key);
SymbolTableEntry *popScope(SymbolTableEntry *stack);
void freeTableStack(SymbolTableStack *stack);