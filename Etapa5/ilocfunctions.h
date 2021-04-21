#include <stdio.h>

#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15
#define RBSS  //register for global variables
#define RFP   //register for local variables

typedef enum {
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

typedef struct t_code {

    char *label;
    Operation opCode;
    char *arg1;
    char *arg2;
    char *arg3;
    char *dest1;
    char *dest2;
    struct t_code *next;
    struct t_code *prev;

} Code;


char* generateLabelName();
char* generateRegisterName();