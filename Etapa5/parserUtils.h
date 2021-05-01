#include "ilocfunctions.h"

extern int get_line_number(void);

Node *program_globalVariable_program(Node *globalVariable, Node *program);
Node *program_functionDefinition_program(Node *functionDefinition, Node *program);
Node *program_empty(Node *tree);

Node *optionalStatic_TK_PR_STATIC(TokenData *p_TK_PR_STATIC);
Node *optionalStatic_empty();

Node *optionalConst_TK_PR_CONST(TokenData *p_TK_PR_CONST);
Node *optionalConst_empty();

Node *globalVariable_optionalStatic_type_identifier_globalVariableList_semicolon(Node *optionalStatic, Type type, Node *identifier, Node *globalVariableList, void *semicolon);

Node *globalVariableList_comma_identifier_globalVariableList(void *comma, Node *identifier, Node *globalVariableList);
Node *globalVariableList_empty();

Type type_TK_PR_INT(void *p_TK_PR_INT);
Type type_TK_PR_FLOAT(void *p_TK_PR_FLOAT);
Type type_TK_PR_CHAR(void *p_TK_PR_CHAR);
Type type_TK_PR_BOOL(void *p_TK_PR_BOOL);
Type type_TK_PR_STRING(void *p_TK_PR_STRING);

Node *value_TK_LIT_INT(TokenData *p_TK_LIT_INT);
Node *value_TK_LIT_FLOAT(TokenData *p_TK_LIT_FLOAT);
Node *value_TK_LIT_FALSE(TokenData *p_TK_LIT_FALSE);
Node *value_TK_LIT_TRUE(TokenData *p_TK_LIT_TRUE);
Node *value_TK_LIT_CHAR(TokenData *p_TK_LIT_CHAR);
Node *value_TK_LIT_STRING(TokenData *p_TK_LIT_STRING);

Node *functionDefinition_functionHeader_functionCommandBlockInit_commandBlockEnd(Node *functionHeader, void *functionCommandBlockInit, Node *commandBlockEnd);

Node *functionHeader_functionName_headerParametersBlockInit_headerParametersBlockEnd(Node *functionName, void *headerParametersBlockInit, void *headerParametersBlockEnd);

Node *functionName_optionalStatic_type_TK_IDENTIFICADOR(Node *optionalStatic, Type type, TokenData *p_TK_IDENTIFICADOR);

void headerParametersBlockInit();

Node *headerParameters_optionalConst_type_TK_IDENTIFICADOR_headerParametersList(Node *optionalConst, Type type, TokenData *p_TK_IDENTIFICADOR, Node *headerParametersList);
Node *headerParameters_empty();

Node *headerParametersList_comma_optionalConst_type_TK_IDENTIFICADOR_headerParametersList(void *comma, Node *optionalConst, Type type, TokenData *p_TK_IDENTIFICADOR, Node *headerParametersList);
Node *headerParametersList_empty();

void commandBlockInit();

Node *commandBlockEnd_commandList_closingCurlyBracket(Node *commandList, void *closingCurlyBracket);

Node *commandList_command_commandList(Node *command, Node *commandList);
Node *commandList_empty();

Node *command_variableDeclaration_semicolon(Node *variableDeclaration, void *semicolon);
Node *command_attribution_semicolon(Node *attribution, void *semicolon);
Node *command_inputOutput_semicolon(Node *inputOutput, void *semicolon);
Node *command_functionCall_semicolon(Node *functionCall, void *semicolon);
Node *command_shift_semicolon(Node *shift, void *semicolon);
Node *command_executionControl_semicolon(Node *executionControl, void *semicolon); // CHECK IF TRUE
Node *command_fluxControl(Node *fluxControl);
Node *command_commandBlockInit_commandBlockEnd_semicolon(void *commandBlockInit, Node *commandBlockEnd, void *semicolon);

Node *attribution_TK_IDENTIFICADOR_equalSign_expression(TokenData *p_TK_IDENTIFICADOR, void *equalSign, Node *expression);
Node *attribution_vectorIdentifier_equalSign_expression(Node *vectorIdentifier, void *equalSign, Node *expression);

Node *inputOutput_input(Node *input);
Node *inputOutput_output(Node *output);

Node *output_TK_PR_OUTPUT_TK_IDENTIFICADOR(TokenData *p_TK_PR_OUTPUT, TokenData *p_TK_IDENTIFICADOR);
Node *output_TK_PR_OUTPUT_value(TokenData *p_TK_PR_OUTPUT, Node *value);

Node *input_TK_PR_INPUT_TK_IDENTIFICADOR(TokenData *p_TK_PR_INPUT, TokenData *p_TK_IDENTIFICADOR);

Node *shift_TK_IDENTIFICADOR_shiftOperator_TK_LIT_INT(TokenData *TK_IDENTIFICADOR, Node *shiftOperator, TokenData *p_TK_LIT_INT);
Node *shift_vectorIdentifier_shiftOperator_positiveInteger(Node *vectorIdentifier, Node *shiftOperator, Node *positiveInteger);

Node *shiftOperator_TK_OC_SL(TokenData *p_TK_OC_SL);
Node *shiftOperator_TK_OC_SR(TokenData *p_TK_OC_SR);

Node *executionControl_TK_PR_RETURN_expression(TokenData *p_TK_PR_RETURN, Node *expression);
Node *executionControl_TK_PR_BREAK(TokenData *p_TK_PR_BREAK);
Node *executionControl_TK_PR_CONTINUE(TokenData *p_TK_PR_CONTINUE);

Node *fluxControl_conditional(Node *conditional);
Node *fluxControl_while(Node *p_while);
Node *fluxControl_for(Node *p_for);

Node *conditional_TK_PR_IF_openingParenthesis_expression_closingParenthesis_commandBlockInit_commandBlockEnd_else(TokenData *p_TK_PR_IF, void *openingParenthesis, Node *expression, void *closingParenthesis, Node *commandBlockInit, Node *commandBlockEnd, Node *p_else);

Node *else_TK_PR_ELSE_commandBlockInit_commandBlockEnd(TokenData *p_TK_PR_ELSE, Node *commandBlockInit, Node *commandBlockEnd);
Node *else_empty();

Node *while_TK_PR_WHILE_openingParenthesis_expression_closingParenthesis_TK_PR_DO_commandBlockInit_commandBlockEnd(TokenData *p_TK_PR_WHILE, void *openingParenthesis, Node *expression, void *closingParenthesis, TokenData *p_TK_PR_DO, Node *commandBlockInit, Node *commandBlockEnd);

Node *for_TK_PR_FOR_openingParenthesis_attribution_colon_expression_colon_attribution_closingParenthesis_commandBlockInit_commandBlockEnd(
    TokenData *p_TK_PR_FOR,
    void *openingParenthesis,
    Node *firstAttribution,
    void *firstColon,
    Node *expression,
    void *secondColon,
    Node *secondAttribution,
    void *closingParenthesis,
    Node *commandBlockInit,
    Node *commandBlockEnd);

Node *expression_orLogicalExpression_questionMark_expression_colon_expression(
    Node *orLogicalExpression,
    void *questionMark,
    Node *firstExpression,
    void *colon,
    Node *secondExpression);
Node *expression_orLogicalExpression(Node *orLogicalExpression);

Node *orLogicalExpression_orLogicalExpression_orLogicalOperator_andLogicalExpression(Node *orLogicalExpression, Node *orLogicalOperator, Node *andLogicalExpression);
Node *orLogicalExpression_andLogicalExpression(Node *andLogicalExpression);

Node *andLogicalExpression_andLogicalExpression_andLogicalOperator_bitwiseOrExpression(Node *andLogicalExpression, Node *andLogicalOperator, Node *bitwiseOrExpression);
Node *andLogicalExpression_bitwiseOrExpression(Node *bitwiseOrExpression);

Node *bitwiseOrExpression_bitwiseOrExpression_bitwiseOrOperator_bitwiseAndExpression(Node *bitwiseOrExpression, Node *bitwiseOrOperator, Node *bitwiseAndExpression);
Node *bitwiseOrExpression_bitwiseAndExpression(Node *bitwiseAndExpression);

Node *bitwiseAndExpression_bitwiseAndExpression_bitwiseAndOperator_equalityExpression(Node *bitwiseAndExpression, Node *bitwiseAndOperator, Node *equalityExpression);
Node *bitwiseAndExpression_equalityExpression(Node *equalityExpression);

Node *equalityExpression_equalityExpression_equalityOperator_comparisonExpression(Node *equalityExpression, Node *equalityOperator, Node *comparisonExpression);
Node *equalityExpression_comparisonExpression(Node *comparisonExpression);

Node *comparisonExpression_comparisonExpression_comparisonOperator_sumExpression(Node *comparisonExpression, Node *comparisonOperator, Node *sumExpression);
Node *comparisonExpression_sumExpression(Node *sumExpression);

Node *sumExpression_sumExpression_sumOperator_multiplicationExpression(Node *sumExpression, Node *sumOperator, Node *multiplicationExpression);
Node *sumExpression_multiplicationExpression(Node *multiplicationExpression);

Node *multiplicationExpression_multiplicationExpression_multiplicationOperator_powerExpression(Node *multiplicationExpression, Node *multiplicationOperator, Node *powerExpression);
Node *multiplicationExpression_powerExpression(Node *powerExpression);

Node *powerExpression_powerExpression_powerOperator_unaryExpression(Node *powerExpression, Node *powerOperator, Node *unaryExpression);
Node *powerExpression_unaryExpression(Node *unaryExpression);

Node *unaryExpression_unaryOperator_unaryExpression(Node *unaryOperator, Node *unaryExpression);
Node *unaryExpression_operand(Node *operand);

Node *orLogicalOperator_TK_OC_OR(TokenData *p_TK_OC_OR);

Node *andLogicalOperator_TK_OC_AND(TokenData *p_TK_OC_AND);

Node *bitwiseOrOperator_pipe(void *pipe);

Node *bitwiseAndOperator_comercialE(void *comercialE);

Node *equalityOperator_TK_OC_EQ(TokenData *p_TK_OC_EQ);
Node *equalityOperator_TK_OC_NE(TokenData *p_TK_OC_NE);

Node *comparisonOperator_TK_OC_LE(TokenData *p_TK_OC_LE);
Node *comparisonOperator_TK_OC_GE(TokenData *p_TK_OC_GE);
Node *comparisonOperator_lessThan(void *lessThan);
Node *comparisonOperator_greaterThan(void *greaterThan);

Node *sumOperator_plusSign(void *plusSign);
Node *sumOperator_minusSign(void *minusSign);

Node *multiplicationOperator_asterisk(void *asterisk);
Node *multiplicationOperator_forwardSlash(void *forwardSlash);
Node *multiplicationOperator_percent(void *percent);

Node *powerOperator_circumflex(void *circumflex);

Node *unaryOperator_plusSign(void *plusSign);
Node *unaryOperator_minusSign(void *minusSign);
Node *unaryOperator_exclamationMark(void *exclamationMark);
Node *unaryOperator_comercialE(void *comercialE);
Node *unaryOperator_asterisk(void *asterisk);
Node *unaryOperator_questionMark(void *questionMark);
Node *unaryOperator_hashtag(void *hashtag);

Node *variableDeclaration_optionalStatic_optionalConst_type_variable_variableDeclarationList(
    Node *optionalStatic,
    Node *optionalConst,
    Type type,
    Node *variable,
    Node *variableDeclarationList);

Node *variable_TK_IDENTIFICADOR(TokenData *p_TK_IDENTIFICADOR);
Node *variable_TK_IDENTIFICADOR_TK_OC_LE_value(TokenData *p_TK_IDENTIFICADOR, TokenData *p_TK_OC_LE, Node *value);
Node *variable_TK_IDENTIFICADOR_TK_OC_LE_TK_IDENTIFICADOR(TokenData *first_TK_IDENTIFICADOR, TokenData *p_TK_OC_LE, TokenData *second_TK_IDENTIFICADOR);

Node *variableDeclarationList_comma_variable_variableDeclarationList(void *comma, Node *variable, Node *variableDeclarationList);
Node *variableDeclarationList_empty();

Node *functionCall_TK_IDENTIFICADOR_openingParenthesis_functionParameters_closingParenthesis(
    TokenData *p_TK_IDENTIFICADOR,
    void *openingParenthesis,
    Node *functionParameters,
    void *closingParenthesis);

Node *functionParameters_expression_functionParametersList(Node *expression, Node *functionParametersList);
Node *functionParameters_empty();

Node *functionParametersList_comma_expression_functionParametersList(void *comma, Node *expression, Node *functionParametersList);
Node *functionParametersList_empty();

Node *operand_TK_IDENTIFICADOR(TokenData *p_TK_IDENTIFICADOR);
Node *operand_vectorIdentifier(Node *vectorIdentifier);
Node *operand_value(Node *value);
Node *operand_functionCall(Node *functionCall);
Node *operand_openingParenthesis_expression_closingParenthesis(void *openingParenthesis, Node *expression, void *closingParenthesis);

Node *vectorIdentifier_TK_IDENTIFICADOR_openingBracket_expression_closingBracket(TokenData *p_TK_IDENTIFICADOR, void *openingBracket, Node *expression, void *closingBracket);

Node *identifier_TK_IDENTIFICADOR(TokenData *p_TK_IDENTIFICADOR);
Node *identifier_TK_IDENTIFICADOR_openingBracket_positiveInteger_closingBracket(TokenData *p_TK_IDENTIFICADOR, void *openingBracket, Node *positiveInteger, void *closingBracket);

Node *positiveInteger_plusSign_TK_LIT_INT(void *plusSign, TokenData *p_TK_LIT_INT);
Node *positiveInteger_TK_LIT_INT(TokenData *p_TK_LIT_INT);