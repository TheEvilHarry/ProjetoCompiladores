#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parserUtils.h"

Type currentFunctionReturn = TYPE_UNDEFINED;

Node *program_globalVariable_program(Node *globalVariable, Node *program)
{
  return program;
}
Node *program_functionDefinition_program(Node *functionDefinition, Node *program)
{
  addNext(functionDefinition, program);

  if (program != NULL)
  {
    addCodeToNode(functionDefinition, joinCodes(functionDefinition->code, program->code));
  }

  return functionDefinition;
}
Node *program_empty(Node *tree)
{
  return tree;
}

Node *optionalStatic_TK_PR_STATIC(TokenData *p_TK_PR_STATIC)
{
  createNode(p_TK_PR_STATIC, TYPE_UNDEFINED);
  return NULL;
}
Node *optionalStatic_empty() { return NULL; }

Node *optionalConst_TK_PR_CONST(TokenData *p_TK_PR_CONST)
{
  return NULL;
}
Node *optionalConst_empty()
{
  return NULL;
}

Node *globalVariable_optionalStatic_type_identifier_globalVariableList_semicolon(
    Node *optionalStatic,
    Type type,
    Node *identifier,
    Node *globalVariableList,
    void *semicolon)
{
  endVariableListDeclaration(type);
  return NULL;
}

Node *globalVariableList_comma_identifier_globalVariableList(
    void *comma,
    Node *identifier,
    Node *globalVariableList)
{
  return NULL;
}
Node *globalVariableList_empty()
{
  return NULL;
}

Type type_TK_PR_INT(void *p_TK_PR_INT) { return TYPE_INTEGER; }
Type type_TK_PR_FLOAT(void *p_TK_PR_FLOAT) { return TYPE_FLOAT; }
Type type_TK_PR_CHAR(void *p_TK_PR_CHAR) { return TYPE_CHAR; }
Type type_TK_PR_BOOL(void *p_TK_PR_BOOL) { return TYPE_BOOL; }
Type type_TK_PR_STRING(void *p_TK_PR_STRING) { return TYPE_STRING; }

Node *value_TK_LIT_INT(TokenData *p_TK_LIT_INT)
{
  createLiteralTableEntry(get_line_number(), TYPE_INTEGER, p_TK_LIT_INT);
  Node *node = createNode(p_TK_LIT_INT, TYPE_INTEGER);
  char *literalRegister = generateRegisterName();
  char literalValue[16];
  sprintf(literalValue, "%d", p_TK_LIT_INT->value.valueInt);
  Code *code = createCode(LOADI, literalRegister, literalValue, NULL, NULL, literalRegister, NULL, NULL);
  addCodeToNode(node, code);
  addToGlobalNodeList(node);
  // addToGlobalCodeList(code);

  return node;
}
Node *value_TK_LIT_FLOAT(TokenData *p_TK_LIT_FLOAT)
{
  createLiteralTableEntry(get_line_number(), TYPE_FLOAT, p_TK_LIT_FLOAT);
  return createNode(p_TK_LIT_FLOAT, TYPE_FLOAT);
}
Node *value_TK_LIT_FALSE(TokenData *p_TK_LIT_FALSE)
{
  createLiteralTableEntry(get_line_number(), TYPE_BOOL, p_TK_LIT_FALSE);
  return createNode(p_TK_LIT_FALSE, TYPE_BOOL);
}
Node *value_TK_LIT_TRUE(TokenData *p_TK_LIT_TRUE)
{
  createLiteralTableEntry(get_line_number(), TYPE_BOOL, p_TK_LIT_TRUE);
  return createNode(p_TK_LIT_TRUE, TYPE_BOOL);
}
Node *value_TK_LIT_CHAR(TokenData *p_TK_LIT_CHAR)
{
  createLiteralTableEntry(get_line_number(), TYPE_CHAR, p_TK_LIT_CHAR);
  return createNode(p_TK_LIT_CHAR, TYPE_CHAR);
}
Node *value_TK_LIT_STRING(TokenData *p_TK_LIT_STRING)
{
  createLiteralTableEntry(get_line_number(), TYPE_STRING, p_TK_LIT_STRING);
  return createNode(p_TK_LIT_STRING, TYPE_STRING);
}

Node *functionDefinition_functionHeader_functionCommandBlockInit_commandBlockEnd(Node *functionHeader, void *functionCommandBlockInit, Node *commandBlockEnd)
{
  Node *node = addChild(functionHeader, commandBlockEnd);
  addCodeToNode(node, generateFunctionCode(functionHeader, functionHeader->data->value.valueString, commandBlockEnd));
  addToGlobalNodeList(node);
  return node;
}

Node *functionHeader_functionName_headerParametersBlockInit_headerParametersBlockEnd(Node *functionName, void *headerParametersBlockInit, void *headerParametersBlockEnd)
{
  addArgumentsToLastDefinedFunction();
  return functionName;
}

Node *functionName_optionalStatic_type_TK_IDENTIFICADOR(Node *optionalStatic, Type type, TokenData *p_TK_IDENTIFICADOR)
{
  currentFunctionReturn = type;
  Node *node = createNode(p_TK_IDENTIFICADOR, type);
  createFunctionTableEntry(p_TK_IDENTIFICADOR->value.valueString, get_line_number(), type, p_TK_IDENTIFICADOR);
  updateCurrentFunction(p_TK_IDENTIFICADOR->value.valueString);
  return node;
}

void headerParametersBlockInit() { stackScope(); }

Node *headerParameters_optionalConst_type_TK_IDENTIFICADOR_headerParametersList(Node *optionalConst, Type type, TokenData *p_TK_IDENTIFICADOR, Node *headerParametersList)
{
  createVariableTableEntry(p_TK_IDENTIFICADOR->value.valueString, get_line_number(), type, NULL);
  freeToken(p_TK_IDENTIFICADOR);
  return NULL;
}
Node *headerParameters_empty() { return NULL; }

Node *headerParametersList_comma_optionalConst_type_TK_IDENTIFICADOR_headerParametersList(void *comma, Node *optionalConst, Type type, TokenData *p_TK_IDENTIFICADOR, Node *headerParametersList)
{
  createVariableTableEntry(p_TK_IDENTIFICADOR->value.valueString, get_line_number(), type, NULL);
  freeToken(p_TK_IDENTIFICADOR);
  return NULL;
}
Node *headerParametersList_empty() { return NULL; }

void commandBlockInit()
{

  stackScope();
}

Node *commandBlockEnd_commandList_closingCurlyBracket(Node *commandList, void *closingCurlyBracket)
{
  popScope();

  return commandList;
}

Node *commandList_command_commandList(Node *command, Node *commandList)
{
  if (command == NULL)
  {
    return commandList;
  }
  else
  {
    addNext(command, commandList);
    if (commandList != NULL)
      command->code = joinCodes(command->code, commandList->code);
    return command;
  }
}
Node *commandList_empty() { return NULL; }

Node *command_variableDeclaration_semicolon(Node *variableDeclaration, void *semicolon) { return variableDeclaration; }
Node *command_attribution_semicolon(Node *attribution, void *semicolon) { return attribution; }
Node *command_inputOutput_semicolon(Node *inputOutput, void *semicolon) { return inputOutput; }
Node *command_functionCall_semicolon(Node *functionCall, void *semicolon) { return functionCall; }
Node *command_shift_semicolon(Node *shift, void *semicolon) { return shift; }
Node *command_executionControl_semicolon(Node *executionControl, void *semicolon) { return executionControl; } // CHECK IF TRUE
Node *command_fluxControl(Node *fluxControl) { return fluxControl; }
Node *command_commandBlockInit_commandBlockEnd_semicolon(void *commandBlockInit, Node *commandBlockEnd, void *semicolon) { return commandBlockEnd; }

Node *attribution_TK_IDENTIFICADOR_equalSign_expression(TokenData *p_TK_IDENTIFICADOR, void *equalSign, Node *expression)
{
  Type identifierType = getEntryTypeFromKey(p_TK_IDENTIFICADOR->value.valueString);
  verifyVariableUse(p_TK_IDENTIFICADOR->value.valueString);

  SymbolTableEntry *identifier = findEntryInStack(getGlobalStack(), p_TK_IDENTIFICADOR->value.valueString);
  if (identifier != NULL)
  {

    if (isNodeLiteralAndString(expression) == 1 && identifier->type == TYPE_STRING)
    {
      int newSize = strlen(expression->data->value.valueString);
      if (identifier->size < newSize)
      {
        throwStringSizeError(p_TK_IDENTIFICADOR->value.valueString, get_line_number());
      }
    }
  }

  Node *node = createCustomLabelNode("=", get_line_number(), inferType(identifierType, expression->type));

  addChild(node, createNode(p_TK_IDENTIFICADOR, identifierType));
  addChild(node, expression);
  addToGlobalNodeList(addCodeToNode(node, generateAttributionCode(p_TK_IDENTIFICADOR, expression)));
  return node;
}
Node *attribution_vectorIdentifier_equalSign_expression(Node *vectorIdentifier, void *equalSign, Node *expression)
{
  Node *node = createCustomLabelNode("=", get_line_number(), vectorIdentifier->type);

  addChild(node, vectorIdentifier);
  addChild(node, expression);
  return node;
}

Node *inputOutput_input(Node *input) { return input; }
Node *inputOutput_output(Node *output) { return output; }

Node *output_TK_PR_OUTPUT_TK_IDENTIFICADOR(TokenData *p_TK_PR_OUTPUT, TokenData *p_TK_IDENTIFICADOR)
{
  Type identifierType = getEntryTypeFromKey(p_TK_IDENTIFICADOR->value.valueString);

  if (identifierType != TYPE_INTEGER && identifierType != TYPE_FLOAT)
  {
    throwWrongParOutput(get_line_number());
  }

  return addChild(createCustomLabelNode("output", get_line_number(), identifierType), createNode(p_TK_IDENTIFICADOR, identifierType));
}
Node *output_TK_PR_OUTPUT_value(TokenData *p_TK_PR_OUTPUT, Node *value)
{
  return addChild(createCustomLabelNode("output", get_line_number(), value->type), value);
}

Node *input_TK_PR_INPUT_TK_IDENTIFICADOR(TokenData *p_TK_PR_INPUT, TokenData *p_TK_IDENTIFICADOR)
{
  Type identifierType = getEntryTypeFromKey(p_TK_IDENTIFICADOR->value.valueString);

  if (identifierType != TYPE_INTEGER && identifierType != TYPE_FLOAT)
  {
    throwWrongParInput(get_line_number());
  }

  return addChild(createCustomLabelNode("input", get_line_number(), identifierType), createNode(p_TK_IDENTIFICADOR, identifierType));
}

Node *shift_TK_IDENTIFICADOR_shiftOperator_TK_LIT_INT(TokenData *TK_IDENTIFICADOR, Node *shiftOperator, TokenData *p_TK_LIT_INT)
{
  if (p_TK_LIT_INT->value.valueInt > 16)
  {
    throwShiftError(get_line_number());
  }

  addChild(shiftOperator, createNode(TK_IDENTIFICADOR, getEntryTypeFromKey(TK_IDENTIFICADOR->value.valueString)));
  addChild(shiftOperator, createNode(p_TK_LIT_INT, p_TK_LIT_INT->type));
  return shiftOperator;
}
Node *shift_vectorIdentifier_shiftOperator_positiveInteger(Node *vectorIdentifier, Node *shiftOperator, Node *positiveInteger)
{
  addChild(shiftOperator, vectorIdentifier);
  addChild(shiftOperator, positiveInteger);
  return shiftOperator;
}

Node *shiftOperator_TK_OC_SL(TokenData *p_TK_OC_SL) { return createNode(p_TK_OC_SL, TYPE_UNDEFINED); }
Node *shiftOperator_TK_OC_SR(TokenData *p_TK_OC_SR) { return createNode(p_TK_OC_SR, TYPE_UNDEFINED); }

Node *executionControl_TK_PR_RETURN_expression(TokenData *p_TK_PR_RETURN, Node *expression)
{
  if (allowsImplicitConversion(currentFunctionReturn, expression->type) == 0)
  {
    throwReturnError(get_line_number());
  }

  Node *node = addChild(createCustomLabelNode("return", get_line_number(), expression->type), expression);

  addToGlobalNodeList(addCodeToNode(node, generateReturnCode(node->children[0])));

  return node;
}
Node *executionControl_TK_PR_BREAK(TokenData *p_TK_PR_BREAK) { return createCustomLabelNode("break", get_line_number(), TYPE_UNDEFINED); }
Node *executionControl_TK_PR_CONTINUE(TokenData *p_TK_PR_CONTINUE) { return createCustomLabelNode("continue", get_line_number(), TYPE_UNDEFINED); }

Node *fluxControl_conditional(Node *conditional) { return conditional; }
Node *fluxControl_while(Node *p_while) { return p_while; }
Node *fluxControl_for(Node *p_for) { return p_for; }

Node *conditional_TK_PR_IF_openingParenthesis_expression_closingParenthesis_commandBlockInit_commandBlockEnd_else(
    TokenData *p_TK_PR_IF,
    void *openingParenthesis,
    Node *expression,
    void *closingParenthesis,
    Node *commandBlockInit,
    Node *commandBlockEnd,
    Node *p_else)
{
  if (expression->type == TYPE_STRING)
  {
    throwStringToXError(NULL);
  }
  else if (expression->type == TYPE_CHAR)
  {
    throwCharToXError(NULL);
  }

  Node *node = createCustomLabelNode("if", get_line_number(), TYPE_UNDEFINED);

  addChild(node, expression);
  addChild(node, commandBlockEnd);
  addChild(node, p_else);
  addCodeToNode(node, generateIfCode(expression, commandBlockEnd, p_else));

  return node;
}

Node *else_TK_PR_ELSE_commandBlockInit_commandBlockEnd(TokenData *p_TK_PR_ELSE, Node *commandBlockInit, Node *commandBlockEnd)
{
  return addCodeToNode(addChild(createCustomLabelNode("else", get_line_number(), TYPE_UNDEFINED), commandBlockEnd), commandBlockEnd->code);
}

Node *else_empty() { return NULL; }

Node *while_TK_PR_WHILE_openingParenthesis_expression_closingParenthesis_TK_PR_DO_commandBlockInit_commandBlockEnd(
    TokenData *p_TK_PR_WHILE,
    void *openingParenthesis,
    Node *expression,
    void *closingParenthesis,
    TokenData *p_TK_PR_DO,
    Node *commandBlockInit,
    Node *commandBlockEnd)
{

  if (expression->type == TYPE_STRING)
  {
    throwStringToXError(NULL);
  }
  else if (expression->type == TYPE_CHAR)
  {
    throwCharToXError(NULL);
  }

  Node *node = createCustomLabelNode("while", get_line_number(), TYPE_UNDEFINED);

  addChild(node, expression);
  addChild(node, commandBlockEnd);

  Code *code = generateWhileCode(expression, commandBlockEnd);

  addCodeToNode(node, code);

  addToGlobalNodeList(node);

  return node;
}

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
    Node *commandBlockEnd)
{

  if (expression->type == TYPE_STRING)
  {
    throwStringToXError(NULL);
  }
  else if (expression->type == TYPE_CHAR)
  {
    throwCharToXError(NULL);
  }

  Node *node = createCustomLabelNode("for", get_line_number(), TYPE_UNDEFINED);

  addChild(node, firstAttribution);
  addChild(node, expression);
  addChild(node, secondAttribution);
  addChild(node, commandBlockEnd);
  Code *code = generateForCode(firstAttribution, expression, secondAttribution, commandBlockEnd);
  node->code = code;

  return node;
}

Node *expression_orLogicalExpression_questionMark_expression_colon_expression(
    Node *orLogicalExpression,
    void *questionMark,
    Node *firstExpression,
    void *colon,
    Node *secondExpression)
{
  if (orLogicalExpression->type == TYPE_STRING)
  {
    throwStringToXError(NULL);
  }
  else if (orLogicalExpression->type == TYPE_CHAR)
  {
    throwCharToXError(NULL);
  }

  Node *node = createCustomLabelNode("?:", get_line_number(), inferType(firstExpression->type, secondExpression->type)); // Verificar se sao do mesmo tipo?
  addChild(node, orLogicalExpression);
  addChild(node, firstExpression);
  addChild(node, secondExpression);

  // addCodeToNode(node, generateTernaryCode(orLogicalExpression, firstExpression, secondExpression));

  return node;
}
Node *expression_orLogicalExpression(Node *orLogicalExpression) { return orLogicalExpression; }

Node *orLogicalExpression_orLogicalExpression_orLogicalOperator_andLogicalExpression(Node *orLogicalExpression, Node *orLogicalOperator, Node *andLogicalExpression)
{
  addTypeToNode(orLogicalOperator, inferType(orLogicalExpression->type, andLogicalExpression->type));
  addChild(orLogicalOperator, orLogicalExpression);
  addChild(orLogicalOperator, andLogicalExpression);

  Code *code = generateBinaryExpression(orLogicalOperator->data->value.valueString, orLogicalOperator, orLogicalExpression, andLogicalExpression);
  addCodeToNode(orLogicalOperator, code);

  return orLogicalOperator;
}
Node *orLogicalExpression_andLogicalExpression(Node *andLogicalExpression) { return andLogicalExpression; }

Node *andLogicalExpression_andLogicalExpression_andLogicalOperator_bitwiseOrExpression(Node *andLogicalExpression, Node *andLogicalOperator, Node *bitwiseOrExpression)
{
  addTypeToNode(andLogicalOperator, inferType(andLogicalExpression->type, bitwiseOrExpression->type));
  addChild(andLogicalOperator, andLogicalExpression);
  addChild(andLogicalOperator, bitwiseOrExpression);

  Code *code = generateBinaryExpression(andLogicalOperator->data->value.valueString, andLogicalOperator, andLogicalExpression, bitwiseOrExpression);
  addCodeToNode(andLogicalOperator, code);

  return andLogicalOperator;
}
Node *andLogicalExpression_bitwiseOrExpression(Node *bitwiseOrExpression) { return bitwiseOrExpression; }

Node *bitwiseOrExpression_bitwiseOrExpression_bitwiseOrOperator_bitwiseAndExpression(Node *bitwiseOrExpression, Node *bitwiseOrOperator, Node *bitwiseAndExpression)
{
  addTypeToNode(bitwiseOrOperator, inferType(bitwiseOrExpression->type, bitwiseAndExpression->type));
  addChild(bitwiseOrOperator, bitwiseOrExpression);
  addChild(bitwiseOrOperator, bitwiseAndExpression);

  return bitwiseOrOperator;
}
Node *bitwiseOrExpression_bitwiseAndExpression(Node *bitwiseAndExpression) { return bitwiseAndExpression; }

Node *bitwiseAndExpression_bitwiseAndExpression_bitwiseAndOperator_equalityExpression(Node *bitwiseAndExpression, Node *bitwiseAndOperator, Node *equalityExpression)
{
  addTypeToNode(bitwiseAndOperator, inferType(bitwiseAndExpression->type, equalityExpression->type));
  addChild(bitwiseAndOperator, bitwiseAndExpression);
  addChild(bitwiseAndOperator, equalityExpression);

  return bitwiseAndOperator;
}
Node *bitwiseAndExpression_equalityExpression(Node *equalityExpression) { return equalityExpression; }

Node *equalityExpression_equalityExpression_equalityOperator_comparisonExpression(Node *equalityExpression, Node *equalityOperator, Node *comparisonExpression)
{
  addTypeToNode(equalityOperator, inferType(equalityExpression->type, comparisonExpression->type));
  addChild(equalityOperator, equalityExpression);
  addChild(equalityOperator, comparisonExpression);

  Code *code = generateBinaryExpression(equalityOperator->data->value.valueString, equalityOperator, equalityExpression, comparisonExpression);
  addCodeToNode(equalityOperator, code);

  return equalityOperator;
}
Node *equalityExpression_comparisonExpression(Node *comparisonExpression) { return comparisonExpression; }

Node *comparisonExpression_comparisonExpression_comparisonOperator_sumExpression(Node *comparisonExpression, Node *comparisonOperator, Node *sumExpression)
{
  addTypeToNode(comparisonOperator, inferType(comparisonExpression->type, sumExpression->type));
  addChild(comparisonOperator, comparisonExpression);
  addChild(comparisonOperator, sumExpression);

  Code *code = generateBinaryExpression(comparisonOperator->data->value.valueString, comparisonOperator, comparisonExpression, sumExpression);
  addCodeToNode(comparisonOperator, code);

  return comparisonOperator;
}
Node *comparisonExpression_sumExpression(Node *sumExpression) { return sumExpression; }

Node *sumExpression_sumExpression_sumOperator_multiplicationExpression(Node *sumExpression, Node *sumOperator, Node *multiplicationExpression)
{
  addTypeToNode(sumOperator, inferType(sumExpression->type, multiplicationExpression->type));
  addChild(sumOperator, sumExpression);
  addChild(sumOperator, multiplicationExpression);

  Code *code = generateBinaryExpression(sumOperator->data->value.valueString, sumOperator, sumExpression, multiplicationExpression);
  addCodeToNode(sumOperator, code);

  return sumOperator;
}
Node *sumExpression_multiplicationExpression(Node *multiplicationExpression) { return multiplicationExpression; }

Node *multiplicationExpression_multiplicationExpression_multiplicationOperator_powerExpression(Node *multiplicationExpression, Node *multiplicationOperator, Node *powerExpression)
{
  addTypeToNode(multiplicationOperator, inferType(multiplicationExpression->type, powerExpression->type));
  addChild(multiplicationOperator, multiplicationExpression);
  addChild(multiplicationOperator, powerExpression);

  Code *code = generateBinaryExpression(multiplicationOperator->data->value.valueString, multiplicationOperator, multiplicationExpression, powerExpression);
  addCodeToNode(multiplicationOperator, code);

  return multiplicationOperator;
}
Node *multiplicationExpression_powerExpression(Node *powerExpression) { return powerExpression; }

Node *powerExpression_powerExpression_powerOperator_unaryExpression(Node *powerExpression, Node *powerOperator, Node *unaryExpression)
{
  addTypeToNode(powerOperator, inferType(powerExpression->type, unaryExpression->type));
  addChild(powerOperator, powerExpression);
  addChild(powerOperator, unaryExpression);

  return powerOperator;
}
Node *powerExpression_unaryExpression(Node *unaryExpression) { return unaryExpression; }

Node *unaryExpression_unaryOperator_unaryExpression(Node *unaryOperator, Node *unaryExpression)
{
  verifyUnaryOperatorType(unaryOperator->data->label, unaryExpression->type);
  addTypeToNode(unaryOperator, unaryExpression->type);
  addChild(unaryOperator, unaryExpression);

  addCodeToNode(unaryOperator, generateUnaryExpression(unaryOperator));

  return unaryOperator;
}
Node *unaryExpression_operand(Node *operand) { return operand; }

Node *orLogicalOperator_TK_OC_OR(TokenData *p_TK_OC_OR) { return createNode(p_TK_OC_OR, TYPE_BOOL); }

Node *andLogicalOperator_TK_OC_AND(TokenData *p_TK_OC_AND) { return createNode(p_TK_OC_AND, TYPE_BOOL); }

Node *bitwiseOrOperator_pipe(void *pipe) { return createCustomLabelNode("|", get_line_number(), TYPE_BOOL); }

Node *bitwiseAndOperator_comercialE(void *comercialE) { return createCustomLabelNode("&", get_line_number(), TYPE_BOOL); }

Node *equalityOperator_TK_OC_EQ(TokenData *p_TK_OC_EQ) { return createNode(p_TK_OC_EQ, TYPE_BOOL); }
Node *equalityOperator_TK_OC_NE(TokenData *p_TK_OC_NE) { return createNode(p_TK_OC_NE, TYPE_BOOL); }

Node *comparisonOperator_TK_OC_LE(TokenData *p_TK_OC_LE) { return createNode(p_TK_OC_LE, TYPE_BOOL); }
Node *comparisonOperator_TK_OC_GE(TokenData *p_TK_OC_GE) { return createNode(p_TK_OC_GE, TYPE_BOOL); }
Node *comparisonOperator_lessThan(void *lessThan) { return createCustomLabelNode("<", get_line_number(), TYPE_BOOL); }
Node *comparisonOperator_greaterThan(void *greaterThan) { return createCustomLabelNode(">", get_line_number(), TYPE_BOOL); }

Node *sumOperator_plusSign(void *plusSign) { return createCustomLabelNode("+", get_line_number(), TYPE_UNDEFINED); }
Node *sumOperator_minusSign(void *minusSign) { return createCustomLabelNode("-", get_line_number(), TYPE_UNDEFINED); }

Node *multiplicationOperator_asterisk(void *asterisk) { return createCustomLabelNode("*", get_line_number(), TYPE_UNDEFINED); }
Node *multiplicationOperator_forwardSlash(void *forwardSlash) { return createCustomLabelNode("/", get_line_number(), TYPE_UNDEFINED); }
Node *multiplicationOperator_percent(void *percent) { return createCustomLabelNode("%", get_line_number(), TYPE_UNDEFINED); }

Node *powerOperator_circumflex(void *circumflex) { return createCustomLabelNode("^", get_line_number(), TYPE_UNDEFINED); }

Node *unaryOperator_plusSign(void *plusSign) { return createCustomLabelNode("+", get_line_number(), TYPE_UNDEFINED); }
Node *unaryOperator_minusSign(void *minusSign) { return createCustomLabelNode("-", get_line_number(), TYPE_UNDEFINED); }
Node *unaryOperator_exclamationMark(void *exclamationMark) { return createCustomLabelNode("!", get_line_number(), TYPE_UNDEFINED); }
Node *unaryOperator_comercialE(void *comercialE) { return createCustomLabelNode("&", get_line_number(), TYPE_UNDEFINED); }
Node *unaryOperator_asterisk(void *asterisk) { return createCustomLabelNode("*", get_line_number(), TYPE_UNDEFINED); }
Node *unaryOperator_questionMark(void *questionMark) { return createCustomLabelNode("?", get_line_number(), TYPE_UNDEFINED); }
Node *unaryOperator_hashtag(void *hashtag) { return createCustomLabelNode("#", get_line_number(), TYPE_UNDEFINED); }

Node *variableDeclaration_optionalStatic_optionalConst_type_variable_variableDeclarationList(
    Node *optionalStatic,
    Node *optionalConst,
    Type type,
    Node *variable,
    Node *variableDeclarationList)
{
  endVariableListDeclaration(type);
  cleanVariableListDeclaration();
  if (variable == NULL)
  {
    return variableDeclarationList;
  }
  else
  {
    addNext(variable, variableDeclarationList);
    return variable;
  }
}

Node *variable_TK_IDENTIFICADOR(TokenData *p_TK_IDENTIFICADOR)
{
  createVariableTableEntry(p_TK_IDENTIFICADOR->value.valueString, get_line_number(), TYPE_UNDEFINED, NULL);
  Node *identifierNode = createNode(p_TK_IDENTIFICADOR, TYPE_UNDEFINED);

  addCodeToNode(identifierNode, generateLocalVarCode(identifierNode, NULL, 0));

  return NULL;
}
Node *variable_TK_IDENTIFICADOR_TK_OC_LE_value(TokenData *p_TK_IDENTIFICADOR, TokenData *p_TK_OC_LE, Node *value)
{
  SymbolTableEntry *entry = createVariableTableEntry(p_TK_IDENTIFICADOR->value.valueString, get_line_number(), TYPE_UNDEFINED, p_TK_IDENTIFICADOR);
  if (value->type == TYPE_STRING)
  {
    updateEntrySize(entry, strlen(value->data->value.valueString));
  }

  Node *node = createNode(p_TK_OC_LE, TYPE_UNDEFINED); // Verificar inferencia
  Node *identifierNode = createNode(p_TK_IDENTIFICADOR, TYPE_UNDEFINED);
  addChild(node, identifierNode);
  addChild(node, value);

  addCodeToNode(node, generateLocalVarCode(identifierNode, value, 1));

  return node;
}
Node *variable_TK_IDENTIFICADOR_TK_OC_LE_TK_IDENTIFICADOR(TokenData *first_TK_IDENTIFICADOR, TokenData *p_TK_OC_LE, TokenData *second_TK_IDENTIFICADOR)
{
  createVariableTableEntry(first_TK_IDENTIFICADOR->value.valueString, get_line_number(), TYPE_UNDEFINED, first_TK_IDENTIFICADOR);
  Type identifierType = getEntryTypeFromKey(first_TK_IDENTIFICADOR->value.valueString);

  Node *node = createNode(p_TK_OC_LE, identifierType);
  Node *identifierNode = createNode(first_TK_IDENTIFICADOR, identifierType);
  Node *initializerNode = createNode(second_TK_IDENTIFICADOR, getEntryTypeFromKey(second_TK_IDENTIFICADOR->value.valueString));

  addCodeToNode(initializerNode, generateLoadVariableCode(initializerNode));

  addChild(node, identifierNode);
  addChild(node, initializerNode);

  addCodeToNode(node, generateLocalVarCode(identifierNode, initializerNode, 1));

  return node;
}

Node *variableDeclarationList_comma_variable_variableDeclarationList(void *comma, Node *variable, Node *variableDeclarationList)
{

  if (variable == NULL)
  {
    return variableDeclarationList;
  }
  else
  {
    variable->next = variableDeclarationList;
    return variable;
  }
}
Node *variableDeclarationList_empty() { return NULL; }

Node *functionCall_TK_IDENTIFICADOR_openingParenthesis_functionParameters_closingParenthesis(
    TokenData *p_TK_IDENTIFICADOR,
    void *openingParenthesis,
    Node *functionParameters,
    void *closingParenthesis)
{
  verifyFunctionUse(p_TK_IDENTIFICADOR->value.valueString);
  verifyFunctionCallParams(p_TK_IDENTIFICADOR->value.valueString, functionParameters);
  Type identifierType = getEntryTypeFromKey(p_TK_IDENTIFICADOR->value.valueString);
  char str[10] = "call ";

  strcat(str, p_TK_IDENTIFICADOR->label);

  return addCodeToNode(
      addChild(createCustomLabelNode(str, get_line_number(), identifierType), functionParameters),
      generateFunctionCallCode(p_TK_IDENTIFICADOR->value.valueString, functionParameters));
}

Node *functionParameters_expression_functionParametersList(Node *expression, Node *functionParametersList) { return addNext(expression, functionParametersList); }
Node *functionParameters_empty() { return NULL; }

Node *functionParametersList_comma_expression_functionParametersList(void *comma, Node *expression, Node *functionParametersList) { return addNext(expression, functionParametersList); }
Node *functionParametersList_empty() { return NULL; }

Node *operand_TK_IDENTIFICADOR(TokenData *p_TK_IDENTIFICADOR)
{
  Node *node = createNode(p_TK_IDENTIFICADOR, getEntryTypeFromKey(p_TK_IDENTIFICADOR->value.valueString));

  return addCodeToNode(node, generateLoadVariableCode(node));
}
Node *operand_vectorIdentifier(Node *vectorIdentifier) { return vectorIdentifier; }
Node *operand_value(Node *value) { return value; }
Node *operand_functionCall(Node *functionCall) { return functionCall; }
Node *operand_openingParenthesis_expression_closingParenthesis(void *openingParenthesis, Node *expression, void *closingParenthesis) { return expression; }

Node *vectorIdentifier_TK_IDENTIFICADOR_openingBracket_expression_closingBracket(TokenData *p_TK_IDENTIFICADOR, void *openingBracket, Node *expression, void *closingBracket)
{
  Type identifierType = getEntryTypeFromKey(p_TK_IDENTIFICADOR->value.valueString);
  verifyVectorUse(p_TK_IDENTIFICADOR->value.valueString);

  Node *node = createCustomLabelNode("[]", get_line_number(), identifierType);
  addChild(node, createNode(p_TK_IDENTIFICADOR, identifierType));
  addChild(node, expression);

  return node;
}

Node *identifier_TK_IDENTIFICADOR(TokenData *p_TK_IDENTIFICADOR)
{
  createVariableTableEntry(p_TK_IDENTIFICADOR->value.valueString, get_line_number(), TYPE_UNDEFINED, NULL);
  freeToken(p_TK_IDENTIFICADOR);

  return NULL;
}
Node *identifier_TK_IDENTIFICADOR_openingBracket_positiveInteger_closingBracket(TokenData *p_TK_IDENTIFICADOR, void *openingBracket, Node *positiveInteger, void *closingBracket)
{
  createVectorTableEntry(p_TK_IDENTIFICADOR->value.valueString, get_line_number(), TYPE_UNDEFINED, positiveInteger->data->value.valueInt, NULL);
  freeToken(p_TK_IDENTIFICADOR);
  freeAST(positiveInteger);
}

Node *positiveInteger_plusSign_TK_LIT_INT(void *plusSign, TokenData *p_TK_LIT_INT)
{
  createLiteralTableEntry(get_line_number(), TYPE_INTEGER, p_TK_LIT_INT);
  return createNode(p_TK_LIT_INT, TYPE_INTEGER);
}
Node *positiveInteger_TK_LIT_INT(TokenData *p_TK_LIT_INT)
{
  createLiteralTableEntry(get_line_number(), TYPE_INTEGER, p_TK_LIT_INT);
  return createNode(p_TK_LIT_INT, TYPE_INTEGER);
}