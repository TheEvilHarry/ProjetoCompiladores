%{
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "parserUtils.h"

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

program: globalVariable program { $$ = program_globalVariable_program($1, $2); arvore = $$; }
        | functionDefinition program {$$ = program_functionDefinition_program($1, $2); arvore = $$; }
        | {$$=program_empty(arvore);};

optionalStatic: TK_PR_STATIC  { $$ = optionalStatic_TK_PR_STATIC(NULL); }
        |  { $$ = optionalStatic_empty(); };
optionalConst: TK_PR_CONST  { $$ = optionalConst_TK_PR_CONST(NULL); }
        |  { $$ = optionalConst_empty(); };

globalVariable: optionalStatic type identifier globalVariableList ';' { 
        $$=globalVariable_optionalStatic_type_identifier_globalVariableList_semicolon($1, $2, $3, $4, NULL); };

globalVariableList: ',' identifier globalVariableList {$$=globalVariableList_comma_identifier_globalVariableList(NULL, $2, $3);}
        | { $$=globalVariableList_empty(); };

type: TK_PR_INT { $$ = type_TK_PR_INT(NULL); }
        | TK_PR_FLOAT  { $$ = type_TK_PR_FLOAT(NULL); }
        | TK_PR_CHAR  { $$ = type_TK_PR_CHAR(NULL); }
        | TK_PR_BOOL  { $$ = type_TK_PR_BOOL(NULL); }
        | TK_PR_STRING  { $$ = type_TK_PR_STRING(NULL); };

value: TK_LIT_INT { $$=value_TK_LIT_INT($1); }
        | TK_LIT_FLOAT { $$=value_TK_LIT_FLOAT($1); }
        | TK_LIT_FALSE { $$=value_TK_LIT_FALSE($1); }
        | TK_LIT_TRUE { $$=value_TK_LIT_TRUE($1); }
        | TK_LIT_CHAR { $$=value_TK_LIT_CHAR($1); }
        | TK_LIT_STRING { $$=value_TK_LIT_STRING($1); };

functionDefinition: functionHeader functionCommandBlockInit commandBlockEnd { 
        $$=functionDefinition_functionHeader_functionCommandBlockInit_commandBlockEnd($1, NULL, $3); };  //CHECK LATER

functionHeader: functionName headerParametersBlockInit headerParametersBlockEnd {
        $$=functionHeader_functionName_headerParametersBlockInit_headerParametersBlockEnd($1, NULL, NULL); } ;

functionName: optionalStatic type TK_IDENTIFICADOR { 
        $$=functionName_optionalStatic_type_TK_IDENTIFICADOR($1, $2, $3); };

headerParametersBlockInit: '(' { headerParametersBlockInit(); };

headerParametersBlockEnd: headerParameters ')';

headerParameters: optionalConst type TK_IDENTIFICADOR headerParametersList {
        $$=headerParameters_optionalConst_type_TK_IDENTIFICADOR_headerParametersList($1, $2, $3, $4); }
        | { $$=headerParameters_empty(); };
headerParametersList: ',' optionalConst type TK_IDENTIFICADOR headerParametersList {
        $$=headerParametersList_comma_optionalConst_type_TK_IDENTIFICADOR_headerParametersList(NULL, $2, $3, $4, $5); }
        | {$$=headerParametersList_empty();};

commandBlockInit: '{' { commandBlockInit(); };
commandBlockEnd: commandList '}' { $$=commandBlockEnd_commandList_closingCurlyBracket($1, NULL); };

functionCommandBlockInit: '{';

commandList: command commandList { $$=commandList_command_commandList($1, $2); }
        | {$$=commandList_empty();};

command: variableDeclaration ';' { $$ = command_variableDeclaration_semicolon($1, NULL); }
        | attribution ';' { $$ = command_attribution_semicolon($1, NULL); }
        | inputOutput ';' { $$ = command_inputOutput_semicolon($1, NULL); }
        | functionCall ';' { $$ = command_functionCall_semicolon($1, NULL); }
        | shift ';' { $$ = command_shift_semicolon($1, NULL); }
        | executionControl ';' { $$ = command_executionControl_semicolon($1, NULL); }
        | fluxControl { $$ = command_fluxControl($1);}
        | commandBlockInit commandBlockEnd ';' { $$ = command_commandBlockInit_commandBlockEnd_semicolon($1, $2, NULL);};


attribution: TK_IDENTIFICADOR '=' expression { $$=attribution_TK_IDENTIFICADOR_equalSign_expression($1, NULL, $3); }
       | vector_identifier '=' expression { $$=attribution_vectorIdentifier_equalSign_expression($1, NULL, $3); };

inputOutput: input { $$=inputOutput_input($1); }
        | output { $$=inputOutput_output($1); };

output: TK_PR_OUTPUT TK_IDENTIFICADOR { $$=output_TK_PR_OUTPUT_TK_IDENTIFICADOR($1, $2); }
        | TK_PR_OUTPUT value { $$=output_TK_PR_OUTPUT_value($1, $2); };

input: TK_PR_INPUT TK_IDENTIFICADOR { $$=input_TK_PR_INPUT_TK_IDENTIFICADOR($1, $2); } ;


shift: TK_IDENTIFICADOR shiftOperator TK_LIT_INT { $$=shift_TK_IDENTIFICADOR_shiftOperator_TK_LIT_INT($1, $2, $3); }
        | vector_identifier shiftOperator positive_integer { $$=shift_vectorIdentifier_shiftOperator_positiveInteger($1, $2, $3); };

shiftOperator: TK_OC_SL { $$=shiftOperator_TK_OC_SL($1); }
        | TK_OC_SR { $$=shiftOperator_TK_OC_SR($1); };

executionControl: TK_PR_RETURN expression { $$=executionControl_TK_PR_RETURN_expression($1, $2); }
        | TK_PR_BREAK { $$=executionControl_TK_PR_BREAK($1); }
        | TK_PR_CONTINUE { $$=executionControl_TK_PR_CONTINUE($1); };

fluxControl: conditional { $$=fluxControl_conditional($1); }
        | while { $$=fluxControl_while($1); }
        | for { $$=fluxControl_for($1); };

conditional: TK_PR_IF '(' expression ')' commandBlockInit commandBlockEnd else {
        $$=conditional_TK_PR_IF_openingParenthesis_expression_closingParenthesis_commandBlockInit_commandBlockEnd_else($1, NULL, $3, NULL, $5, $6, $7); };

else: TK_PR_ELSE commandBlockInit commandBlockEnd { $$=else_TK_PR_ELSE_commandBlockInit_commandBlockEnd($1, $2, $3); }
        | { $$=else_empty(); };

while: TK_PR_WHILE '(' expression ')' TK_PR_DO commandBlockInit commandBlockEnd { 
        $$=while_TK_PR_WHILE_openingParenthesis_expression_closingParenthesis_TK_PR_DO_commandBlockInit_commandBlockEnd($1, NULL, $3, NULL, NULL, $6, $7); };

for: TK_PR_FOR '(' attribution  ':' expression ':' attribution ')' commandBlockInit commandBlockEnd {
        $$=for_TK_PR_FOR_openingParenthesis_attribution_colon_expression_colon_attribution_closingParenthesis_commandBlockInit_commandBlockEnd($1, NULL, $3, NULL, $5, NULL, $7, NULL, $9, $10); } ;

expression: orLogicalExpression '?' expression ':' expression {
        $$=expression_orLogicalExpression_questionMark_expression_colon_expression($1, NULL, $3, NULL, $5); }
    | orLogicalExpression { $$=expression_orLogicalExpression($1); };

orLogicalExpression: orLogicalExpression orLogicalOperator andLogicalExpression {
        $$=orLogicalExpression_orLogicalExpression_orLogicalOperator_andLogicalExpression($1, $2, $3); }
        | andLogicalExpression { $$=orLogicalExpression_andLogicalExpression($1); };

andLogicalExpression: andLogicalExpression andLogicalOperator bitwiseOrExpression {
        $$=andLogicalExpression_andLogicalExpression_andLogicalOperator_bitwiseOrExpression($1, $2, $3); }
    | bitwiseOrExpression { $$=andLogicalExpression_bitwiseOrExpression($1); };

bitwiseOrExpression: bitwiseOrExpression bitwiseOrOperator bitwiseAndExpression {
        $$=bitwiseOrExpression_bitwiseOrExpression_bitwiseOrOperator_bitwiseAndExpression($1, $2, $3); }
    | bitwiseAndExpression { $$=bitwiseOrExpression_bitwiseAndExpression($1); };

bitwiseAndExpression: bitwiseAndExpression bitwiseAndOperator equalityExpression {
        $$=bitwiseAndExpression_bitwiseAndExpression_bitwiseAndOperator_equalityExpression($1, $2, $3); }
    | equalityExpression { $$=bitwiseAndExpression_equalityExpression($1); };

equalityExpression: equalityExpression equalityOperator comparisonExpression {
        $$=equalityExpression_equalityExpression_equalityOperator_comparisonExpression($1, $2, $3); }
        | comparisonExpression { $$=equalityExpression_comparisonExpression($1); };

comparisonExpression: comparisonExpression comparisonOperator sumExpression {
        $$=comparisonExpression_comparisonExpression_comparisonOperator_sumExpression($1, $2, $3); }
        | sumExpression { $$=comparisonExpression_sumExpression($1); };

sumExpression: sumExpression sumOperator multiplicationExpression {
        $$=sumExpression_sumExpression_sumOperator_multiplicationExpression($1, $2, $3); }
        | multiplicationExpression { $$=sumExpression_multiplicationExpression($1); };

multiplicationExpression: multiplicationExpression multiplicationOperator powerExpression {
        $$=multiplicationExpression_multiplicationExpression_multiplicationOperator_powerExpression($1, $2, $3); }
        | powerExpression { $$=multiplicationExpression_powerExpression($1); };

powerExpression: powerExpression powerOperator unaryExpression {
        $$=powerExpression_powerExpression_powerOperator_unaryExpression($1, $2, $3); }
        | unaryExpression { $$=powerExpression_unaryExpression($1); };

unaryExpression: unaryOperator unaryExpression {
        $$=unaryExpression_unaryOperator_unaryExpression($1, $2); }
        | operand { $$=unaryExpression_operand($1); };

orLogicalOperator: TK_OC_OR { $$=orLogicalOperator_TK_OC_OR($1); };
andLogicalOperator: TK_OC_AND { $$=andLogicalOperator_TK_OC_AND($1); };
bitwiseOrOperator: '|' { $$=bitwiseOrOperator_pipe(NULL); };
bitwiseAndOperator: '&' { $$=bitwiseAndOperator_comercialE(NULL); };

equalityOperator: TK_OC_EQ { $$=equalityOperator_TK_OC_EQ($1); }
        | TK_OC_NE { $$=equalityOperator_TK_OC_NE($1); };
comparisonOperator: TK_OC_LE { $$=comparisonOperator_TK_OC_LE($1); }
        | TK_OC_GE { $$=comparisonOperator_TK_OC_GE($1); }
        | '<' { $$=comparisonOperator_lessThan(NULL); }
        | '>' { $$=comparisonOperator_greaterThan(NULL); };


sumOperator: '+' { $$=sumOperator_plusSign(NULL); };
        | '-' { $$=sumOperator_minusSign(NULL); };
multiplicationOperator: '*' {$$=multiplicationOperator_asterisk(NULL);}
        | '/' {$$=multiplicationOperator_forwardSlash(NULL);};
        | '%' {$$=multiplicationOperator_percent(NULL);};
powerOperator: '^' {$$=powerOperator_circumflex(NULL);};
unaryOperator: '+' {$$=unaryOperator_plusSign(NULL);}
        | '-' {$$=unaryOperator_minusSign(NULL);}
        | '!' {$$=unaryOperator_exclamationMark(NULL);}
        | '&' {$$=unaryOperator_comercialE(NULL);}
        | '*' {$$=unaryOperator_asterisk(NULL);}
        | '?' {$$=unaryOperator_questionMark(NULL);}
        | '#' {$$=unaryOperator_hashtag(NULL);};




variableDeclaration: optionalStatic optionalConst type variable variableDeclarationList {
	$$= variableDeclaration_optionalStatic_optionalConst_type_variable_variableDeclarationList($1, $2, $3, $4, $5); };

variable: TK_IDENTIFICADOR { $$=variable_TK_IDENTIFICADOR($1); }
        | TK_IDENTIFICADOR TK_OC_LE value { $$=variable_TK_IDENTIFICADOR_TK_OC_LE_value($1, $2, $3); }
        | TK_IDENTIFICADOR TK_OC_LE TK_IDENTIFICADOR { $$=variable_TK_IDENTIFICADOR_TK_OC_LE_TK_IDENTIFICADOR($1, $2, $3); };

variableDeclarationList: ',' variable variableDeclarationList { $$=variableDeclarationList_comma_variable_variableDeclarationList(NULL, $2, $3); }
        | { $$=variableDeclarationList_empty(); };


functionCall: TK_IDENTIFICADOR '(' functionParameters ')' {
        $$=functionCall_TK_IDENTIFICADOR_openingParenthesis_functionParameters_closingParenthesis($1, NULL, $3, NULL); };

functionParameters: expression functionParametersList { $$=functionParameters_expression_functionParametersList($1, $2); }
        | { $$=functionParameters_empty(); };

functionParametersList: ',' expression functionParametersList { $$=functionParametersList_comma_expression_functionParametersList(NULL, $2, $3); }
        | { $$=functionParametersList_empty(); };

operand: TK_IDENTIFICADOR { $$=operand_TK_IDENTIFICADOR($1); }
        | vector_identifier { $$=operand_vectorIdentifier($1); }
        | value {$$=operand_value($1);}
        | functionCall { $$=operand_functionCall($1); }
        | '(' expression ')' { $$=operand_openingParenthesis_expression_closingParenthesis(NULL, $2, NULL); };

vector_identifier: TK_IDENTIFICADOR '[' expression ']' { $$=vectorIdentifier_TK_IDENTIFICADOR_openingBracket_expression_closingBracket($1, NULL, $3, NULL); };

identifier: TK_IDENTIFICADOR { $$=identifier_TK_IDENTIFICADOR($1); }
          | TK_IDENTIFICADOR '[' positive_integer ']' { $$=identifier_TK_IDENTIFICADOR_openingBracket_positiveInteger_closingBracket($1, NULL, $3, NULL); };


positive_integer: '+' TK_LIT_INT { $$=positiveInteger_plusSign_TK_LIT_INT(NULL, $2); }
		| TK_LIT_INT { $$=positiveInteger_TK_LIT_INT($1); };


%%

int yyerror (char const *s) {
    printf("Error on line %d: %s.\n", yylineno, s);
    return 1;
}