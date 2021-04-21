#include <stdio.h>
#include "ast.h"

#define MAXLABELSIZE 15
#define MAXREGISTERSIZE 15
#define RBSS //register for global variables
#define RFP  //register for local variables

char *generateLabelName();
char *generateRegisterName();

Code *generate(Node *node);