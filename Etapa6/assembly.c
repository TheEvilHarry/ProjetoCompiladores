#include "assembly.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialCodePrint()
{
    printf("\t.file\t\"programa.c\"\n");
    printf("\t.text\n");
}

void globalInfoPrint()
{
    SymbolTableEntry *entry = getGlobalStack()->top;
    while (entry != NULL)
    {
        if (entry->nature == NATURE_variable)
        {
            printf("\t.comm\t%s,4\n", entry->key);
        }
        else if (entry->nature == NATURE_function)
        {
            printf("\t.globl\t%s\n", entry->key);
            printf("\t.type\t%s, @function\n", entry->key);
        }
        entry = entry->nextEntry;
    }
}

void generateAssembly(Code *code)
{
    initialCodePrint();
    globalInfoPrint();
    printAssembly(code);
}

void pop(char *reg)
{
    printf("\tmovl\t(%%rsp), %%%s\n", reg); // Tira da pilha
    printf("\taddq\t$4, %%rsp\n");
}

void push()
{
    printf("\tsubq\t$4, %%rsp\n");
    printf("\tmovl\t%%eax, (%%rsp)\n"); // Bota na pilha
}

void print_binary_op_assembly(char *op)
{
    pop("edx");
    pop("eax");
    printf("\t%s\t%%edx, %%eax\n", op); // OP
    push();
}

void print_division_op_assembly(char *op)
{
    pop("ebx");
    pop("eax");
    printf("\tcdq\n");           // Extende sinal
    printf("\t%s\t%%ebx\n", op); // OP
    push();
}

int isSpecialRegister(char *address)
{

    if (strcmp(address, RSP) == 0 || strcmp(address, RFP) == 0 || strcmp(address, RBSS) == 0)
        return 1;
    else
        return 0;
}

char *registerConversion(char *reg)
{

    if (strcmp(reg, RBSS) == 0)
        return "rip";
    else if (strcmp(reg, RFP) == 0)
        return "rbp";
    else if (strcmp(reg, RSP) == 0)
        return RSP;
    else
        return reg;
}

void pushValue(char *value)
{
    printf("\tsubq\t$4, %%rsp\n");
    printf("\tmovl\t$%s, (%%rsp)\n", value);
}

void conditionalJumpAssembly(char *jump_cond, char *label)
{
    pop("edx");
    pop("eax");
    printf("\tcmpl\t%%edx, %%eax\n");
    printf("\t%s\t.%s\n", jump_cond, label);
}

void printLoadAiAssembly(Code *c)
{
    if (isSpecialRegister(c->dest1) == 1)
    {
        if (strcmp(c->arg1, RBSS) == 0)
            printf("\tmovl\t%s(%%rip), (%%%s) \n", getKeyFromOffset(atoi(c->arg1)), registerConversion(c->dest1));
        else
            printf("\tmovl\t%s(%%%s), (%%%s) \n", c->arg2, registerConversion(c->arg1), registerConversion(c->dest1));
    }
    else
    {
        if (strcmp(c->arg1, RBSS) == 0)
            printf("\tmovl\t%s(%%rip), %%eax\n ", getKeyFromOffset(atoi(c->arg1)));
        else
            printf("\tmovl\t%s(%%%s), %%eax \n", c->arg2, registerConversion(c->arg1));
        push();
    }
}

void printLoadIAssembly(Code *c)
{
    if (isSpecialRegister(c->dest1) == 1)
    {
        printf("\tmovl\t$%s, (%%%s)\n", c->arg1, registerConversion(c->dest1));
    }
    else
    {
        pushValue(c->arg1);
    }
}

char *getKeyFromOffset(int offset)
{
    SymbolTableEntry *entry = findEntryInTableByOffset(getGlobalScopeTable(getGlobalStack())->top, offset);

    return entry->key;
}

void printStoreAiAssembly(Code *c)
{

    pop("eax");
    // Store
    if (strcmp(c->dest1, RBSS) == 0)
        printf("\tmovl\t%%eax, %s(%%rip)\n", getKeyFromOffset(atoi(c->dest2)));
    else
        printf("\tmovl\t%%eax, %s(%%%s)\n", c->dest2, registerConversion(c->dest1));
}

void callFunction_Asm(char *label_fun)
{
    //TODO:
    // printf("\tcall\t%s\n", get_function_name(label_fun));
}

void intOperation(char *op, Code *c)
{
    if (strcmp(c->arg1, c->dest1) == 0 && isSpecialRegister(c->arg1) == 1)
    { // Sendo utilizado para inicio de funcao
        printf("\t%sq\t$%s, %%%s\n", op, c->arg2, registerConversion(c->arg1));
    }
    else
    {
        if (isSpecialRegister(c->arg1) == 1)
        {
            printf("\tmovl\t%%%s, %%eax\n", registerConversion(c->arg1));
        }
        else
        {
            // pop_Asm("eax");
        }
        printf("\t%sl\t$%s, %%eax\n", op, c->arg2);
        if (isSpecialRegister(c->dest1) == 1)
        {
            printf("\tmovl\t%%eax, %%%s\n", registerConversion(c->dest1));
        }
        else
        {
            push();
        }
    }
}

int printFunctionLabel(char *label)
{
    SymbolTableEntry *table = getGlobalScopeTable(getGlobalStack())->top;
    SymbolTableEntry *currentEntry;

    for (currentEntry = table; currentEntry != NULL; currentEntry = currentEntry->nextEntry)
    {
        if (strcmp(currentEntry->ILOCLabel, label) == 0)
        {
            printf("%s:\n", currentEntry->key);
            printf("\tendbr64\n");
            printf("\tpushq\t%%rbp\n");
            return 1;
        }
    }

    return 0;
}

void printAssembly(Code *c)
{
    if (c == NULL)
        return;

    if (c->label != NULL)
    {
        if (printFunctionLabel(c->label) == 1)
        {
            printf(".%s:\n", c->label);
        }
    }

    if (c->type == function_call_preparation_code)
    {
        // Ignora store de RSP e RFP
        printAssembly(c->next->next);
        return;
    }

    if (c->type == function_return_load_code)
    {
        push();
        printAssembly(c->next);
        return;
    }

    if (c->type == function_return_code)
    {
        printf("\tmovl\t(%%rsp), %%eax\n");
        printf("\taddq\t$4, %%rsp\n");
        printAssembly(c->next);
        return;
    }

    if (c->type == main_function_exit_code)
    {
        printf("\tleave\n");
        printf("\tret\n");
        return; // Fim do programa - sem nada depois da main
    }

    if (c->type == function_exit_code)
    {
        printf("\tleave\n");
        printf("\tret\n");
        printAssembly(c->next->next->next);
        return;
    }

    switch (c->opCode)
    {
    case ADD:
        print_binary_op_assembly("addl");
        break;
    case SUB:
        print_binary_op_assembly("subl");
        break;
    case MULT:
        print_binary_op_assembly("imull");
        break;
    case DIV:
        print_division_op_assembly("idivl");
        break;
    case ADDI:
        if (strcmp(c->arg1, RPC) == 0)
        {
            callFunction_Asm(c->next->next->dest1); // <=========
            c = c->next->next;
        }
        else
            intOperation("add", c); // <=========
        break;
    case SUBI:
        intOperation("sub", c);
        break;
    case RSUBI:
        pop("eax");
        printf("\tnegl\t%%eax\n");
        push();
        break;
    case MULTI:
        break;
    case DIVI:
        break;
    case LOADI:
        printLoadIAssembly(c);
        break;
    case LOADAI:
        printLoadAiAssembly(c);
        break;
    case STOREAI:
        printStoreAiAssembly(c);
        break;
    case I2I:
        if (isSpecialRegister(c->arg1) && isSpecialRegister(c->dest1) == 1) //<====CHECK THIS LATER
            printf("\tmovq\t%%%s, %%%s\n", registerConversion(c->arg1), registerConversion(c->dest1));
        break;
    case CMP_LT:
        conditionalJumpAssembly("jge", c->next->dest2);
        c = c->next;
        break;
    case CMP_LE:
        conditionalJumpAssembly("jg", c->next->dest2);
        c = c->next;
        break;
    case CMP_EQ:
        conditionalJumpAssembly("jne", c->next->dest2);
        c = c->next;
        break;
    case CMP_GE:
        conditionalJumpAssembly("jl", c->next->dest2);
        c = c->next;
        break;
    case CMP_GT:
        conditionalJumpAssembly("jle", c->next->dest2);
        c = c->next;
        break;
    case CMP_NE:
        conditionalJumpAssembly("je", c->next->dest2);
        c = c->next;
        break;
    // case op_jump:
    //     break;
    case JUMPI:
        printf("\tjmp\t.%s\n", c->dest1);
        break;
    default:
        break;
    }
    printAssembly(c->next);
}

void handleRootCodeExport(Node *root)
{
    Code *code = getFirstCode(root->code);
    Code *fullCode = getFirstCode(joinCodes(generateInitialInstructions(code), code));
    Node *rootWithCode = addCodeToNode(root, fullCode);
    // exportCodeList(rootWithCode->code);
    generateAssembly(fullCode);
}