#include "tokenutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TokenData *createNonLiteralToken(int line, Token type, char *value)
{
  printf("Creating non literal (type=%d) lexical value %s on line %d\n", type, value, line);
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = type;
  token->literal = NOT_LITERAL;

  token->value.valueString = strdup(value);
  token->label = strdup(value);

  return token;
}

TokenData *createIntegerLiteralToken(int line, char *value)
{
  printf("Creating integer lexical value %s on line %d\n", value, line);
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_INTEGER;

  token->value.valueInt = atoi(value);
  token->label = strdup(value);

  return token;
}

TokenData *createFloatLiteralToken(int line, char *value)
{
  printf("Creating float lexical value %s on line %d\n", value, line);
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_FLOAT;

  token->value.valueInt = atof(value);
  token->label = strdup(value);

  return token;
}

TokenData *createBooleanLiteralToken(int line, char *value)
{
  printf("Creating boolean lexical value %s on line %d\n", value, line);
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_BOOLEAN;

  if (strcmp(value, "true"))
  {
    token->value.valueBoolean = 1;
  }

  if (strcmp(value, "false"))
  {
    token->value.valueBoolean = 0;
  }

  token->label = strdup(value);

  return token;
}

TokenData *createCharLiteralToken(int line, char *value)
{
  printf("Creating char lexical value %s on line %d\n", value, line);
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_CHAR;

  token->value.valueChar = (char)value[1];
  token->label = strdup(value);

  return token;
}

TokenData *createStringLiteralToken(int line, char *value)
{
  printf("Creating string lexical value %s on line %d\n", value, line);
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
  token->label = strdup(value);

  return token;
}

void freeToken(TokenData *token)
{
  printf("Staring token %s's free operation\n", token->label);
  if (token != NULL)
  {
    // printf("Token %s is not NULL, proceeding with free operation\n", token->label);
    if (token->type != LITERAL_TOKEN || token->literal == LIT_STRING)
    {
      // printf("Freeing token %s's string value\n", token->label);
      free(token->value.valueString);
    }
    // printf("Freeing token %s's label\n", token->label);
    free(token->label);
    // printf("Freeing token %s (this is the label value after free)\n", token->label);
    free(token);
    // printf("Completed token %s's free operation\n", token->label);
  }
  printf("Finished token free operation\n");

  return;
}