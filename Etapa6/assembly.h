#include "ilocfunctions.h"

void printAssembly(Code *c);
void push_Asm();
void pop_Asm(char *reg);
char *registerConversion(char *reg);
void print_division_op_assembly(char *op);
void print_binary_op_assembly(char *op);
void push();
void pop(char *reg);
char * getKeyFromOffset(int offset);