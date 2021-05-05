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

#define DEBUG 0

int commandCount = 0;

int RBSSOffset = 0;
int RFPOffset = 0;
int RSPOffset = 0;

int currentLabel = 1;
int currentRegister = 0;

NodeList *globalNodeList = NULL;
Code *globalCodeList = NULL;

char *currentFunction;

void updateCurrentFunction(char *function)
{
    currentFunction = strdup(function);
}

char *getCurrentFunction()
{
    return currentFunction;
}

char *generateLabelName()
{
    char temp[32];
    sprintf(temp, "L%d", currentLabel);
    char *newLabel = malloc(strlen(temp) + 1);
    strcpy(newLabel, temp);

    currentLabel++;

    return newLabel;
}

char *generateRegisterName()
{
    char temp[32];
    sprintf(temp, "r%d", currentRegister);
    char *newRegister = malloc(strlen(temp) + 1);
    strcpy(newRegister, temp);

    currentRegister++;

    return newRegister;
}

Code *getFirstCode(Code *code)
{
    Code *aux = code;

    while (aux->prev != NULL)
    {
        aux = aux->prev;
    }

    return aux;
}

int getNumberOfInstructions(Code *code)
{
    Code *currentInstruction = getFirstCode(code);
    int i = 0;

    while (currentInstruction != NULL)
    {
        currentInstruction = currentInstruction->next;
        i++;
    }

    return i;
}

int setOffset(char *symbol, int *scope)
{
    //TODO;
    //NOT DONE BECAUSE I DIDNT KNOW HOW TO TEST THE SCOPE AND I'M TOO SLEEPY TO TRY.
    return 0;
}

Code *createCode(Operation op, char *pointer, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2, char *label)
{
    Code *code = (Code *)malloc(sizeof(Code));
    code->opCode = op;
    code->arg1 = arg1 != NULL ? strdup(arg1) : NULL;
    code->arg2 = arg2 != NULL ? strdup(arg2) : NULL;
    code->arg3 = arg3 != NULL ? strdup(arg3) : NULL;
    code->dest1 = dest1 != NULL ? strdup(dest1) : NULL;
    code->dest2 = dest2 != NULL ? strdup(dest2) : NULL;
    code->pointer = pointer;
    code->next = NULL;
    code->prev = NULL;
    code->res = (dest1 != NULL && dest2 == NULL) ? dest1 : NULL;
    code->label = label != NULL ? label : generateLabelName();

    if (DEBUG == 1)
    {
        commandCount++;
        printf("%d Creating code for operation %s        %s\n", commandCount, generateILOCFromCode(code), getOperationName(op));
    }

    return code;
} //CHECK WITH PEDRO IF THIS IS RIGHT?!

Code *generateEmptyCode(char *pointer)
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
    code->pointer = pointer;

    return code;
}

Code *joinCodes(Code *code1, Code *code2)
{
    if (code1 == NULL)
        return code2;
    else if (code2 == NULL)
        return code1;

    if (DEBUG == 1)
    {
        printf("Joining %s with %s\n", generateILOCFromCode(code1), generateILOCFromCode(code2));
    }

    Code *aux = code1;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    Code *firstOfCode2 = getFirstCode(code2);
    aux->next = firstOfCode2;
    firstOfCode2->prev = aux;

    return getFirstCode(code1);
}

Code *generateLoadVariableCode(Node *variableNode)
{
    SymbolTableEntry *variableEntry = findEntryInStack(getGlobalStack(), variableNode->data->label);
    SymbolTableStack *variableTable = findEntryTable(getGlobalStack(), variableNode->data->label);

    char entryOffsetAsString[16];
    sprintf(entryOffsetAsString, "%d", variableEntry->entryOffset);

    char *destinationRegister = generateRegisterName();

    Code *code = createCode(LOADAI, NULL, variableTable->isGlobal == 1 ? RBSS : RFP, entryOffsetAsString, NULL, destinationRegister, NULL, NULL);

    return code;
}

Code *generateReturnCode(Node *child)
{
    if (DEBUG == 1)
    {
        printf("Return code for child %s with code %s\n", child->data->label, child->code == NULL ? "NULL" : generateILOCFromCode(child->code));
    }

    Code *saveReturnValue = createCode(STOREAI, NULL, child->code->res, NULL, NULL, RFP, "4", NULL);

    if (strcmp(currentFunction, "main") == 0)
    {
        return joinCodes(child->code, joinCodes(saveReturnValue, createCode(JUMPI, NULL, NULL, NULL, NULL, "L0", NULL, NULL)));
    }

    char *returnRegister = generateRegisterName();

    Code *getReturnAddress = createCode(LOADAI, NULL, RFP, "0", NULL, returnRegister, NULL, NULL);
    Code *saveRSP = createCode(LOADAI, NULL, RFP, "12", NULL, RSP, NULL, NULL);
    Code *saveRFP = createCode(LOADAI, NULL, RFP, "8", NULL, RFP, NULL, NULL);
    Code *jump = createCode(JUMP, NULL, NULL, NULL, NULL, returnRegister, NULL, NULL);

    return joinCodes(child->code,
                     joinCodes(saveReturnValue,
                               joinCodes(getReturnAddress,
                                         joinCodes(saveRSP,
                                                   joinCodes(saveRFP, jump)))));
}

Code *generateInitialInstructions(Code *code)
{
    SymbolTableEntry *mainFunctionEntry = findEntryInStack(getGlobalStack(), "main");
    Code *jump = createCode(JUMPI, NULL, NULL, NULL, NULL, (mainFunctionEntry != NULL) ? mainFunctionEntry->ILOCLabel : "L0", NULL, NULL);
    jump->next = createCode(HALT, NULL, NULL, NULL, NULL, NULL, NULL, "L0");
    char numberOfInstructions[16];
    sprintf(numberOfInstructions, "%d", getNumberOfInstructions(code) + 4);
    Code *RBSSDefault = createCode(LOADI, NULL, numberOfInstructions, NULL, NULL, RBSS, NULL, NULL);
    RBSSDefault->next = jump;
    Code *RSPDefault = createCode(LOADI, NULL, "1024", NULL, NULL, RSP, NULL, NULL);
    RSPDefault->next = RBSSDefault;
    Code *RFPDefault = createCode(LOADI, NULL, "1024", NULL, NULL, RFP, NULL, NULL);
    RFPDefault->next = RSPDefault;

    return RFPDefault;
}

Code *generateAttributionCode(TokenData *identifier, Node *exp)
{
    if (DEBUG == 1)
    {
        printf("Generating attribution code for identifier %s and node %s\n", identifier->value.valueString, exp->data->label);
    }
    Code *code;
    SymbolTableStack *scope = findEntryTable(getGlobalStack(), identifier->value.valueString); //CHECK THISSSSSSSS <================
    SymbolTableEntry *entry = findEntryInStack(getGlobalStack(), identifier->value.valueString);

    if (scope->isGlobal == 1)
    {
        if (DEBUG == 1)
        {
            // printf("Scope is global\n");
        }
        char *entryOffsetAsString = malloc(4);
        sprintf(entryOffsetAsString, "%d", entry->entryOffset);
        code = createCode(STOREAI, RBSS, exp->code->res, NULL, NULL, RBSS, entryOffsetAsString, NULL);
    }
    else
    {
        if (DEBUG == 1)
        {
            // printf("Scope is not global\n");
        }
        char *entryOffsetAsString = malloc(4);
        sprintf(entryOffsetAsString, "%d", entry->entryOffset);
        if (DEBUG == 1)
        {
            // printf("Before function call\n");
        }
        code = createCode(STOREAI, RFP, exp->code->res, NULL, NULL, RFP, entryOffsetAsString, NULL);
    }

    return joinCodes(exp->code, code);
}

Code *generateIfCode(Node *expr, Node *trueExpr, Node *falseExpr)
{
    char *label1 = generateLabelName();
    char *label2 = generateLabelName();
    char *label3 = generateLabelName();

    //TODO:
    //Where are we getting the result of if expressions?
    char *reg = expr->code->res;
    Code *ifCode = createCBRCode(expr, reg, label1, label2, label1, trueExpr);

    Code *trueJump = generateTrueConditionalJump(label3);
    Code *labelCode2 = generateLabelCode(label2);
    labelCode2 = joinCodes(trueJump, labelCode2);

    ifCode = joinCodes(ifCode, labelCode2);

    Code *labelCode3 = generateLabelCode(label3);
    if (falseExpr != NULL)
    {
        labelCode3 = joinCodes(falseExpr->code, labelCode3);
        // printf("else code is %s\n", generateILOCFromCode(falseExpr->code));
    }

    return joinCodes(ifCode, labelCode3);
}

Code *generateLabelCode(char *label)
{
    Code *code = createCode(NOP, NULL, NULL, NULL, NULL, NULL, NULL, label);
    return code;
}

Code *generateTrueConditionalJump(char *label)
{
    Code *jumpi = createCode(JUMPI, NULL, NULL, NULL, NULL, label, NULL, NULL);
    return jumpi;
}

Code *generateFunctionCode(Node *header, char *identifier, Node *commands)
{
    SymbolTableEntry *functionEntry = findEntryInStack(getGlobalStack(), identifier);
    char functionEntryOffset[16];
    sprintf(functionEntryOffset, "%d", functionEntry->entryOffset);
    Code *updateRFP = createCode(I2I, NULL, RSP, NULL, NULL, RFP, NULL, functionEntry->ILOCLabel);
    Code *updateRSP = createCode(ADDI, NULL, RSP, functionEntryOffset, NULL, RSP, NULL, NULL);

    if (DEBUG == 1)
    {
        // printf("Final code generated for function %s:\n", identifier);
        // exportCodeList(getFirstCode(updateRFP));
    }

    return joinCodes(updateRFP, joinCodes(updateRSP, commands->code));
}

Code *generateFunctionCallCode(char *functionName, Node *params)
{
    Code *storeRSP = createCode(STOREAI, NULL, RSP, NULL, NULL, RSP, "12", NULL);
    Code *storeRFP = createCode(STOREAI, NULL, RFP, NULL, NULL, RFP, "8", NULL);

    Node *auxParam = params;
    int rspOffset = 16;
    char rspOffsetAsString[16];
    Code *storeFunctionParams = NULL;
    while (auxParam != NULL)
    {
        Code *currentParamCode = auxParam->code;
        sprintf(rspOffsetAsString, "%d", rspOffset);
        storeFunctionParams = joinCodes(storeFunctionParams, joinCodes(currentParamCode, createCode(STOREAI, NULL, currentParamCode->res, NULL, NULL, RSP, rspOffsetAsString, NULL)));
        auxParam = auxParam->next;
        rspOffset += 4;
    }

    SymbolTableEntry *functionEntry = findEntryInStack(getGlobalStack(), functionName);

    char *functionCallRegister = generateRegisterName();
    char *returnPositionRegister = generateRegisterName();

    Code *returnPosition = createCode(ADDI, NULL, RPC, "3", NULL, returnPositionRegister, NULL, NULL);
    Code *storeReturnPosition = createCode(STOREAI, NULL, returnPositionRegister, NULL, NULL, RSP, "0", NULL);
    Code *jumpToFunction = createCode(JUMPI, NULL, NULL, NULL, NULL, functionEntry->ILOCLabel, NULL, NULL);
    Code *loadReturnValue = createCode(LOADAI, NULL, RSP, "4", NULL, functionCallRegister, NULL, NULL);

    storeRSP->res = functionCallRegister;

    return joinCodes(storeRSP,
                     joinCodes(storeRFP,
                               joinCodes(storeFunctionParams,
                                         joinCodes(returnPosition,
                                                   joinCodes(storeReturnPosition,
                                                             joinCodes(jumpToFunction, loadReturnValue))))));
}

Code *generateRegularFunctionCode(Node *header, char *identifier, Code *code, Node *commands, char *labelReturn)
{
    char *register1 = generateRegisterName();
    char *register2 = generateRegisterName();
    char *register3 = generateRegisterName();
    char rfp[4];
    char offsetZero[2];
    char offsetFour[2];
    char offsetEight[2];
    sprintf(rfp, "%s", RFP);
    sprintf(offsetZero, "%s", "0");
    sprintf(offsetFour, "%s", "4");
    sprintf(offsetEight, "%s", "8");

    Code *labelCode = generateLabelCode(labelReturn);
    Code *loadCode1 = createCode(LOADAI, NULL, rfp, offsetZero, NULL, register1, NULL, NULL);
    loadCode1 = joinCodes(labelCode, loadCode1);

    Code *loadCode2 = createCode(LOADAI, NULL, rfp, offsetFour, NULL, register2, NULL, NULL);
    loadCode2 = joinCodes(loadCode1, loadCode2);

    Code *loadCode3 = createCode(LOADAI, NULL, rfp, offsetEight, NULL, register3, NULL, NULL);
    loadCode3 = joinCodes(loadCode2, loadCode3);

    Code *i2iCode = generateI2ICode(register2, rfp);
    i2iCode = joinCodes(loadCode3, i2iCode);

    Code *i2iCode2 = generateI2ICode(register3, rfp);
    i2iCode2 = joinCodes(i2iCode, i2iCode2);

    Code *jump = generateJump(register1);
    jump = joinCodes(i2iCode2, jump);

    Code *body;
    if (commands != NULL)
    {
        body = joinCodes(commands->code, jump);
    }
    else
    {
        body = joinCodes(NULL, jump);
    }
    Code *function = joinCodes(header->code, body);

    return joinCodes(code, function);
}

Code *generateMainFunctionCode(Node *header, char *identifier, Code *code, Node *commands, char *labelReturn)
{
    Code *jumpICode = generateTrueConditionalJump(identifier);
    Code *ending = code;
    Code *haltCode = generateHaltCommand();
    Code *body;

    while (ending->prev)
    {
        ending = ending->prev;
    }
    jumpICode->next = ending->next;
    jumpICode->prev = ending;

    if (ending->next != NULL)
    {
        ending->next->prev = jumpICode;
    }
    else
    {
        code = jumpICode;
    }

    ending->next = jumpICode;

    if (commands != NULL)
    {
        body = joinCodes(commands->code, haltCode);
    }
    else
    {
        body = joinCodes(NULL, haltCode);
    }

    Code *function = joinCodes(header->code, body);
    return joinCodes(code, function);
}

Code *generateJump(char *reg)
{
    return createCode(JUMP, NULL, NULL, NULL, NULL, reg, NULL, NULL);
}

Code *generateHaltCommand()
{

    Code *code = createCode(HALT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    return code;
}

Code *generateI2ICode(char *r1, char *r2)
{
    Code *code = createCode(I2I, NULL, r1, NULL, NULL, r2, NULL, NULL);
}

Code *generateTernaryCode(Node *expr, Node *exprTrue, Node *exprFalse)
{

    char *label1 = generateLabelName();
    char *label2 = generateLabelName();
    char *label3 = generateLabelName();
    char *reg1 = generateRegisterName();

    char *result = expr->code->res; // <===this has to be changed
    Code *cbr = createCode(CBR, NULL, result, NULL, NULL, label1, label2, NULL);
    Code *labelCode1 = generateLabelCode(label1);
    labelCode1 = joinCodes(cbr, labelCode1);
    labelCode1 = joinCodes(expr->code, labelCode1);
    labelCode1 = joinCodes(labelCode1, exprTrue->code);

    char *resultTrue = exprTrue->code->res; // <===this has to be changed
    Code *i2iCode = generateI2ICode(resultTrue, reg1);

    Code *jumpCode = generateTrueConditionalJump(label3);
    jumpCode = joinCodes(i2iCode, jumpCode);
    Code *labelCode2 = generateLabelCode(label2);
    labelCode2 = joinCodes(jumpCode, labelCode2);

    labelCode1 = joinCodes(labelCode1, labelCode2);
    labelCode1 = joinCodes(labelCode1, exprFalse->code);

    char *resultFalse = exprFalse->code->res; // <===this has to be changed
    Code *i2iCode2 = generateI2ICode(resultFalse, reg1);

    Code *labelCode3 = generateLabelCode(label3);
    labelCode3 = joinCodes(i2iCode, labelCode3);
    labelCode1 = joinCodes(labelCode1, labelCode3);

    labelCode1->res = reg1;
    return labelCode1;
}

Code *createCBRCode(Node *expr, char *r1, char *l1, char *l2, char *followingLabel, Node *trueExpr)
{

    Code *cbr = createCode(CBR, NULL, r1, NULL, NULL, l1, l2, NULL);
    if (followingLabel != NULL)
    {
        Code *labelCode1 = generateLabelCode(followingLabel);
        labelCode1 = joinCodes(cbr, labelCode1);
        labelCode1 = joinCodes(expr->code, labelCode1);
        labelCode1 = joinCodes(labelCode1, trueExpr->code);
        return labelCode1;
    }

    cbr = joinCodes(expr->code, cbr);
    cbr = joinCodes(cbr, trueExpr->code);
    return cbr;
}

Code *generateWhileCode(Node *expr, Node *commands)
{
    char *label1 = generateLabelName();
    char *label2 = generateLabelName();
    char *label3 = generateLabelName();

    if (DEBUG == 1)
    {
        printf("generating while code with expression %s and commands staring with %s\n", expr->data->label, commands->data->label);
    }

    //TODO:
    //Where are we getting the result of if expressions?

    Code *labelCode = generateLabelCode(label1);
    labelCode = joinCodes(labelCode, expr->code);

    char *reg = expr->code->res;
    Code *exprCode = createCode(CBR, NULL, reg, NULL, NULL, label2, label3, NULL);
    exprCode = joinCodes(labelCode, exprCode);

    Code *labelCode2 = generateLabelCode(label2);
    labelCode2 = joinCodes(exprCode, labelCode2);
    labelCode2 = joinCodes(labelCode2, commands->code);

    Code *jumpCode = generateTrueConditionalJump(label1);
    jumpCode = joinCodes(labelCode2, jumpCode);

    Code *labelCode3 = generateLabelCode(label3);
    labelCode3 = joinCodes(jumpCode, labelCode3);

    // printf("Adding to global code list\n");

    // addToGlobalCodeList(labelCode3);

    // exportCodeList(getGlobalCodeList());

    return labelCode3;
}

Code *generateForCode(Node *start, Node *expr, Node *incr, Node *commands)
{

    char *label1 = generateLabelName();
    char *label2 = generateLabelName();
    char *label3 = generateLabelName();

    Code *labelCode = generateLabelCode(label1);
    start->code = joinCodes(start->code, labelCode);
    start->code = joinCodes(start->code, expr->code);

    //TODO:
    //Where are we getting the result of if expressions?
    char *reg = expr->code->res;
    Code *conditionCode = createCode(CBR, NULL, reg, NULL, NULL, label2, label3, NULL);
    start->code = joinCodes(start->code, conditionCode);

    Code *labelCode2 = generateLabelCode(label2);
    start->code = joinCodes(start->code, labelCode2);
    start->code = joinCodes(start->code, commands->code);
    start->code = joinCodes(start->code, incr->code);

    Code *jumpCode = generateTrueConditionalJump(label1);
    start->code = joinCodes(start->code, jumpCode);

    Code *labelCode3 = generateLabelCode(label3);
    start->code = joinCodes(start->code, labelCode3);
    return start->code;
}

Code *generateLocalVarCode(Node *identifier, Node *init, int initialized)
{
    if (DEBUG == 1)
    {
        printf("Generating local var code for %s\n", identifier->data->label);
    }
    Code *updatesRSP = createCode(ADDI, NULL, RSP, "4", NULL, RSP, NULL, NULL);

    if (initialized == 1)
    {
        SymbolTableEntry *identifierEntry = findEntryInStack(getGlobalStack(), identifier->data->value.valueString);

        char identifierOffset[16];
        sprintf(identifierOffset, "%d", identifierEntry->entryOffset);
        Code *attribution = createCode(STOREAI, RFP, init->code->res, NULL, NULL, RFP, identifierOffset, NULL);
        updatesRSP = joinCodes(updatesRSP, joinCodes(init->code, attribution));
    }

    return updatesRSP;
}

Code *generateBinaryExpression(char *binaryOperator, Node *parent, Node *child1, Node *child2)
{
    char *reg1 = child1->code->res;
    char *reg2 = child2->code->res;
    char *result = generateRegisterName();
    Operation operation = getOperation(binaryOperator);

    if (DEBUG == 1)
    {
        printf("Generating binary expression for operator %s and nodes %s and %s\n", binaryOperator, child1->code->res, child2->code->res);
    }

    char test[20] = " This should be it";
    //Code *code = createCode(operation, NULL, strcat(reg1, test), reg2, NULL, result, NULL, NULL);
    Code *code = createCode(operation, NULL, reg1, reg2, NULL, result, NULL, NULL);

    if (operation != AND && operation != OR)
    {
        parent->code = joinCodes(child1->code, child2->code);
        parent->code = joinCodes(parent->code, code);

        //Code *joined = joinCodes(child1->code, joinCodes(child2->code, code));

        if (DEBUG == 1)
        {
            printf("Code generated for binary expression %s: \n", binaryOperator);
            // exportCodeList(joined);
            printf("\n\n");
        }

        // return joined;
    }
    else if (operation == AND)
    {
        char *jumpLabel = generateLabelName();
        char *dontJumpLabel = generateLabelName();

        Code *i2iCode = createCode(I2I, NULL, reg1, NULL, NULL, result, NULL, NULL);
        Code *cbrCode = createCode(CBR, NULL, result, NULL, NULL, dontJumpLabel, jumpLabel, NULL);
        Code *labelDontJumpCode = generateLabelCode(dontJumpLabel);
        Code *labelJumpCode = generateLabelCode(jumpLabel);

        i2iCode = joinCodes(i2iCode, cbrCode);
        i2iCode = joinCodes(i2iCode, labelDontJumpCode);

        parent->code = joinCodes(child1->code, i2iCode);
        parent->code = joinCodes(parent->code, child2->code);
        parent->code = joinCodes(parent->code, code);
        parent->code = joinCodes(parent->code, labelJumpCode);

        //       Code *labelDontJumpCode = generateLabelCode(dontJumpLabel);

        //        labelDontJumpCode = joinCodes(cbrCode, labelDontJumpCode);
        //
        //        Code *labelJump = generateLabelCode(jumpLabel);
        //
        //        parent->code = joinCodes(child1->code, labelDontJumpCode);
        //
        //        if (DEBUG == 1)
        //        {
        //            printf("Code generated for binary expression %s: \n", binaryOperator);
        //            exportCodeList(parent->code);
        //            printf("\n\n");
        //        }
        //

        //            return joinCodes(child1->code, joinCodes(child2->code, code));
    }
    else if (operation == OR)
    {
        Code *i2iCode = createCode(I2I, NULL, reg1, NULL, NULL, result, NULL, NULL);
        char *jumpLabel = generateLabelName();
        char *dontJumpLabel = generateLabelName();
        Code *cbrCode = createCode(CBR, NULL, result, NULL, NULL, jumpLabel, dontJumpLabel, NULL);
        cbrCode = joinCodes(i2iCode, cbrCode);

        Code *dontJumpLabelCode = generateLabelCode(dontJumpLabel);
        dontJumpLabelCode = joinCodes(cbrCode, dontJumpLabelCode);
        Code *jumpLabelCode = generateLabelCode(jumpLabel);

        parent->code = joinCodes(child1->code, dontJumpLabelCode);
        parent->code = joinCodes(parent->code, child2->code);
        parent->code = joinCodes(parent->code, code);
        parent->code = joinCodes(parent->code, jumpLabelCode);

        if (DEBUG == 1)
        {
            printf("Code generated for binary expression %s: \n", binaryOperator);
            exportCodeList(parent->code);
            printf("\n\n");
        }
    }
    parent->code->res = result;
    return parent->code;
}

Code *generateUnaryExpression(Operation operation, Code *operand)
{
    Code *code = createCode(operation, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    return joinCodes(code, operand);
}

char *getOperationName(Operation operation)
{
    switch (operation)
    {
    case NOP:
        return "nop";
        break;
    case HALT:
        return "halt";
        break;
    case ADD:
        return "add";
        break;
    case SUB:
        return "sub";
        break;
    case MULT:
        return "mult";
        break;
    case DIV:
        return "div";
        break;
    case ADDI:
        return "addI";
        break;
    case SUBI:
        return "subI";
        break;
    case RSUBI:
        return "rsubI";
        break;
    case MULTI:
        return "multI";
        break;
    case DIVI:
        return "divI";
        break;
    case AND:
        return "and";
        break;
    case ANDI:
        return "andI";
        break;
    case OR:
        return "or";
        break;
    case ORI:
        return "orI";
        break;
    case LOAD:
        return "load";
        break;
    case LOADI:
        return "loadI";
        break;
    case LOADAI:
        return "loadAI";
        break;
    case LOAD0:
        return "loadA0";
        break;
    case CLOAD:
        return "cload";
        break;
    case CLOADAI:
        return "cloadAI";
        break;
    case CLOADA0:
        return "cloadA0";
        break;
    case STORE:
        return "store";
        break;
    case STOREAI:
        return "storeAI";
        break;
    case STOREA0:
        return "storeA0";
        break;
    case CSTORE:
        return "cstore";
        break;
    case CSTOREAI:
        return "cstoreAI";
        break;
    case CSTOREA0:
        return "cstoreA0";
        break;
    case I2I:
        return "i2i";
        break;
    case C2C:
        return "c2c";
        break;
    case C2I:
        return "c2i";
        break;
    case I2C:
        return "i2c";
        break;
    case JUMPI:
        return "jumpI";
        break;
    case JUMP:
        return "jump";
        break;
    case CBR:
        return "cbr";
        break;
    case CMP_LT:
        return "cmp_LT";
        break;
    case CMP_LE:
        return "cmp_LE";
        break;
    case CMP_EQ:
        return "cmp_EQ";
        break;
    case CMP_GE:
        return "cmp_GE";
        break;
    case CMP_GT:
        return "cmp_GT";
        break;
    case CMP_NE:
        return "cmp_NE";
        break;
    default:
        return "";
        break;
    }
}

char *generateILOCFromCode(Code *code)
{

    if (code == NULL)
    {
        return NULL;
    }
    char tempInstructionLine[128];
    char arg1[16] = "", arg2[16] = "", dest1[16] = "", dest2[16] = "", label[16] = "";
    if (code->opCode == NOP && code->label != NULL)
    {
        sprintf(label, "%s: ", code->label);
        sprintf(tempInstructionLine, "%s", label);
    }
    else
    {
        if (code->arg1 != NULL)
        {
            sprintf(arg1, "%s", code->arg1);
        }
        if (code->arg2 != NULL)
        {
            sprintf(arg2, ", %s", code->arg2);
        }
        if (code->dest1 != NULL)
        {
            sprintf(dest1, "%s", code->dest1);
        }
        if (code->dest2 != NULL)
        {
            sprintf(dest2, ", %s", code->dest2);
        }
        if (code->label != NULL)
        {
            sprintf(label, "%s: ", code->label);
        }

        sprintf(tempInstructionLine, "%s%s %s%s => %s%s", label, getOperationName(code->opCode), arg1, arg2, dest1, dest2);
    }

    char *instructionLine = malloc(strlen(tempInstructionLine) + 1);
    strcpy(instructionLine, tempInstructionLine);

    return instructionLine;
}

NodeList *addToGlobalNodeList(Node *node)
{
    NodeList *nodeList = createNodeList(node);

    if (globalNodeList == NULL)
    {
        globalNodeList = nodeList;
    }
    else
    {
        NodeList *aux = globalNodeList;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = nodeList;
    }

    return globalNodeList;
}

Code *addToGlobalCodeList(Code *code)
{
    if (globalCodeList == NULL)
    {
        globalCodeList = code;
    }
    else
    {
        Code *aux = globalCodeList;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = code;
    }

    return globalCodeList;
}

NodeList *getGlobalNodeList()
{
    return globalNodeList;
}

Code *getGlobalCodeList()
{
    return globalCodeList;
}

NodeList *createNodeList(Node *node)
{
    NodeList *newNodeList = (NodeList *)malloc(sizeof(NodeList));
    newNodeList->node = node;
    newNodeList->next = NULL;
    newNodeList->previous = NULL;

    return newNodeList;
}

void exportCodeFromNodeList(NodeList *nodeListElem)
{
    if (nodeListElem != NULL)
    {
        Code *aux = nodeListElem->node->code;
        printf("Code for node %s:\n", nodeListElem->node->data->label);
        while (aux != NULL)
        {
            printf("%s\n", generateILOCFromCode(aux));
            aux = aux->next;
        }
        exportCodeFromNodeList(nodeListElem->next);
    }
}

void exportCodeList(Code *code)
{
    if (code != NULL)
    {
        printf("%s\n", generateILOCFromCode(code));
        exportCodeList(code->next);
    }
}

void handleRootCodeExport(Node *root)
{
    Code *code = getFirstCode(root->code);
    exportCodeList(addCodeToNode(root, getFirstCode(joinCodes(generateInitialInstructions(code), code)))->code);
}
