%{
#include "stdio.h"
#include "stdlib.h"

extern int yylineno;
int yylex(void);
int yyerror (char const *s);
%}

%define parse.lac full
%define parse.error verbose

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token TK_PR_BREAK
%token TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_PR_END
%token TK_PR_DEFAULT
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_SL
%token TK_OC_SR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO

%%
 
program: globalVariable program
        | functionDefinition program
        | ;

optionalStatic: TK_PR_STATIC
        | ;
optionalConst: TK_PR_CONST
        | ;

globalVariable: optionalStatic type identifier globalVariableList ';';
globalVariableList: ',' identifier globalVariableList
        | ;

type: TK_PR_INT
        | TK_PR_FLOAT
        | TK_PR_CHAR
        | TK_PR_BOOL
        | TK_PR_STRING;
identifier: TK_IDENTIFICADOR
        | TK_IDENTIFICADOR '[' TK_LIT_INT ']';
value: TK_LIT_INT
        | TK_LIT_FLOAT
        | TK_LIT_FALSE
        | TK_LIT_TRUE
        | TK_LIT_CHAR
        | TK_LIT_STRING;


functionDefinition: functionHeader commandBlock;

functionHeader: optionalStatic type TK_IDENTIFICADOR '(' parameters ')';

parameters: optionalConst type TK_IDENTIFICADOR parametersList 
        | ;
parametersList: ',' TK_PR_CONST type TK_IDENTIFICADOR parametersList
        | ;

commandBlock: '{' simpleCommandList '}';
simpleCommandList: simpleCommand ';' simpleCommandList
        | ;
simpleCommand: ;
        /* variable_declaration
        | attribution_command
        | input_output_command
        | function_call
        | shift_command 
        | execution_control_commands
        | flux_control_commands
        | commandBlock; */

%%

int yyerror (char const *s) {
    printf("Error on line %d: %s.\n", yylineno, s);
    return 1;
}

int main() {
    int ret = yyparse();
    if (ret != 0) {
        fprintf(stderr, "%d errors found.\n", ret);
    }
    return 0;
}