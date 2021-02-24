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
        | TK_IDENTIFICADOR '[' positive_integer ']';
value: signal TK_LIT_INT
        | signal TK_LIT_FLOAT
        | TK_LIT_FALSE
        | TK_LIT_TRUE
        | TK_LIT_CHAR
        | TK_LIT_STRING;
signal: '+'
        | '-'
        | ;


functionDefinition: functionHeader commandBlock;

functionHeader: optionalStatic type TK_IDENTIFICADOR '(' headerParameters ')';

headerParameters: optionalConst type TK_IDENTIFICADOR headerParametersList 
        | ;
headerParametersList: ',' optionalConst type TK_IDENTIFICADOR headerParametersList
        | ;

commandBlock: '{' commandList '}';
commandList: command commandList
        | ;
command: variableDeclaration ';'
        | attribution ';'
        | inputOutput ';'
        | functionCall ';'
        | shift ';'
        | executionControl ';'
        | fluxControl ';'
        | commandBlock ';';

variableDeclaration: optionalStatic optionalConst type variable variableDeclarationList;
variable: TK_IDENTIFICADOR
        | TK_IDENTIFICADOR TK_OC_LE value
        | TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR;
variableDeclarationList: ',' variable variableDeclarationList
        | ;

attribution: TK_IDENTIFICADOR '=' expression
        | TK_IDENTIFICADOR '[' expression ']' '=' expression;

inputOutput: input
        | output;

output: TK_PR_OUTPUT TK_IDENTIFICADOR
        | TK_PR_OUTPUT value;

input: TK_PR_INPUT TK_IDENTIFICADOR;

functionCall: TK_IDENTIFICADOR '(' functionParameters ')';
functionParameters: expression functionParametersList
        | ;
functionParametersList: ',' expression functionParametersList
        | ;

shift: TK_IDENTIFICADOR shiftOperator TK_LIT_INT
        | TK_IDENTIFICADOR '[' expression ']' shiftOperator positive_integer;
shiftOperator: TK_OC_SL
        | TK_OC_SR;

executionControl: TK_PR_RETURN expression
        | TK_PR_BREAK
        | TK_PR_CONTINUE;

fluxControl: conditional
        | while
        | for;
conditional: TK_PR_IF '(' expression ')' commandBlock else;
else: TK_PR_ELSE commandBlock
        | ;
while: TK_PR_WHILE '(' expression ')' TK_PR_DO commandBlock;
for: TK_PR_FOR '(' attribution  ':' expression ':' attribution ')' commandBlock;

expression: orLogicalExpression '?' expression ':' expression
    | orLogicalExpression;
orLogicalExpression: orLogicalExpression orLogicalOperator andLogicalExpression
        | andLogicalExpression;
andLogicalExpression: andLogicalExpression andLogicalOperator bitwiseOrExpression
    | bitwiseOrExpression;
bitwiseOrExpression: bitwiseOrExpression bitwiseOrOperator bitwiseAndExpression
    | bitwiseAndExpression;
bitwiseAndExpression: bitwiseAndExpression bitwiseAndOperator equalityExpression
    | equalityExpression;
equalityExpression: equalityExpression equalityOperator comparisonExpression
        | comparisonExpression;
comparisonExpression: comparisonExpression comparisonOperator sumExpression
        | sumExpression;
sumExpression: sumExpression sumOperator multiplicationExpression
        | multiplicationExpression;
multiplicationExpression: multiplicationExpression multiplicationOperator powerExpression
        | powerExpression;
powerExpression: powerExpression powerOperator unaryExpression
        | unaryExpression;
unaryExpression: unaryOperator unaryExpression
        | operand;

orLogicalOperator: TK_OC_OR;
andLogicalOperator: TK_OC_AND;
bitwiseOrOperator: '|';
bitwiseAndOperator: '&';
equalityOperator: TK_OC_EQ
        | TK_OC_NE;
comparisonOperator: TK_OC_LE
        | TK_OC_GE
        | '<'
        | '>';
sumOperator: '+'
        | '-';
multiplicationOperator: '*'
        | '/'
        | '%';
powerOperator: '^';
unaryOperator: '+'
        | '-'
        | '!'
        | '&'
        | '*'
        | '?'
        | '#';
operand: TK_IDENTIFICADOR
        | TK_IDENTIFICADOR '[' expression ']'
        | value
        | functionCall
        | '(' expression ')';

positive_integer: '+' TK_LIT_INT | TK_LIT_INT;

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