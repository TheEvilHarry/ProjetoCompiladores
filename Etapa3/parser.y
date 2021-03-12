%{
#include "stdio.h"
#include "stdlib.h"
#include "ast.h"

extern void *arvore;

extern int yylineno;
int yylex(void);
int yyerror (char const *s);
%}

%union{
        TokenData *valor_lexico;
        Node *node;
}

%define parse.lac full
%define parse.error verbose

%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT
%token<valor_lexico> TK_PR_BOOL
%token<valor_lexico> TK_PR_CHAR
%token<valor_lexico> TK_PR_STRING
%token<valor_lexico> TK_PR_IF
%token<valor_lexico> TK_PR_THEN
%token<valor_lexico> TK_PR_ELSE
%token<valor_lexico> TK_PR_WHILE
%token<valor_lexico> TK_PR_DO
%token<valor_lexico> TK_PR_INPUT
%token<valor_lexico> TK_PR_OUTPUT
%token<valor_lexico> TK_PR_RETURN
%token<valor_lexico> TK_PR_CONST
%token<valor_lexico> TK_PR_STATIC
%token<valor_lexico> TK_PR_FOREACH
%token<valor_lexico> TK_PR_FOR
%token<valor_lexico> TK_PR_SWITCH
%token<valor_lexico> TK_PR_CASE
%token<valor_lexico> TK_PR_BREAK
%token<valor_lexico> TK_PR_CONTINUE
%token<valor_lexico> TK_PR_CLASS
%token<valor_lexico> TK_PR_PRIVATE
%token<valor_lexico> TK_PR_PUBLIC
%token<valor_lexico> TK_PR_PROTECTED
%token<valor_lexico> TK_PR_END
%token<valor_lexico> TK_PR_DEFAULT
%token<valor_lexico> TK_OC_LE
%token<valor_lexico> TK_OC_GE
%token<valor_lexico> TK_OC_EQ
%token<valor_lexico> TK_OC_NE
%token<valor_lexico> TK_OC_AND
%token<valor_lexico> TK_OC_OR
%token<valor_lexico> TK_OC_SL
%token<valor_lexico> TK_OC_SR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> TK_LIT_CHAR
%token<valor_lexico> TK_LIT_STRING
%token<valor_lexico> TK_IDENTIFICADOR
%token TOKEN_ERRO

%type<node> program
%type<node> globalVariable
%type<node>functionDefinition
%type<node> optionalConst
%type<node> optionalStatic
%type<node> globalVariableList
%type<node> type
%type<node> identifier
%type<node> value
%type<node> commandBlock
%type<node> functionParametersList
%type<node> functionParameters
%type<node> headerParameters
%type<node> headerParametersList
%type<node> commandList
%type<node> command 
%type<node> variableDeclaration
%type<node> variableDeclarationList
%type<node> variable
%type<node> attribution
%type<node> inputOutput
%type<node> input
%type<node> output
%type<node> functionCall
%type<node> shift
%type<node> executionControl
%type<node> fluxControl
%type<node> conditional
%type<node> else 
%type<node> for
%type<node> while 
%type<node> expression
%type<node> orLogicalExpression
%type<node> andLogicalExpression
%type<node> bitwiseOrExpression
%type<node> bitwiseAndExpression
%type<node> equalityExpression
%type<node> comparisonExpression
%type<node> sumExpression
%type<node> multiplicationExpression
%type<node> powerExpression
%type<node> unaryExpression

%type<valor_lexico> functionHeader
%type<valor_lexico> shiftOperator
%%

//  estudando como estruturar a criação dos nodos ainda
// Let's create the nodes from the bottom-up
// need a join nodes function (?) maybe
//label is at node>data>tokenvalue>value

program: globalVariable program { $$ = $2; arvore = $$; }
        | functionDefinition program {$$=$1; $1->next = $2; arvore=$$; }
        | {$$=NULL;};

optionalStatic: TK_PR_STATIC  { $$ = NULL; }
        |  { $$ = NULL; };
optionalConst: TK_PR_CONST  { $$ = NULL; }
        |  { $$ = NULL; };

globalVariable: optionalStatic type identifier globalVariableList ';' {$$=NULL; freeToken($4);} ;
globalVariableList: ',' identifier globalVariableList {$$=NULL; freeToken($1);}
        | {$$=NULL};

type: TK_PR_INT { $$ = NULL; }
        | TK_PR_FLOAT  { $$ = NULL; }
        | TK_PR_CHAR  { $$ = NULL; }
        | TK_PR_BOOL  { $$ = NULL; }
        | TK_PR_STRING  { $$ = NULL; };
identifier: TK_IDENTIFICADOR
        | TK_IDENTIFICADOR '[' positive_integer ']';

value: TK_LIT_INT {createNode($1);}
        | TK_LIT_FLOAT {createNode($1);}
        | TK_LIT_FALSE {createNode($1);}
        | TK_LIT_TRUE {createNode($1);}
        | TK_LIT_CHAR {createNode($1);}
        | TK_LIT_STRING {createNode($1);};

functionDefinition: functionHeader commandBlock {add_child($1,$2); $$=S1;} ;  //CHECK LATER

functionHeader: optionalStatic type TK_IDENTIFICADOR '(' headerParameters ')' {$$=createNode($3);} ;

headerParameters: optionalConst type TK_IDENTIFICADOR headerParametersList {freeToken($3);$$=NULL;}
        | ;
headerParametersList: ',' optionalConst type TK_IDENTIFICADOR headerParametersList {$$=NULL;}
        | {$$=NULL;};

commandBlock: '{' commandList '}';
commandList: command commandList
        | ;
command: variableDeclaration ';' {$$ = $1; }
        | attribution ';' {$$ = $1; }
        | inputOutput ';' {$$ = $1; }
        | functionCall ';' {$$ = $1; }
        | shift ';' {$$ = $1; }
        | executionControl ';' {$$ = $1; }      // CHECK IF TRUE
        | fluxControl ';' {$$ = $1; }
        | commandBlock ';' {$$ = $1; };

variableDeclaration: optionalStatic optionalConst type variable variableDeclarationList;

variable: TK_IDENTIFICADOR
        | TK_IDENTIFICADOR TK_OC_LE value
        | TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR;
variableDeclarationList: ',' variable variableDeclarationList
        | ;

attribution: TK_IDENTIFICADOR '=' expression
        | TK_IDENTIFICADOR '[' expression ']' '=' expression;

inputOutput: input {$$=$1;}
        | output {$$=$1;};

output: TK_PR_OUTPUT TK_IDENTIFICADOR {$$=createNote($1); addChild($$,$2);}
        | TK_PR_OUTPUT value {$$=createNote($1); addChild($$,$2);};

input: TK_PR_INPUT TK_IDENTIFICADOR {$$=createNote($1); addChild($$,$2);} ;

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
        | TK_PR_BREAK {$$=createNode($1);}
        | TK_PR_CONTINUE {$$=createNode($1);};

fluxControl: conditional {$$=$1;}
        | while
        | for;
conditional: TK_PR_IF '(' expression ')' commandBlock else {$$=createNode($1); addChild{$$,$3};addChild{$$,$5};addChild{$$,$6};};

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
unaryOperator: '+' {$$=$1;}
        | '-' {$$=$1;}
        | '!' {$$=$1;}
        | '&' {$$=$1;}
        | '*' {$$=$1;}
        | '?' {$$=$1;}
        | '#' {$$=$1;};

operand: TK_IDENTIFICADOR {$$=createNode($1);}
        | TK_IDENTIFICADOR '[' expression ']'
        | value {$$=$1;}
        | functionCall
        | '(' expression ')' {freeToken($1); freeToken($3); $$=S2;};

positive_integer: '+' TK_LIT_INT {$$=createNote($1);}
		| TK_LIT_INT {$$=createNote($1);};

%%

int yyerror (char const *s) {
    printf("Error on line %d: %s.\n", yylineno, s);
    return 1;
}