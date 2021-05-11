#include "assembly.h"

void pop_Asm(char *reg)
{
    printf("\tmovl\t(%%rsp), %%%s\n", reg); // Tira da pilha
    printf("\taddq\t$4, %%rsp\n");
}

void push_Asm()
{
    printf("\tsubq\t$4, %%rsp\n");
    printf("\tmovl\t%%eax, (%%rsp)\n"); // Bota na pilha
}

void print_binary_op_assembly(char *op)
{
    pop_Asm("edx");
    pop_Asm("eax");
    printf("\t%s\t%%edx, %%eax\n", op); // OP
    push_Asm();
}

void print_division_op_assembly(char *op)
{
    pop_Asm("ebx");
    pop_Asm("eax");
    printf("\tcdq\n");           // Extende sinal
    printf("\t%s\t%%ebx\n", op); // OP
    push_Asm();
}

void printAssembly(Code *c)
{
    if (c == NULL)
        return;

    // if (c->label != NULL)
    // {
    //     if (printa_label_fun(c->label))
    //     { // <========= CHECK THIS LATER
    //         // pop_from_return_function = load_parameters(c->label);
    //     }
    //     else
    //         printf(".L%d:\n", c->label);
    // }

    // if (c->tipo == function_call_preparation_code)
    // {
    //     // Ignora store de RSP e RFP
    //     printAssembly(c->next->next);
    //     return;
    // }

    // if (c->tipo == function_return_load_code)
    // {
    //     push_Asm();
    //     printAssembly(c->next);
    //     return;
    // }

    // if (c->tipo == function_return_code)
    // {
    //     printf("\tmovl\t(%%rsp), %%eax\n");
    //     printf("\taddq\t$4, %%rsp\n");
    //     printAssembly(c->next);
    //     return;
    // }

    // if (c->tipo == main_function_exit_code)
    // {
    //     printf("\tleave\n");
    //     printf("\tret\n");
    //     return; // Fim do programa - sem nada depois da main
    // }

    // if (c->tipo == function_exit_code)
    // {
    //     printf("\tleave\n");
    //     printf("\tret\n");
    //     printAssembly(c->next->next->next);
    //     return;
    // }

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
        if (c->arg1 == RPC)
        {
            callFunction_Asm(c->next->next->dest1); // <=========
            c = c->next->next;
        }
        else
            opI_Asm("add", c); // <=========
        break;
    case SUBI:
        opI_Asm("sub", c);
        break;
    case RSUBI:
        pop_Asm("eax");
        printf("\tnegl\t%%eax\n");
        push_Asm();
        break;
    case MULTI:
        break;
    case DIVI:
        break;
    case LOADI:
        opLoadI_Asm(c); //<======
        break;
    case LOADAI:
        opLoadAI_Asm(c); //<======
        break;
    case STOREAI:
        opStoreAI_Asm(c); //<======
        break;
    case I2I:
        if (c->arg1 < 0 && c->dest1 < 0) //<====CHECK THIS LATER
            printf("\tmovq\t%%%s, %%%s\n", converte_AsmReg(c->arg1), converte_AsmReg(c->dest1));
        // "else" Not currently on use
        break;
    case CMP_LT:
        jmpCond_Asm("jge", c->next->dest2); //<======
        c = c->next;
        break;
    case CMP_LE:
        jmpCond_Asm("jg", c->next->dest2); //<======
        c = c->next;
        break;
    case CMP_EQ:
        jmpCond_Asm("jne", c->next->dest2); //<======
        c = c->next;
        break;
    case CMP_GE:
        jmpCond_Asm("jl", c->next->dest2); //<======
        c = c->next;
        break;
    case CMP_GT:
        jmpCond_Asm("jle", c->next->dest2); //<======
        c = c->next;
        break;
    case CMP_NE:
        jmpCond_Asm("je", c->next->dest2); //<======
        c = c->next;
        break;
    // case op_jump:
    //     break;
    case JUMPI:
        printf("\tjmp\t.L%d\n", c->dest1);
        break;
    default:
        break;
    }
    printAssembly(c->next);
}