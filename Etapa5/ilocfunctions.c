// TODO:
// Functions signed with the TO DO sign;
// Treatment of new variable Local in Node object

// WE MUST HAVE A REGISTER IN EACH NODE OR TABLE ENTRY SPECIFYING THE LOCAL OF THE CODE, NOT THE SAME
// AS THE : LOCAL : VAR WE ARE USING TO DELIMIT THE DATA AREA
//FIND OUT WHERE THIS REGISTER SHOULD BE GENERATED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ilocfunctions.h"

int currentLabel = 1;
int currentRegister = 0;

char *generateLabelName()
{
    char *newLabel;
    sprintf(newLabel, "L%d", currentLabel);

    currentLabel++;

    return newLabel;
}

char *generateRegisterName()
{
    char *newRegister;
    sprintf(newRegister, "r%d", currentRegister);

    currentRegister++;

    return newRegister;
}

Code *generateEmptyCode(char *local)
{
    Code *code = (Code *)malloc(sizeof(Code));
    code->opCode = NOP;
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

Code *createCode(Operation op, char *local, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2)
{
    Code *code = (Code *)malloc(sizeof(Code));
    code->opCode = op;
    code->arg1 = arg1;
    code->arg2 = arg2;
    code->arg3 = arg3;
    code->dest1 = dest1;
    code->dest2 = dest2;
    code->local = local;
    code->next = NULL;
    code->prev = NULL;
    code->res = NULL;

    code->label = generateLabelName();

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

// Code *generateInitialInstructions()
// {
//     Code *jump = createCode(JUMPI, NULL, NULL, NULL, NULL, findEntryInStack(getGlobalStack(), "main"), NULL);
//     jump->next = createCode(HALT, "L0", NULL, NULL, NULL, NULL, NULL);
//     Code *RBSSDefault = createCode(LOADI, NULL, getNumberOfInstructions(), NULL, NULL, RBSS, NULL);
//     RBSSDefault->next = jump;
//     Code *RFPDefault = createCode(LOADI, NULL, "1024", NULL, NULL, RFP, NULL);
//     RFPDefault->next = RBSSDefault;
//     return RFPDefault;
// }

Code *generatesAttributionCode(Node *attr, Node *exp)
{
    SymbolTableEntry *expression = findEntryInTable(getCurrentScope(), exp->data->value.valueString);
    Code *code;
    SymbolTableStack *scope = getGlobalStack(); //CHECK THISSSSSSSS
    if (scope->isGlobal == 1)
    {
        char local[4] = RBSS;
        code = createCode(STOREAI, local, NULL, NULL, NULL, NULL, NULL);
    }
    else
    {
        char local[4] = RFP;
        code = createCode(STOREAI, local, NULL, NULL, NULL, NULL, NULL);
    }

    return joinCodes(expression->code, code);
}

Code *generatesIfCode(Node *expr, Node *trueExpr, Node *falseExpr)
{
    char *label1 = generateLabelName();
    char *label2 = generateLabelName();
    char *label3 = generateLabelName();
    SymbolTableEntry *exprEntry = findEntryInStack(getGlobalStack(), expr->data->value.valueString);

    //TODO:
    //Where are we getting the result of if expressions?
    char *reg = exprEntry->code->res;
    Code *ifCode = createCBRCode(expr, reg, label1, label2, trueExpr);

    Code *trueJump = generateTrueConditionalJump(label1);
    ifCode = joinCodes(ifCode, trueJump);
    Code *labelCode = generateLabelCode(label3);
    if (falseExpr != NULL)
    {
        SymbolTableEntry *entry = findEntryInStack(getGlobalStack(), falseExpr->data->value.valueString);
        labelCode = joinCodes(entry->code, labelCode);
    }

    return joinCodes(ifCode, labelCode);
}

Code *generateLabelCode(char *label)
{
    Code *code = createCode(NOP, NULL, label, NULL, NULL, NULL, NULL);
    return code;
}

Code *generateTrueConditionalJump(char *label)
{
    Code *jumpi = createCode(JUMPI, NULL, NULL, NULL, NULL, label, NULL);
    return jumpi;
}

Code *createCBRCode(Node *expr, char *r1, char *l1, char *l2, Node *trueExpr)
{
    SymbolTableEntry *entry = findEntryInStack(getGlobalStack(), expr->data->value.valueString);
    SymbolTableEntry *entryTrue = findEntryInStack(getGlobalStack(), expr->data->value.valueString);

    Code *cbr = createCode(CBR, NULL, r1, NULL, NULL, l1, l2);
    cbr = joinCodes(entry->code, cbr);
    cbr = joinCodes(cbr, entryTrue->code);
    return cbr;
}

Code *generateI2ICode(char *r1, char *r2)
{
    Code *code = createCode(I2I, NULL, r1, NULL, NULL, r2, NULL);
}

Code *generateTernaryOpCode(Node *expr, Node *exprTrue, Node *exprFalse)
{

    SymbolTableEntry *entryFalse = findEntryInStack(getGlobalStack(), exprFalse->data->value.valueString);
    SymbolTableEntry *entryTrue = findEntryInStack(getGlobalStack(), exprTrue->data->value.valueString);
    SymbolTableEntry *entryExpr = findEntryInStack(getGlobalStack(), expr->data->value.valueString);
    char *label1 = generateLabelName();
    char *label2 = generateLabelName();
    char *label3 = generateLabelName();
    char *reg1 = generateRegisterName();

    char *result = entryExpr->code->res; // <===this has to be changed
    Code *cbr = createCBRCode(expr, result, label1, label2, exprTrue);

    char *resultTrue = entryTrue->code->res; // <===this has to be changed
    Code *i2iCode = generateI2ICode(resultTrue, reg1);

    Code *jumpCode = generateTrueConditionalJump(label3);
    jumpCode = joinCodes(i2iCode, jumpCode);

    cbr = joinCodes(cbr, jumpCode);
    cbr = joinCodes(cbr, entryFalse->code);

    char *resultFalse = entryFalse->code->res; // <===this has to be changed
    Code *i2iCode2 = generateI2ICode(resultFalse, reg1);

    Code *labelCode = generateLabelCode(label3);
    labelCode = joinCodes(i2iCode, labelCode);
    cbr = joinCodes(cbr, labelCode);

    cbr->res = reg1;
    return cbr;
}

Code *generateWhileCode(Node *expr, Node *commands)
{

    SymbolTableEntry *entry = findEntryInStack(getGlobalStack(), expr->data->value.valueString);
    SymbolTableEntry *entryCommands = findEntryInStack(getGlobalStack(), commands->data->value.valueString);
    char *label1 = generateLabelName();
    char *label2 = generateLabelName();
    char *label3 = generateLabelName();

    // Code *labelCode = generateLabelCode(label1);
    // labelCode = joinCodes(labelCode, entry->code);

    //TODO:
    //Where are we getting the result of if expressions?
    char *reg = entry->code->res;
    Code *exprCode = createCBRCode(expr, reg, label2, label3, commands);

    Code *labelCode = generateLabelCode(label1);
    labelCode = joinCodes(labelCode, entry->code);

    Code *labelCode2 = generateLabelCode(label2);
    labelCode2 = joinCodes(exprCode, labelCode2);
    labelCode2 = joinCodes(labelCode2, entryCommands->code);

    Code *jumpCode = generateTrueConditionalJump(label1);
    jumpCode = joinCodes(labelCode2, jumpCode);

    Code *labelCode3 = generateLabelCode(label3);
    labelCode3 = joinCodes(jumpCode, labelCode3);

    return labelCode3;
}

// Code *generateForCode(Node *start, Node *expr, Node *incr, Node *commands)
// {
//     char *label1 = generateLabelName();
//     char *label2 = generateLabelName();
//     char *label3 = generateLabelName();

//     SymbolTableEntry *startEntry = findEntryInStack(getGlobalStack(), start->data->value.valueString);
//     SymbolTableEntry *exprEntry = findEntryInStack(getGlobalStack(), expr->data->value.valueString);
//     SymbolTableEntry *commandsEntry = findEntryInStack(getGlobalStack(), commands->data->value.valueString);
//     SymbolTableEntry *incrEntry = findEntryInStack(getGlobalStack(), incr->data->value.valueString);

//     Code *labelCode = generateLabelCode(label1);
//     labelCode = joinCodes(startEntry->code, labelCode);
//     labelCode = joinCodes(labelCode, exprEntry->code);

//     //TODO:
//     //Where are we getting the result of if expressions?
//     char *reg = exprEntry->code->res;
//     Code *conditionCode = createCBRCode(expr, reg, label2, label3);
//     conditionCode = joinCodes(labelCode, conditionCode);

//     Code *labelCode2 = generateLabelCode(label2);
//     labelCode = joinCodes(conditionCode, labelCode2);
//     labelCode = joinCodes(labelCode2, commandsEntry->code);
//     labelCode = joinCodes(labelCode2, incrEntry->code);

//     Code *jumpCode = generateTrueConditionalJump(label1);
//     labelCode = joinCodes(labelCode2, jumpCode);

//     Code *labelCode3 = generateLabelCode(label3);
//     labelCode3 = joinCodes(jumpCode, labelCode3);
//     return labelCode3;
// }
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

OperationType getOperationFromTokenData(TokenData *data)
{
    if (strcmp(data->label, "+") == 0)
    {
        return OPERATION_TYPE_ADD;
    }
    else if (strcmp(data->label, "-") == 0)
    {
        return OPERATION_TYPE_SUB;
    }
    else if (strcmp(data->label, "*") == 0)
    {
        return OPERATION_TYPE_MULT;
    }
    else if (strcmp(data->label, "/") == 0)
    {
        return OPERATION_TYPE_DIV;
    }
    else if (strcmp(data->label, "output") == 0)
    {
        return OPERATION_TYPE_NOP; // Verify
    }
    else if (strcmp(data->label, "input") == 0)
    {
        return OPERATION_TYPE_NOP; // Verify
    }
    else if (strcmp(data->label, "return") == 0)
    {
        return OPERATION_TYPE_RETURN; // Verify
    }
    else if (strcmp(data->label, "break") == 0)
    {
        return OPERATION_TYPE_NOP;
    }
    else if (strcmp(data->label, "continue") == 0)
    {
        return OPERATION_TYPE_NOP;
    }
    else if (strcmp(data->label, "if") == 0)
    {
        return OPERATION_TYPE_IF_ELSE;
    }
    else if (strcmp(data->label, "else") == 0)
    {
        return OPERATION_TYPE_IF_ELSE;
    }
    else if (strcmp(data->label, "while") == 0)
    {
        return OPERATION_TYPE_WHILE;
    }
    else if (strcmp(data->label, "for") == 0)
    {
        return OPERATION_TYPE_FOR;
    }
    else if (strcmp(data->label, "?:") == 0)
    {
        return OPERATION_TYPE_TERNARY;
    }
    else if (strcmp(data->label, "||") == 0)
    {
        return OPERATION_TYPE_OR;
    }
    else if (strcmp(data->label, "<") == 0)
    {
        return OPERATION_TYPE_LESS_THAN;
    }
    else if (strcmp(data->label, ">") == 0)
    {
        return OPERATION_TYPE_GREATER_THAN;
    }
    else if (strcmp(data->label, "%") == 0)
    {
        return OPERATION_TYPE_NOP;
    }
    else if (strcmp(data->label, "^") == 0)
    {
        return OPERATION_TYPE_NOP;
    }
    else if (strcmp(data->label, "!") == 0)
    {
        return OPERATION_TYPE_NOT;
    }
    else
    {
        return OPERATION_TYPE_NOP;
    }
}

char *generate(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    char *children[MAX_CHILDREN];
    for (int i = 0; i < node->numberOfChildren; i++)
    {
        children[i] = generate(node->children[i]);
    }

    char *next;
    next = generate(node->next);

    // Code *finalCode;
    OperationType nodeOperation = getOperationFromTokenData(node->data);

    SymbolTableEntry *nodeEntry = findEntryInStack(getGlobalStack(), node->data->label);

    // if (nodeEntry == NULL)
    // {
    //     printf("Entry %s not found\n", node->data->label);
    //     nodeEntry = findLiteralEntryInStack(getGlobalStack(), node->data->label);

    //     if (nodeEntry == NULL)
    //     {
    //         printf("Entry %s STILL not found\n", node->data->label);
    //     }
    // }

    printf("Generating code for %s::%s::%s\n", node->data->label, getTypeName(node->type), "sal");

    printTable(getGlobalStack()->top);

    // for (int i = 0; i < node->numberOfChildren; i++)
    // {
    //     printf("%d: %s\n", i, children[i]);
    // }

    // switch (nodeOperation)
    // {
    // case OPERATION_TYPE_ADD:
    //     printf("OPERATION_TYPE_ADD\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_SUB:
    //     printf("OPERATION_TYPE_SUB\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_MULT:
    //     printf("OPERATION_TYPE_MULT\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_DIV:
    //     printf("OPERATION_TYPE_DIV\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_LESS_THAN:
    //     printf("OPERATION_TYPE_LESS_THAN\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_GREATER_THAN:
    //     printf("OPERATION_TYPE_GREATER_THAN\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_LESS_EQUAL:
    //     printf("OPERATION_TYPE_LESS_EQUAL\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_GREATER_EQUAL:
    //     printf("OPERATION_TYPE_GREATER_EQUAL\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_VAR_ACCESS:
    //     printf("OPERATION_TYPE_VAR_ACCESS\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_VECTOR_ACCESS:
    //     printf("OPERATION_TYPE_VECTOR_ACCESS\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_FUNCTION_DECLARATION:
    //     printf("OPERATION_TYPE_FUNCTION_DECLARATION\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_FUNCTION_CALL:
    //     printf("OPERATION_TYPE_FUNCTION_CALL\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_OR:
    //     printf("OPERATION_TYPE_OR\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_AND:
    //     printf("OPERATION_TYPE_AND\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_NOT:
    //     printf("OPERATION_TYPE_NOT\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_NEGATIVE:
    //     printf("OPERATION_TYPE_NEGATIVE\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_ATTRIBUTION:
    //     printf("OPERATION_TYPE_ATTRIBUTION\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_ATTRIBUTION_VECTOR:
    //     printf("OPERATION_TYPE_ATTRIBUTION_VECTOR\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_RETURN:
    //     printf("OPERATION_TYPE_RETURN\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_IF:
    //     printf("OPERATION_TYPE_IF\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_IF_ELSE:
    //     printf("OPERATION_TYPE_IF_ELSE\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_TERNARY:
    //     printf("OPERATION_TYPE_TERNARY\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_WHILE:
    //     printf("OPERATION_TYPE_WHILE\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_FOR:
    //     printf("OPERATION_TYPE_FOR\n");
    //     finalCode = NULL;
    //     break;
    // case OPERATION_TYPE_NOP:
    //     printf("OPERATION_TYPE_NOP\n");
    //     finalCode = NULL;
    //     break;
    // default:
    //     printf("Unrecognized operation\n");
    //     finalCode = NULL;
    //     break;
    // }

    return node->data->label;
}
