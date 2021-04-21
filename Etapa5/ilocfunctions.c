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

// char *generateLabelName()
// {

//     char newLabel[MAXLABELSIZE] = "L";
//     char index[] = itoa(currentLabel);
//     strcat(newLabel, index);
//     return newLabel;
// }

// char *generateRegisterName(int flag)
// {
//     char newRegister[MAXREGISTERSIZE] = "R";
//     char index[] = itoa(currentRegister);
//     strcat(newRegister, index);
//     return newRegister;
// }

// Code *createCode(Operation op, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2)
// {

//     Code *code = (Code *)malloc(sizeof(Code));
//     code->opCode = op;
//     code->arg1 = arg1;
//     code->arg2 = arg2;
//     code->arg3 = arg3;
//     code->dest1 = dest1;
//     code->dest2 = dest2;
//     code->dest3 = dest3;
//     code->next = NULL;
//     code->prev = NULL;

//     code->label = generateLabelName();
//     currentLabel++;

//     return code;
// } //CHECK WITH PEDRO IF THIS IS RIGHT?!

Code *joinCodes(Code *code1, Code *code2)
{
    if (code1 == NULL)
        return code2;
    else if (code2 == NULL)
        return code1;

    Code *point = code2;
    while (point->next)
    {
        point = point->next;
    }

    point->next = code1;
}

// Code *generatesAttributionCode(Node *attr, Node *exp)
// {
//     int offset, scope;
//     offset = offset(attr->data->value.valueString, &scope);
//     return createCode(STOREAI, expr->local, NULL, NULL, getsDestForLOADAI(), offset, NULL);
// }

int offset(char *symbol, int *scope)
{
    //TODO;
    //NOT DONE BECAUSE I DIDNT KNOW HOW TO TEST THE SCOPE AND I'M TOO SLEEPY TO TRY.
    return 0;
}

char *getsDestForLOADAI()
{
    //TODO:
    //IF SCOPE IS GLOBAL THEN RETURN RBSS ELSE RFB
    //NOT DONE BECAUSE I DIDNT KNOW HOW TO TEST THE SCOPE AND I'M TOO SLEEPY TO TRY.
}

// Code *generatesInitializationCode(Node *start)
// {
//     if (init == NULL)
//     {
//         return NULL;
//     }
//     Code *code = generatesAttributionCode(start->children[0], start->children[1]);
//     return joinCodes(start->children[1]->code, generatesInitializationCode(start->next));
// }

// Code *generatesBinaryExp(TokenData data, Node *child1, Node *child2, char *dest)
// {
//     Code *code = createCode(-1, getOperationFromData(data), child1->local, child2->local, NULL, dest, NULL);
//     return joinCodes(joinCodes(child1->code, child2->code), code);
// }

Operation getOperationFromData(TokenData data)
{
    //TODO
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
