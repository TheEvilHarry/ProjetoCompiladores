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

#define DEBUG 1

int RBSSOffset = 0;
int RFPOffset = 0;
int RSPOffset = 0;

int currentLabel = 1;
int currentRegister = 0;

NodeList *globalNodeList = NULL;
Code *globalCodeList = NULL;

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

int setOffset(char *symbol, int *scope)
{
    //TODO;
    //NOT DONE BECAUSE I DIDNT KNOW HOW TO TEST THE SCOPE AND I'M TOO SLEEPY TO TRY.
    return 0;
}

Code *createCode(Operation op, char *pointer, char *arg1, char *arg2, char *arg3, char *dest1, char *dest2, char *label)
{
    if (DEBUG == 1)
    {
        printf("Creating code for operation %s: %s %s => %s %s\n", getOperationName(op), arg1, arg2, dest1, dest2);
    }

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

    if (label != NULL)
    {
        code->label = label;
    }
    else if (label == NULL)
    {
        code->label = generateLabelName();
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

    Code *point = code2;
    while (point->prev)
    {
        point = point->prev;
    }

    code1->next = point;
    point->prev = code1;

    return code2;
}

Code *generateReturnCode(Node *child, Node *parent, char *label)
{

    char *rfp = malloc(4);
    char *offset = malloc(4);
    sprintf(rfp, "%s", RFP);
    sprintf(rfp, "%s", offset);
    Code *returnCode = createCode(STOREAI, rfp, child->code->res, NULL, NULL, rfp, offset, NULL);
    Code *jumpCode = generateTrueConditionalJump(label);
    jumpCode = joinCodes(returnCode, jumpCode);
    parent->code = joinCodes(child->code, jumpCode);
    return parent->code;
}

Code *generateInitialInstructions()
{
    // Code *jump = createCode(JUMPI, NULL, NULL, NULL, NULL, findEntryInStack(getGlobalStack(), "main"), NULL);
    // jump->next = createCode(HALT, "L0", NULL, NULL, NULL, NULL, NULL);
    // Code *RBSSDefault = createCode(LOADI, NULL, getNumberOfInstructions(), NULL, NULL, RBSS, NULL);
    // RBSSDefault->next = jump;
    // Code *RFPDefault = createCode(LOADI, NULL, "1024", NULL, NULL, RFP, NULL);
    // RFPDefault->next = RBSSDefault;
    // return RFPDefault;
}

Code *generateAttributionCode(TokenData *identifier, Node *exp)
{
    if (DEBUG == 1)
    {
        printf("Generating attribution code for identifier %s and node %s\n", identifier->value.valueString, exp->data->label);
    }
    Code *code;
    SymbolTableStack *scope = getGlobalStack(); //CHECK THISSSSSSSS <================
    SymbolTableEntry *entry = findEntryInStack(getGlobalStack(), identifier->value.valueString);

    if (scope->isGlobal == 1)
    {
        if (DEBUG == 1)
        {
            // printf("Scope is global\n");
        }
        char pointer[4] = RBSS;
        char *entryOffsetAsString = malloc(4);
        sprintf(entryOffsetAsString, "%d", entry->entryOffset);
        code = createCode(STOREAI, pointer, exp->code->res, NULL, NULL, pointer, entryOffsetAsString, NULL);
    }
    else
    {
        if (DEBUG == 1)
        {
            // printf("Scope is not global\n");
        }
        char pointer[4] = RFP;
        char *entryOffsetAsString = malloc(4);
        sprintf(entryOffsetAsString, "%d", entry->entryOffset);
        if (DEBUG == 1)
        {
            // printf("Before function call\n");
        }
        code = createCode(STOREAI, pointer, exp->code->res, NULL, NULL, pointer, entryOffsetAsString, NULL);
    }

    addToGlobalCodeList(code);

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

//identifier = the label of the header's node

Code *generateFunctionCode(Node *header, char *identifier, Code *code, Node *commands, char *labelReturn)
{

    if (strcmp(identifier, "main") == 0)
    {
        return generateMainFunctionCode(header, identifier, code, commands, labelReturn);
    }
    return generateRegularFunctionCode(header, identifier, code, commands, labelReturn);
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
    Code *cbr = createCBRCode(expr, result, label1, label2, label1, exprTrue);

    char *resultTrue = exprTrue->code->res; // <===this has to be changed
    Code *i2iCode = generateI2ICode(resultTrue, reg1);

    Code *jumpCode = generateTrueConditionalJump(label3);
    jumpCode = joinCodes(i2iCode, jumpCode);
    Code *labelCode2 = generateLabelCode(label2);
    labelCode2 = joinCodes(jumpCode, labelCode2);

    cbr = joinCodes(cbr, labelCode2);
    cbr = joinCodes(cbr, exprFalse->code);

    char *resultFalse = exprFalse->code->res; // <===this has to be changed
    Code *i2iCode2 = generateI2ICode(resultFalse, reg1);

    Code *labelCode3 = generateLabelCode(label3);
    labelCode3 = joinCodes(i2iCode, labelCode3);
    cbr = joinCodes(cbr, labelCode3);

    cbr->res = reg1;
    return cbr;
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

    //TODO:
    //Where are we getting the result of if expressions?

    Code *labelCode = generateLabelCode(label1);
    labelCode = joinCodes(labelCode, expr->code);

    char *reg = expr->code->res;
    Code *exprCode = createCBRCode(expr, reg, label2, label3, NULL, commands);
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
    labelCode = joinCodes(start->code, labelCode);
    labelCode = joinCodes(labelCode, expr->code);

    //TODO:
    //Where are we getting the result of if expressions?
    char *reg = expr->code->res;
    Code *conditionCode = createCBRCode(expr, reg, label2, NULL, label3, NULL);
    conditionCode = joinCodes(labelCode, conditionCode);

    Code *labelCode2 = generateLabelCode(label2);
    labelCode = joinCodes(conditionCode, labelCode2);
    labelCode = joinCodes(labelCode2, commands->code);
    labelCode = joinCodes(labelCode2, incr->code);

    Code *jumpCode = generateTrueConditionalJump(label1);
    labelCode = joinCodes(labelCode2, jumpCode);

    Code *labelCode3 = generateLabelCode(label3);
    labelCode3 = joinCodes(jumpCode, labelCode3);
    return labelCode3;
}

//void ILOC_add_local_var(node_t *parent, node_t *ident, node_t *initializer, char *type, STACK *stack){

Code *generateLocalVarCode(Node *identifier, Node *prev, Node *init, int initialized)
{
    if (DEBUG == 1)
    {
        printf("Generating local var code for %s\n", identifier->data->label);
    }
    char *pointer = malloc(10);
    char *offset = malloc(3);
    sprintf(pointer, "%s", RSP);
    sprintf(offset, "%s", "4");

    Code *updatesRSP = createCode(ADDI, pointer, pointer, offset, NULL, pointer, NULL, NULL);

    if (initialized == 1)
    {
        SymbolTableEntry *identifierEntry = findEntryInStack(getGlobalStack(), identifier->data->value.valueString);

        char *pointer2 = malloc(10);
        sprintf(pointer2, "%s", RFP);
        char *identifierOffset = malloc(10);
        sprintf(identifierOffset, "%d", identifierEntry->entryOffset);
        Code *attribution = createCode(STOREAI, pointer2, init->code->res, NULL, NULL, pointer2, identifierOffset, NULL);
        updatesRSP = joinCodes(updatesRSP, init->code);
        updatesRSP = joinCodes(updatesRSP, attribution);
        prev->code = updatesRSP;
    }
    else if (initialized == 0)
    {
        prev->code = updatesRSP;
    }
    return updatesRSP;
}

Code *generateBinaryExpression(char *binaryOperator, Node *parent, Node *child1, Node *child2)
{
    char *reg1 = child1->code->res;
    char *reg2 = child2->code->res;
    char *result = generateRegisterName();
    Operation operation = getOperation(binaryOperator);

    Code *code = createCode(operation, NULL, reg1, reg2, NULL, result, NULL, NULL);

    if (operation != AND && operation != OR)
    {
        child1->code = joinCodes(child1->code, child2->code);
        child1->code = joinCodes(child1->code, code);

        addToGlobalCodeList(child1->code);
        return child1->code;
    }
    else if (operation == AND)
    {
        Code *i2iCode = createCode(I2I, NULL, reg1, NULL, NULL, result, NULL, NULL);
        char *jumpLabel = generateLabelName();
        char *dontJumpLabel = generateLabelName();
        Code *cbrCode = createCode(CBR, NULL, result, NULL, NULL, dontJumpLabel, jumpLabel, NULL);

        cbrCode = joinCodes(i2iCode, cbrCode);
        Code *labelDontJump = generateLabelCode(dontJumpLabel);

        labelDontJump = joinCodes(cbrCode, labelDontJump);

        Code *labelJump = generateLabelCode(jumpLabel);

        parent->code = joinCodes(child1->code, labelDontJump);
        parent->code = joinCodes(parent->code, child2->code);
        parent->code = joinCodes(parent->code, code);
        parent->code = joinCodes(parent->code, labelJump);

        addToGlobalCodeList(parent->code);
        return parent->code;
    }
    else if (operation == OR)
    {
        Code *i2iCode = createCode(I2I, NULL, reg1, NULL, NULL, result, NULL, NULL);
        char *jumpLabel = generateLabelName();
        char *dontJumpLabel = generateLabelName();
        Code *cbrCode = createCode(CBR, NULL, result, NULL, NULL, jumpLabel, dontJumpLabel, NULL);
        cbrCode = joinCodes(i2iCode, cbrCode);

        Code *labelDontJump = generateLabelCode(dontJumpLabel);
        labelDontJump = joinCodes(cbrCode, labelDontJump);
        Code *labelJump = generateLabelCode(jumpLabel);

        parent->code = joinCodes(child1->code, labelDontJump);
        parent->code = joinCodes(parent->code, child2->code);
        parent->code = joinCodes(parent->code, code);
        parent->code = joinCodes(parent->code, labelJump);

        addToGlobalCodeList(parent->code);
        return parent->code;
    }
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
        return "hlt";
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
    char arg1[16] = "", arg2[16] = "", dest1[16] = "", dest2[16] = "", label[16] = "";
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
    char tempInstructionLine[128];
    sprintf(tempInstructionLine, "%s%s %s%s => %s%s", label, getOperationName(code->opCode), arg1, arg2, dest1, dest2);

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
