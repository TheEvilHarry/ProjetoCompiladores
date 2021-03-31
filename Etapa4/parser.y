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
        int type;
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
%type<node> identifier
%type<node> value
%type<node> commandBlockInit
%type<node> commandBlockEnd
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
%type<node> functionName			
%type<node> shiftOperator

%type<type> type

%%

program: globalVariable program { $$ = $2; arvore = $$; }
        | functionDefinition program {$$=$1; addNext($$, $2); arvore=$$; }
        | {$$=NULL;};

optionalStatic: TK_PR_STATIC  { $$ = NULL; }
        |  { $$ = NULL; };
optionalConst: TK_PR_CONST  { $$ = NULL; }
        |  { $$ = NULL; };

globalVariable: optionalStatic type identifier globalVariableList ';' { 
        $$=NULL; 
        endVariableListDeclaration($2); };  // <==== Is this not gonna be a token/node being attributed to a function expecting a Type? #PEDRO

globalVariableList: ',' identifier globalVariableList {$$=NULL;}
        | { $$=NULL; };

type: TK_PR_INT { $$ = TYPE_INTEGER; }
        | TK_PR_FLOAT  { $$ = TYPE_FLOAT; }
        | TK_PR_CHAR  { $$ = TYPE_CHAR; }
        | TK_PR_BOOL  { $$ = TYPE_BOOL; }
        | TK_PR_STRING  { $$ = TYPE_STRING; };

value: TK_LIT_INT {
                $$=createNode($1, TYPE_INTEGER);
	        createLiteralTableEntry(yylineno, TYPE_INTEGER,$1); }
        | TK_LIT_FLOAT {
                createLiteralTableEntry(yylineno, TYPE_FLOAT, $1);
                $$=createNode($1, TYPE_FLOAT); }
        | TK_LIT_FALSE {
                createLiteralTableEntry(yylineno, TYPE_BOOL, $1);
                $$=createNode($1, TYPE_BOOL); }
        | TK_LIT_TRUE {
                createLiteralTableEntry(yylineno, TYPE_BOOL, $1);
                $$=createNode($1, TYPE_BOOL); }
        | TK_LIT_CHAR {
                createLiteralTableEntry(yylineno, TYPE_CHAR, $1);
                $$=createNode($1, TYPE_CHAR); }
        | TK_LIT_STRING {
                createLiteralTableEntry(yylineno, TYPE_STRING, $1);
                $$=createNode($1, TYPE_STRING); };

functionDefinition: functionHeader functionCommandBlockInit commandBlockEnd {
        addChild($1,$3);
        $$=$1; };  //CHECK LATER

functionHeader: functionName headerParametersBlockInit headerParametersBlockEnd {
        addArgumentsToLastDefinedFunction();
        $$=$1; } ;

functionName: optionalStatic type TK_IDENTIFICADOR { 
        $$=createNode($3, $2);
        createFunctionTableEntry($3->value.valueString, yylineno, $2, $3); };

headerParametersBlockInit: '(' { stackScope(); };

headerParametersBlockEnd: headerParameters ')';

headerParameters: optionalConst type TK_IDENTIFICADOR headerParametersList {
        createVariableTableEntry($3->value.valueString, yylineno, $2, NULL);
        freeToken($3);
        $$=NULL; }
        | { $$=NULL; };
headerParametersList: ',' optionalConst type TK_IDENTIFICADOR headerParametersList {
        createVariableTableEntry($4->value.valueString, yylineno, $3, NULL);
        $$=NULL; }
        | {$$=NULL;};

commandBlockInit: '{' { stackScope(); };
commandBlockEnd: commandList '}' { $$=$1; popScope(); };

functionCommandBlockInit: '{';

commandList: command commandList {
		if($1==NULL) {
			$$=$2;
                }
		else {
		        addNext($1, $2);
		        $$=$1;
                }

}
        | {$$=NULL;};

command: variableDeclaration ';' {$$ = $1; }
        | attribution ';' {$$ = $1; }
        | inputOutput ';' {$$ = $1; }
        | functionCall ';' {$$ = $1; }
        | shift ';' {$$ = $1; }
        | executionControl ';' {$$ = $1; }      // CHECK IF TRUE
        | fluxControl {$$ = $1;}
        | commandBlockInit commandBlockEnd ';' {$$ = $2;};


attribution: TK_IDENTIFICADOR '=' expression {
        Type identifierType = getEntryTypeFromKey($1->value.valueString);
        verifyVariableUse($1->value.valueString);
        $$=createCustomLabelNode("=", yylineno, inferType(identifierType, $3->type));
        addChild($$,createNode($1, identifierType));
        addChild($$,$3); }
        | vector_identifier '=' expression {
                $$=createCustomLabelNode("=", yylineno, $1->type);
                addChild($$,$1);
                addChild($$,$3); };

inputOutput: input {$$=$1;}
        | output {$$=$1;};

output: TK_PR_OUTPUT TK_IDENTIFICADOR {
        Type identifierType = getEntryTypeFromKey($2->value.valueString);

        if(identifierType!=TYPE_INTEGER && identifierType!=TYPE_FLOAT){
                	throwWrongParOutput(yylineno);}

        $$=createCustomLabelNode("output", yylineno, identifierType);
        addChild($$,createNode($2, identifierType)); }
        | TK_PR_OUTPUT value {
                $$=createCustomLabelNode("output", yylineno, $2->type);
                addChild($$,$2); };

input: TK_PR_INPUT TK_IDENTIFICADOR {
        Type identifierType = getEntryTypeFromKey($2->value.valueString);

        if(identifierType!=TYPE_INTEGER && identifierType!=TYPE_FLOAT){
        	throwWrongParInput(yylineno);}

        $$=createCustomLabelNode("input", yylineno, identifierType);
        addChild($$,createNode($2, identifierType)); } ;


shift: TK_IDENTIFICADOR shiftOperator TK_LIT_INT {
	if($3->value.valueInt > 16){
	throwShiftError(yylineno);
	}

        addChild($2,createNode($1, getEntryTypeFromKey($1->value.valueString)));
        addChild($2,createNode($3, $3->type));
        $$=$2; }
        | vector_identifier shiftOperator positive_integer {addChild($2,$1); addChild($2,$3); $$=$2;} ;

shiftOperator: TK_OC_SL {$$=createNode($1, TYPE_UNDEFINED);}
        | TK_OC_SR {$$=createNode($1, TYPE_UNDEFINED);};

executionControl: TK_PR_RETURN expression {
        $$=createCustomLabelNode("return", yylineno, $2->type);
        addChild($$,$2); }
        | TK_PR_BREAK {$$=createCustomLabelNode("break", yylineno, TYPE_UNDEFINED);}
        | TK_PR_CONTINUE {$$=createCustomLabelNode("continue", yylineno, TYPE_UNDEFINED);};

fluxControl: conditional {$$=$1;}
        | while {$$=$1;}
        | for {$$=$1;};

conditional: TK_PR_IF '(' expression ')' commandBlockInit commandBlockEnd else {

	if($3->type==TYPE_STRING){
		throwStringToXError(NULL); }
	else if($3->type==TYPE_CHAR){
		throwCharToXError(NULL); }

	$$=createCustomLabelNode("if", yylineno, TYPE_UNDEFINED);
	addChild($$,$3);
	addChild($$,$6);
	addChild($$,$7);};

else: TK_PR_ELSE commandBlockInit commandBlockEnd {$$=createCustomLabelNode("else", yylineno, TYPE_UNDEFINED); addChild($$, $2);}
        | {$$=NULL;} ;

while: TK_PR_WHILE '(' expression ')' TK_PR_DO commandBlockInit commandBlockEnd {

	if($3->type==TYPE_STRING){
        		throwStringToXError(NULL); }
        	else if($3->type==TYPE_CHAR){
        		throwCharToXError(NULL); }

	$$=createCustomLabelNode("while", yylineno, TYPE_UNDEFINED);
	addChild($$,$3);
	addChild($$,$7); };


for: TK_PR_FOR '(' attribution  ':' expression ':' attribution ')' commandBlockInit commandBlockEnd {

	if($5->type==TYPE_STRING){
        		throwStringToXError(NULL); }
        	else if($5->type==TYPE_CHAR){
        		throwCharToXError(NULL); }

	$$=createCustomLabelNode("for", yylineno, TYPE_UNDEFINED);
	addChild($$,$3);
	addChild($$,$5);
	addChild($$,$7);
	addChild($$,$10);} ;

expression: orLogicalExpression '?' expression ':' expression {

	if($1->type==TYPE_STRING){
        	throwStringToXError(NULL); }
        else if($1->type==TYPE_CHAR){
        	throwCharToXError(NULL); }

        $$=createCustomLabelNode("?:", yylineno, inferType($3->type, $5->type)); // Verificar se sao do mesmo tipo?
        addChild($$,$1);
        addChild($$,$3); 
        addChild($$,$5); }
    | orLogicalExpression {$$=$1;};

orLogicalExpression: orLogicalExpression orLogicalOperator andLogicalExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
        | andLogicalExpression {$$=$1;};

andLogicalExpression: andLogicalExpression andLogicalOperator bitwiseOrExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
    | bitwiseOrExpression {$$=$1;};

bitwiseOrExpression: bitwiseOrExpression bitwiseOrOperator bitwiseAndExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
    | bitwiseAndExpression {$$=$1;};

bitwiseAndExpression: bitwiseAndExpression bitwiseAndOperator equalityExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1); 
        addChild($2,$3);
        $$=$2; }
    | equalityExpression {$$=$1;};

equalityExpression: equalityExpression equalityOperator comparisonExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
        | comparisonExpression {$$=$1;};
comparisonExpression: comparisonExpression comparisonOperator sumExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
        | sumExpression {$$=$1;};

sumExpression: sumExpression sumOperator multiplicationExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
        | multiplicationExpression {$$=$1;};

multiplicationExpression: multiplicationExpression multiplicationOperator powerExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
        | powerExpression {$$=$1;};
powerExpression: powerExpression powerOperator unaryExpression {
        addTypeToNode($2, inferType($1->type, $3->type));
        addChild($2,$1);
        addChild($2,$3);
        $$=$2; }
        | unaryExpression {$$=$1;};

unaryExpression: unaryOperator unaryExpression {
        verifyUnaryOperatorType($1->data->label, $2->type);
        addTypeToNode($1, $2->type);
        $$=$1;
        addChild($$, $2); }
        | operand {$$=$1;};

orLogicalOperator: TK_OC_OR {$$=createNode($1, TYPE_BOOL);};
andLogicalOperator: TK_OC_AND {$$=createNode($1, TYPE_BOOL);} ;
bitwiseOrOperator: '|' {$$=createCustomLabelNode("|", yylineno, TYPE_BOOL);};
bitwiseAndOperator: '&' {$$=createCustomLabelNode("&", yylineno, TYPE_BOOL);};
equalityOperator: TK_OC_EQ {$$=createNode($1, TYPE_BOOL);}
        | TK_OC_NE {$$=createNode($1, TYPE_BOOL);};
comparisonOperator: TK_OC_LE {$$=createNode($1, TYPE_BOOL);}
        | TK_OC_GE {$$=createNode($1, TYPE_BOOL);}
        | '<' {$$=createCustomLabelNode("<", yylineno, TYPE_BOOL);}
        | '>' {$$=createCustomLabelNode(">", yylineno, TYPE_BOOL);};


sumOperator: '+' {$$=createCustomLabelNode("+", yylineno, TYPE_UNDEFINED);};
        | '-' {$$=createCustomLabelNode("-", yylineno, TYPE_UNDEFINED);};
multiplicationOperator: '*' {$$=createCustomLabelNode("*", yylineno, TYPE_UNDEFINED);}
        | '/' {$$=createCustomLabelNode("/", yylineno, TYPE_UNDEFINED);};
        | '%' {$$=createCustomLabelNode("%", yylineno, TYPE_UNDEFINED);};
powerOperator: '^' {$$=createCustomLabelNode("^", yylineno, TYPE_UNDEFINED);};
unaryOperator: '+' {$$=createCustomLabelNode("+", yylineno, TYPE_UNDEFINED);}
        | '-' {$$=createCustomLabelNode("-", yylineno, TYPE_UNDEFINED);}
        | '!' {$$=createCustomLabelNode("!", yylineno, TYPE_UNDEFINED);}
        | '&' {$$=createCustomLabelNode("&", yylineno, TYPE_UNDEFINED);}
        | '*' {$$=createCustomLabelNode("*", yylineno, TYPE_UNDEFINED);}
        | '?' {$$=createCustomLabelNode("?", yylineno, TYPE_UNDEFINED);}
        | '#' {$$=createCustomLabelNode("#", yylineno, TYPE_UNDEFINED);} ;




variableDeclaration: optionalStatic optionalConst type variable variableDeclarationList {
	if($4==NULL) {
	        $$=$5;
        }
	else {
	        addNext($4, $5);
		$$=$4;
        }
        endVariableListDeclaration($3);
};

variable: TK_IDENTIFICADOR {
        $$=NULL;
        createVariableTableEntry($1->value.valueString, yylineno, TYPE_UNDEFINED, NULL); }
        | TK_IDENTIFICADOR TK_OC_LE value {
                createVariableTableEntry($1->value.valueString, yylineno, TYPE_UNDEFINED, NULL);
                Type identifierType = getEntryTypeFromKey($1->value.valueString);
                $$=createNode($2, identifierType); // Verificar inferencia
                addChild($$,createNode($1, identifierType));
                addChild($$,$3); }
        | TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR {
                createVariableTableEntry($1->value.valueString, yylineno, TYPE_UNDEFINED, NULL);
                Type identifierType = getEntryTypeFromKey($1->value.valueString);
                $$=createNode($2, identifierType);
                addChild($$,createNode($1, identifierType));
                addChild($$,createNode($3, getEntryTypeFromKey($3->value.valueString))); };

variableDeclarationList: ',' variable variableDeclarationList {

	if($2==NULL){
		$$=$3;	}
	else{
		$2->next = $3;
		$$=$2;	}
}
        | { $$=NULL; };


functionCall: TK_IDENTIFICADOR '(' functionParameters ')' {
        verifyFunctionUse($1->value.valueString);
        verifyFunctionCallParams($1->value.valueString, $3);
        Type identifierType = getEntryTypeFromKey($1->value.valueString);
	char str[10]="call ";

        strcat(str, $1->label);

	$$=createCustomLabelNode(str, yylineno, identifierType);

	addChild($$,$3);
} ;

functionParameters: expression functionParametersList { $$=addNext($1, $2); }
        | {$$=NULL;};

functionParametersList: ',' expression functionParametersList { $$=addNext($2, $3); }
        | {$$=NULL;};

operand: TK_IDENTIFICADOR {$$=createNode($1, getEntryTypeFromKey($1->value.valueString));}
        | vector_identifier {$$=$1;}
        | value {$$=$1;}
        | functionCall {$$=$1;}
        | '(' expression ')' {$$=$2;};

vector_identifier: TK_IDENTIFICADOR '[' expression ']' {
        Type identifierType = getEntryTypeFromKey($1->value.valueString);
        verifyVectorUse($1->value.valueString);
        $$=createCustomLabelNode("[]", yylineno, identifierType); 
        addChild($$, createNode($1, identifierType));
        addChild($$, $3); };

identifier: TK_IDENTIFICADOR {
        createVariableTableEntry($1->value.valueString, yylineno, TYPE_UNDEFINED, NULL);
        freeToken($1);
        $$=NULL; }
          | TK_IDENTIFICADOR '[' positive_integer ']' {
                  createVectorTableEntry($1->value.valueString, yylineno, TYPE_UNDEFINED, $3->data->value.valueInt, NULL);
                  freeToken($1);
                  freeAST($3); };


positive_integer: '+' TK_LIT_INT {
	createLiteralTableEntry(yylineno, TYPE_INTEGER, $2);
	$$=createNode($2, TYPE_INTEGER);}
		| TK_LIT_INT {
		createLiteralTableEntry(yylineno, TYPE_INTEGER, $1);
		$$=createNode($1, TYPE_INTEGER);};


%%

int yyerror (char const *s) {
    printf("Error on line %d: %s.\n", yylineno, s);
    return 1;
}