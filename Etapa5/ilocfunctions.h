#include <stdio.h>

#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15

typedef enum {
    HALT,
    NOP,
    ADD,
    SUB,
    MULT,
    DIV,
    ADDI,
    LOADI,
    LOADAI,
    STOREAI,
    I2I,
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

} Code;


char* generateLabelName();
char* generateRegisterName();