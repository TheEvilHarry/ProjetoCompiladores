%{
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
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

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token<valor_lexico> TK_PR_IF
%token TK_PR_THEN
%token<valor_lexico> TK_PR_ELSE
%token<valor_lexico> TK_PR_WHILE
%token TK_PR_DO
%token<valor_lexico> TK_PR_INPUT
%token<valor_lexico> TK_PR_OUTPUT
%token<valor_lexico> TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token<valor_lexico> TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token<valor_lexico> TK_PR_BREAK
%token<valor_lexico> TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_PR_END
%token TK_PR_DEFAULT
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
%token ','
%token ';'
%token ':'
%token '('
%token ')'
%token '['
%token ']'
%token '{'
%token '}'
%token '+'
%token '-'
%token '|'
%token '*'
%token '/'
%token '<'
%token '>'
%token '='
%token '!'
%token '&'
%token '%'
%token '#'
%token '^'
%token '.'
%token '$'
%token '?'
%token TOKEN_ERRO


%type<node> program
%type<node> globalVariable
%type<node> functionDefinition
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
%type<node> positive_integer
%type<node> operand
%type<node> orLogicalOperator
%type<node> andLogicalOperator
%type<node> bitwiseOrOperator
%type<node> bitwiseAndOperator
%type<node> equalityOperator
%type<node> sumOperator
%type<node> multiplicationOperator
%type<node> powerOperator
%type<node> unaryOperator
%type<node> comparisonOperator
%type<node> vector_identifier


%type<node> functionHeader			//CHECK THIS LATER
%type<node> shiftOperator

%%

program: globalVariable program { $$ = $2; arvore = $$; }
        | functionDefinition program {$$=$1; addNext($$, $2); arvore=$$; }
        | {$$=NULL;};

optionalStatic: TK_PR_STATIC  { $$ = NULL; }
        |  { $$ = NULL; };
optionalConst: TK_PR_CONST  { $$ = NULL; }
        |  { $$ = NULL; };

globalVariable: optionalStatic type identifier globalVariableList ';' {$$=NULL;} ;
globalVariableList: ',' identifier globalVariableList {$$=NULL;}
        | {$$=NULL;};

type: TK_PR_INT { $$ = NULL; }
        | TK_PR_FLOAT  { $$ = NULL; }
        | TK_PR_CHAR  { $$ = NULL; }
        | TK_PR_BOOL  { $$ = NULL; }
        | TK_PR_STRING  { $$ = NULL; };

value: TK_LIT_INT {$$=createNode($1);}
        | TK_LIT_FLOAT {$$=createNode($1);}
        | TK_LIT_FALSE {$$=createNode($1);}
        | TK_LIT_TRUE {$$=createNode($1);}
        | TK_LIT_CHAR {$$=createNode($1);}
        | TK_LIT_STRING {$$=createNode($1);};

functionDefinition: functionHeader commandBlock {addChild($1,$2); $$=$1;} ;  //CHECK LATER

functionHeader: optionalStatic type TK_IDENTIFICADOR '(' headerParameters ')' {$$=createNode($3);} ;

headerParameters: optionalConst type TK_IDENTIFICADOR headerParametersList {freeToken($3);$$=NULL;}
        | {$$=NULL;};
headerParametersList: ',' optionalConst type TK_IDENTIFICADOR headerParametersList {$$=NULL;}
        | {$$=NULL;};

commandBlock: '{' commandList '}' {$$=$2;} ;

commandList: command commandList { addNext($1, $2); $$=$1; }
        | {$$=NULL;};

command: variableDeclaration ';' {$$ = $1; }
        | attribution ';' {$$ = $1; }
        | inputOutput ';' {$$ = $1; }
        | functionCall ';' {$$ = $1; }
        | shift ';' {$$ = $1; }
        | executionControl ';' {$$ = $1; }      // CHECK IF TRUE
        | fluxControl {$$ = $1;}
        | commandBlock {$$ = $1;};


attribution: TK_IDENTIFICADOR '=' expression {$$=createCustomLabelNode("=", yylineno); addChild($$,createNode($1)); addChild($$,$3);}
        | vector_identifier '=' expression {$$=createCustomLabelNode("=", yylineno); addChild($$,$1); addChild($$,$3);};

inputOutput: input {$$=$1;}
        | output {$$=$1;};

output: TK_PR_OUTPUT TK_IDENTIFICADOR {$$=createCustomLabelNode("output", yylineno); addChild($$,createNode($2));}
        | TK_PR_OUTPUT value {$$=createCustomLabelNode("output", yylineno); addChild($$,$2);};

input: TK_PR_INPUT TK_IDENTIFICADOR {$$=createCustomLabelNode("input", yylineno); addChild($$,createNode($2));} ;


shift: TK_IDENTIFICADOR shiftOperator TK_LIT_INT {addChild($2,createNode($1)); addChild($2,createNode($3)); $$=$2;}
        | vector_identifier shiftOperator positive_integer {addChild($2,$1); addChild($2,$3); $$=$2;} ;

shiftOperator: TK_OC_SL {$$=createNode($1);}
        | TK_OC_SR {$$=createNode($1);};

executionControl: TK_PR_RETURN expression {$$=createCustomLabelNode("return", yylineno); addChild($$,$2);}
        | TK_PR_BREAK {$$=createCustomLabelNode("break", yylineno);}
        | TK_PR_CONTINUE {$$=createCustomLabelNode("continue", yylineno);};

fluxControl: conditional {$$=$1;}
        | while {$$=$1;}
        | for {$$=$1;};
conditional: TK_PR_IF '(' expression ')' commandBlock else {$$=createCustomLabelNode("if", yylineno); addChild($$,$3);addChild($$,$5);addChild($$,$6);};

else: TK_PR_ELSE commandBlock {$$=createCustomLabelNode("else", yylineno);}
        | {$$=NULL;} ;

while: TK_PR_WHILE '(' expression ')' TK_PR_DO commandBlock {$$=createCustomLabelNode("while", yylineno); addChild($$,$3); addChild($$,$6);};


for: TK_PR_FOR '(' attribution  ':' expression ':' attribution ')' commandBlock {$$=createCustomLabelNode("for", yylineno); addChild($$,$3); addChild($$,$5); addChild($$,$7); addChild($$,$9);} ;

expression: orLogicalExpression '?' expression ':' expression {$$=createCustomLabelNode("?:", yylineno); addChild($$,$1); addChild($$,$3); addChild($$,$5);  }
    | orLogicalExpression {$$=$1;};

orLogicalExpression: orLogicalExpression orLogicalOperator andLogicalExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
        | andLogicalExpression {$$=$1;};

andLogicalExpression: andLogicalExpression andLogicalOperator bitwiseOrExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
    | bitwiseOrExpression {$$=$1;};

bitwiseOrExpression: bitwiseOrExpression bitwiseOrOperator bitwiseAndExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
    | bitwiseAndExpression {$$=$1;};

bitwiseAndExpression: bitwiseAndExpression bitwiseAndOperator equalityExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
    | equalityExpression {$$=$1;};

equalityExpression: equalityExpression equalityOperator comparisonExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
        | comparisonExpression {$$=$1;};
comparisonExpression: comparisonExpression comparisonOperator sumExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
        | sumExpression {$$=$1;};
sumExpression: sumExpression sumOperator multiplicationExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
        | multiplicationExpression {$$=$1;};
multiplicationExpression: multiplicationExpression multiplicationOperator powerExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
        | powerExpression {$$=$1;};
powerExpression: powerExpression powerOperator unaryExpression {addChild($2,$1); addChild($2,$3); $$=$2;}
        | unaryExpression {$$=$1;};

unaryExpression: unaryOperator unaryExpression {$$=$1; addChild($$, $2); }
        | operand {$$=$1;};

orLogicalOperator: TK_OC_OR {$$=createNode($1);};
andLogicalOperator: TK_OC_AND {$$=createNode($1);} ;
bitwiseOrOperator: '|' {$$=createCustomLabelNode("|", yylineno);};
bitwiseAndOperator: '&' {$$=createCustomLabelNode("&", yylineno);};
equalityOperator: TK_OC_EQ {$$=createNode($1);}
        | TK_OC_NE {$$=createNode($1);};
comparisonOperator: TK_OC_LE {$$=createNode($1);}
        | TK_OC_GE {$$=createNode($1);}
        | '<' {$$=createCustomLabelNode("<", yylineno);}
        | '>' {$$=createCustomLabelNode(">", yylineno);};
sumOperator: '+' {$$=createCustomLabelNode("+", yylineno);};
        | '-' {$$=createCustomLabelNode("-", yylineno);};
multiplicationOperator: '*' {$$=createCustomLabelNode("*", yylineno);}
        | '/' {$$=createCustomLabelNode("/", yylineno);};
        | '%' {$$=createCustomLabelNode("%", yylineno);};
powerOperator: '^' {$$=createCustomLabelNode("^", yylineno);};
unaryOperator: '+' {$$=createCustomLabelNode("+", yylineno);}
        | '-' {$$=createCustomLabelNode("-", yylineno);}
        | '!' {$$=createCustomLabelNode("!", yylineno);}
        | '&' {$$=createCustomLabelNode("&", yylineno);}
        | '*' {$$=createCustomLabelNode("*", yylineno);}
        | '?' {$$=createCustomLabelNode("?", yylineno);}
        | '#' {$$=createCustomLabelNode("#", yylineno);} ;

variableDeclaration: optionalStatic optionalConst type variable variableDeclarationList {

	if($4==NULL){
		$$=$5;	}
	else{
		$4->next=$5;
		$$=$4;}
};

variable: TK_IDENTIFICADOR {$$=NULL; freeToken($1);}
        | TK_IDENTIFICADOR TK_OC_LE value {$$=createNode($2); addChild($$,createNode($1)); addChild($$,$3); }
        | TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR {$$=createNode($2); addChild($$,createNode($1)); addChild($$,createNode($3)); };

variableDeclarationList: ',' variable variableDeclarationList {

	if($2==NULL){
		$$=$3;	}
	else{
		$2->next = $3;
		$$=$2;	}
}
        | {$$=NULL;};


functionCall: TK_IDENTIFICADOR '(' functionParameters ')' {
	char str[10]="call ";

        strcat(str, $1->label);

	$$=createCustomLabelNode(str, yylineno);

	addChild($$,createNode($1));
	addChild($$,$3);
} ;

functionParameters: expression functionParametersList { $$=addNext($1, $2); }
        | {$$=NULL;};

functionParametersList: ',' expression functionParametersList { $$=addNext($2, $3); }
        | {$$=NULL;};

operand: TK_IDENTIFICADOR {$$=createNode($1);}
        | vector_identifier {$$=$1;}
        | value {$$=$1;}
        | functionCall {$$=$1;}
        | '(' expression ')' {$$=$2;};

vector_identifier: TK_IDENTIFICADOR '[' expression ']' { $$=createCustomLabelNode("[]", yylineno); addChild($$, createNode($1)); addChild($$, $3); };

identifier: TK_IDENTIFICADOR {freeToken($1);}
          | TK_IDENTIFICADOR '[' positive_integer ']' { freeToken($1); freeAST($3); };


positive_integer: '+' TK_LIT_INT {$$=createNode($2);}
		| TK_LIT_INT {$$=createNode($1);};


%%

int yyerror (char const *s) {
    printf("Error on line %d: %s.\n", yylineno, s);
    return 1;
}