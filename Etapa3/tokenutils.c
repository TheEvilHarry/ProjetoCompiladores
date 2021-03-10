#include "tokenutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TokenData *createNonLiteralToken(int line, Token type, char *value)
{
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = type;
  token->literal = NOT_LITERAL;

  token->value.valueString = strdup(value);

  return token;
}

TokenData *createIntegerLiteralToken(int line, int value)
{
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_INTEGER;

  token->value.valueInt = value;

  return token;
}

TokenData *createFloatLiteralToken(int line, float value)
{
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_FLOAT;

  token->value.valueInt = value;

  return token;
}

TokenData *createBooleanLiteralToken(int line, int value)
{
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_BOOLEAN;

  token->value.valueBoolean = value;

  return token;
}

TokenData *createCharLiteralToken(int line, char value)
{
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_CHAR;

  token->value.valueChar = (char)value;

  return token;
}

TokenData *createStringLiteralToken(int line, char *value)
{
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_STRING;

  char *tempString = strdup(value);
  int position = 0, length = strlen(value);
  for (int i = 0; i < length; i++)
  {
    if (i != 0 && i != length - 1)
    {
      tempString[position++] = tempString[i];
    }
  }
  tempString[position] = '\0';

  token->value.valueString = tempString;

  return token;
}

void freeToken(TokenData *token)
{
  if (token != NULL)
  {
    if (token->type != LITERAL_TOKEN || token->literal == LIT_STRING)
    {
      free(token->value.valueString);
    }
    free(token);
  }

  return;
}