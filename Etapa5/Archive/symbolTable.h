#include "tokenutils.h"

extern int get_line_number(void);

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
    int entryOffset;

    struct symbolTableEntry *nextEntry;
} SymbolTableEntry;

typedef struct symbolTableStack
{
    int isGlobal;
    int tableOffset;
    SymbolTableEntry *top;
    struct symbolTableStack *rest;
} SymbolTableStack;

typedef struct stringListT
{
    char *value;
    struct stringListT *next;
} StringList;

//
StringList *createStringList(char *value);
void freeStringList(StringList *first);

// Tabela de simbolos
SymbolTableEntry *createTableEntry(char *key, int line, Nature nature, Type type, int size, TokenData *data);
SymbolTableEntry *findEntryInTable(SymbolTableEntry *table, char *key);
SymbolTableStack *findEntryTable(SymbolTableStack *topStack, char *key);
SymbolTableEntry *findLiteralEntryInTable(SymbolTableEntry *table, char *key);
void addEntryToTopScopeTable(SymbolTableEntry *entry);
void addEntryToTable(SymbolTableEntry *table, SymbolTableEntry *entry);
void freeSymbolTable(SymbolTableEntry *table);
void printTable(SymbolTableEntry *table);

//Pilha de tabelas de simbolos
SymbolTableStack *stackScope();
SymbolTableEntry *findEntryInStack(SymbolTableStack *stack, char *key);
SymbolTableEntry *findLiteralEntryInStack(SymbolTableStack *stack, char *key);
SymbolTableStack *popScope();
void freeTableStack(SymbolTableStack *stack);

// Escopos
void createGlobalScope();
int getNumberOfStackedScopes();
SymbolTableEntry *getCurrentScope();
SymbolTableStack *getGlobalStack();

// Criaçao de entradas da tabela
void createLiteralTableEntry(int line, Type type, TokenData *token);
SymbolTableEntry *createVariableTableEntry(char *identifier, int line, Type type, TokenData *token);
void createStringVariableTableEntry(char *identifier, int line, TokenData *token, char *value);
void createVectorTableEntry(char *identifier, int line, Type type, int size, TokenData *token);
void createFunctionTableEntry(char *identifier, int line, Type type, TokenData *token);

void updateEntrySize(SymbolTableEntry *entry, int size);

void addArgumentsToLastDefinedFunction();

void initiateVariableListDeclaration();
void endVariableListDeclaration(Type type);
StringList *getVariableListDeclaration();
void cleanVariableListDeclaration();
void addVariableToListDeclaration(char *key);

int getSizeFromType(Type type);

Type getEntryTypeFromKey(char *key);

// Verificaçao do uso de identificadores
void verifyVariableUse(char *identifier);
void verifyVectorUse(char *identifier);
void verifyFunctionUse(char *identifier);

void verifyFunctionCallParams(char *functionName, Node *firstParam);

// Tipos
int allowsImplicitConversion(Type type1, Type type2);
void verifyUnaryOperatorType(char *operator, Type type);
Type inferType(Type type1, Type type2);

// Lançamento de erros
void throwDeclaredError(char *name, int previousDeclarationLine);
void throwUndeclaredError(char *name);
void throwVariableError(char *name, int declarationLine, Nature nature);
void throwVectorError(char *name, int declarationLine, Nature nature);
void throwFunctionError(char *name, int declarationLine, Nature nature);
void throwExcessArgsError(char *name, int declarationLine);
void throwMissingArgsError(char *name, int declarationLine);
void throwWrongTypeArgsError(char *name, int declarationLine);
void throwFunctionStringError(char *name, int declarationLine);
void throwWrongTypeError(char *name);
void throwWrongParInput(int line);
void throwWrongParOutput(int line);
void throwShiftError(int line);
void throwCharToXError(char *name);
void throwStringToXError(char *name);
void throwStringSizeError(char *name, int declarationLine);
void throwReturnError(int line);
void throwStringVectorError(int line);

int isNodeLiteralAndString(Node *node);

// Tipos e naturezas
char *getTypeName(Type type);
char *getNatureName(Nature nature);
char *generateLiteralKey(TokenData *token);
int getVectorSize(Type type, int size);