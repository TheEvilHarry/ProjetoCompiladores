#include "ast.h"

typedef enum
{
    NATURE_literal,
    NATURE_variable,
    NATURE_vector,
    NATURE_function
} Nature;

typedef struct symbolTableEntry
{
    char *key;
    int line;
    Nature nature;
    Type type;
    int size;
    struct symbolTableEntry *arguments;
    TokenData *data;

    struct symbolTableEntry *nextEntry;
} SymbolTableEntry;

typedef struct symbolTableStack
{
    SymbolTableEntry *top;
    struct symbolTableStack *rest;
} SymbolTableStack;

// Tabela de simbolos
SymbolTableEntry *createTableEntry(char *key, int line, Nature nature, Type type, int size, TokenData *data);
SymbolTableEntry *findEntryInTable(SymbolTableEntry *table, char *key);
void addEntryToTopScopeTable(SymbolTableEntry *entry);
void freeSymbolTable(SymbolTableEntry *table);
void freeSymbolTableEntryArgs(SymbolTableEntry *arguments);
//Pilha de tabelas de simbolos
SymbolTableStack *stackScope(SymbolTableStack *stack, SymbolTableEntry *scope);
SymbolTableEntry *findEntryInStack(SymbolTableStack *stack, char *key);
SymbolTableStack *popScope(SymbolTableStack *stack);
void freeTableStack(SymbolTableStack *stack);
//
void createGlobalScope();
SymbolTableEntry *getCurrentScope();
//
void createLiteralTableEntry(char *identifier, int line, Type type, TokenData *token);
void createVariableTableEntry(char *identifier, int line, Type type, TokenData *token);
void createVectorTableEntry(char *identifier, int line, Type type, int size, TokenData *token);
void createFunctionTableEntry(char *identifier, int line, Type type, TokenData *token);

void initiateVariableListDeclaration(Type type);
void endVariableListDeclaration();

int getSizeFromType(Type type);

Type getEntryTypeFromKey(char *key);

// Lançamento de erros
void throwDeclaredError(char *name, int previousDeclarationLine);
void throwUndeclaredError(char *name);