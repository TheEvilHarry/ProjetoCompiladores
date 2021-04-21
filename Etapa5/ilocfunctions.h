#include <stdio.h>
#include "ast.h"

#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15
#define RBSS //register for global variables
#define RFP  //register for local variables

char *generateLabelName();
char *generateRegisterName();
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

Code *generate(Node *node);