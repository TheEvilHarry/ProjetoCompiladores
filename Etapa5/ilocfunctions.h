#include <stdio.h>
#include "symbolTable.h"

#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15
#define RBSS "rbss" //register for global variables
#define RFP  "rfp" //register for local variables

char *generateLabelName();
char *generateRegisterName();
Code *createCode(Operation op, char *local, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2);
int setsOffset(char *symbol, int *scope);
char *getsDestForLOADAI();
Code *generateLabelCode(char * label);
Code *createCBRCode(Node *expr, char* r1, char *l1, char *l2, Node* trueExpr);
Code *generatesIfCode(Node * expr, Node *trueExpr, Node *falseExpr);
Code *generateLabelCode(char * label);
Code *generateTrueConditionalJump(char *l1);
Code *generate(Node *node);