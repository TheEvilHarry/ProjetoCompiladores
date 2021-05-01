#define MAX_LABEL_SIZE 100
#define MAX_CHILDREN 4

typedef enum
{
    NOP,
    HALT,
    ADD,
    SUB,
    MULT,
    DIV,
    ADDI,
    SUBI,
    RSUBI,
    MULTI,
    DIVI,
    AND,
    ANDI,
    OR,
    ORI,
    LOAD,
    LOADI,
    LOADAI,
    LOAD0,
    CLOAD,
    CLOADAI,
    CLOADA0,
    STORE,
    STOREAI,
    STOREA0,
    CSTORE,
    CSTOREAI,
    CSTOREA0,
    I2I,
    C2C,
    C2I,
    I2C,
    JUMPI,
    JUMP,
    CBR,
    CMP_LT,
    CMP_LE,
    CMP_EQ,
    CMP_GE,
    CMP_GT,
    CMP_NE
} Operation;

typedef struct t_code
{
    char *label;
    char *pointer;
    char *res;
    Operation opCode;
    char *arg1;
    char *arg2;
    char *arg3;
    char *dest1;
    char *dest2;
    struct t_code *next;
    struct t_code *prev;
} Code;

typedef enum
{
    TYPE_UNDEFINED = 0,
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_CHAR
} Type;

typedef enum lexicalValueLiteralType
{
    LIT_INTEGER,
    LIT_FLOAT,
    LIT_BOOLEAN,
    LIT_CHAR,
    LIT_STRING,
    NOT_LITERAL
} Literal;

typedef enum lexicalValueTokenType
{
    IDENTIFIER_TOKEN,
    LITERAL_TOKEN,
    SPECIAL_CHAR_TOKEN,
    COMPOSITE_OPERATOR_TOKEN,
    SPECIAL_TYPE
} Token;

typedef union lexicalValue
{
    int valueInt;
    float valueFloat;
    int valueBoolean;
    char valueChar;
    char valueString[MAX_LABEL_SIZE];
} LexicalValue;

typedef struct t_token_data
{
    int line;
    Token type;
    Literal literal;

    char label[MAX_LABEL_SIZE];
    LexicalValue value;

} TokenData;

typedef struct t_ast_node
{
    TokenData *data;
    struct t_ast_node *children[MAX_CHILDREN];
    struct t_ast_node *next;
    int numberOfChildren;
    Type type;
    Code *code;
} Node;

TokenData *createNonLiteralToken(int line, Token type, char *value);

TokenData *createIntegerLiteralToken(int line, char *value);

TokenData *createFloatLiteralToken(int line, char *value);

TokenData *createBooleanLiteralToken(int line, char *value);

TokenData *createCharLiteralToken(int line, char *value);

TokenData *createStringLiteralToken(int line, char *value);

Operation getOperation(char *op);

void freeToken(TokenData *data);