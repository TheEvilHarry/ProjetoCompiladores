// TODO:
// Functions signed with the TO DO sign;
// Treatment of new variable Local in Node object

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ilocfunctions.h"


int currentLabel = 1;
int currentRegister = 0;

 char *generateLabelName()
 {

     char newLabel[MAXLABELSIZE] = "L";
     char index[10] = itoa(currentLabel);
     strcat(newLabel, index);
     currentLabel++;
     return newLabel;
 }

// char *generateRegisterName(int flag)
// {
//     char newRegister[MAXREGISTERSIZE] = "R";
//     char index[] = itoa(currentRegister);
//     strcat(newRegister, index);
//     return newRegister;
// }
 Code * generateEmptyCode(char *local){
    Code *code = (Code *)malloc(sizeof(Code));
     code->opCode = NULL;
     code->arg1 = NULL;
     code->arg2 = NULL;
     code->arg3 = NULL;
     code->dest1 = NULL;
     code->dest2 = NULL;
     code->next = NULL;
     code->prev = NULL;
     code->label = NULL;
     code->local = local;
     return code;

    }
 Code *createCode(Operation op, char * local ,char *arg1, char *arg2, char *arg3, char *dest1, char *dest2)
 {

     Code *code = (Code *)malloc(sizeof(Code));
     code->opCode = op;
     code->arg1 = arg1;
     code->arg2 = arg2;
     code->arg3 = arg3;
     code->dest1 = dest1;
     code->dest2 = dest2;
     code->local=local;
     code->next = NULL;
     code->prev = NULL;


     code->label = generateLabelName();
     currentLabel++;

     return code;
 } //CHECK WITH PEDRO IF THIS IS RIGHT?!

Code *joinCodes(Code *code1, Code *code2)
{
    if (code1 == NULL)
        return code2;
    else if (code2 == NULL)
        return code1;

    Code *point = code2;
    while (point->prev)
    {
        point = point->prev;
    }

    code1->next = point;
    point->prev = code1;

    return code2;
}

 Code *generatesAttributionCode(Node *attr, Node *exp)
 {
     SymbolTableEntry *expression = findEntryInTable(getCurrentScope(), exp->data->value.valueString);
     Code *code;
     SymbolTableStack *scope = getCurrentScope();   //CHECK THISSSSSSSS
     if(scope->isGlobal ==1){
        char local[4] = RBSS;
        code = createCode(STOREAI,local,NULL, NULL, NULL, NULL, NULL);
        }
     else{
       char local[4] = RFP;
       code = createCode(STOREAI,local,NULL, NULL, NULL, NULL, NULL);
       }


    return joinCodes(expression->code, code);

 }

 Code *generatesIfCode(Node * expr, Node *trueExpr, Node *falseExpr){
       char* label1 = generateLabelName();
       char* label2 = generateLabelName();
       char* label3 = generateLabelName();

       //TODO:
       //Where are we getting the result of if expressions?
        char* result;
       Code *ifCode = createCBRCode(expr, result, label1, label2, trueExpr);

       Code *trueJump = generateTrueConditionalJump(label1);
       ifCode = joinCodes(ifCode,trueJump);
       Code* labelCode = generateLabelCode(label3);
       if(falseExpr!=NULL){
            SymbolTableEntry *entry = findEntryInTable(getCurrentScope(), falseExpr->data->value.valueString);
            labelCode = joinCodes(entry->code, labelCode);
        }

        free(label1);
        free(label2);
        free(label3);

        return joinCodes(ifCode,labelCode);

        }

Code *generateLabelCode(char * label){
    Code *code = createCode(NOP,NULL, label, NULL, NULL, NULL, NULL);
    return code;
    }
Code *generateTrueConditionalJump(char *l1){
        Code *jumpi = createCode(JUMPI,NULL, NULL, NULL, NULL,l1,NULL);
        return jumpi;
      }

Code *createCBRCode(Node *expr, char* r1, char *l1, char *l2, Node* trueExpr){
    SymbolTableEntry *entry = findEntryInTable(getCurrentScope(), expr->data->value.valueString);
    SymbolTableEntry *entryTrue = findEntryInTable(getCurrentScope(), expr->data->value.valueString);

    Code *cbr = createCode(CBR,NULL, r1, NULL, NULL, l1,l2);
    cbr = joinCodes(entry->code, cbr);
    cbr = joinCodes(cbr,entryTrue->code);
    return cbr;
    }

int setsOffset(char *symbol, int *scope)
{
    //TODO;
    //NOT DONE BECAUSE I DIDNT KNOW HOW TO TEST THE SCOPE AND I'M TOO SLEEPY TO TRY.
    return 0;
}

// Code *generatesBinaryExp(Operation op, Node *child1, Node *child2, char *dest)
// {
//     Code *code = createCode(op, child1->local, child2->local, NULL, dest, NULL);
//     return joinCodes(joinCodes(child1->code, child2->code), code);
// }

// Code *generatesUnaryOperator(Operation operation, Code *op)
// {
//     Code *code = createCode(operation, NULL, NULL, NULL, NULL, NULL, NULL);
//     return joinCodes(code, op);
// }

Operation getOperationFromLabel(char *label)
{
    if (strcmp(label, "+") == 0)
    {
        return ADD;
    }
    else if (strcmp(label, "-") == 0)
    {
        return SUB;
    }
    else if (strcmp(label, "*") == 0)
    {
        return MULT;
    }
    else if (strcmp(label, "/") == 0)
    {
        return DIV;
    }
    else if (strcmp(label, "output") == 0)
    {
        return HALT; // Verify
    }
    else if (strcmp(label, "input") == 0)
    {
        return NOP; // Verify
    }
    else if (strcmp(label, "return") == 0)
    {
        return HALT; // Verify
    }
    else if (strcmp(label, "break") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "continue") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "if") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "else") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "while") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "for") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "?:") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "|") == 0)
    {
        return AND;
    }
    else if (strcmp(label, "<") == 0)
    {
        return CMP_LT;
    }
    else if (strcmp(label, ">") == 0)
    {
        return CMP_GT;
    }
    else if (strcmp(label, "%") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "^") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "!") == 0)
    {
        return NOP;
    }
    else if (strcmp(label, "#") == 0)
    {
        return NOP;
    }
}

Code *generate(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    Code *children[MAX_CHILDREN];
    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        children[i] = generate(node->children[i]);
    }

    Code *next;
    next = generate(node->next);

    Code *finalCode;
    Operation nodeOperation = getOperationFromLabel(node->data->label);

    switch (nodeOperation)
    {
    case ADD:
        printf("Add operation\n");
        finalCode = NULL;
        break;
    case MULT:
        printf("Mult operation\n");
        finalCode = NULL;
        break;
    case SUB:
        printf("Sub operation\n");
        finalCode = NULL;
        break;
    case DIV:
        printf("Div operation\n");
        finalCode = NULL;
        break;
    case HALT:
        printf("Halt operation\n");
        finalCode = NULL;
        break;
    case CMP_LT:
        printf("Less than operation\n");
        finalCode = NULL;
        break;
    case CMP_GT:
        printf("Greater than operation\n");
        finalCode = NULL;
        break;
    case AND:
        printf("And operation\n");
        finalCode = NULL;
        break;
    case OR:
        printf("Or operation\n");
        finalCode = NULL;
        break;
    default:
        printf("Unrecognized operation\n");
    }

    // printf("Node with label %s\n", node->data->label);
    return finalCode;
}
