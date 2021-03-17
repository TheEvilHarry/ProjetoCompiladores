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

  strcpy(token->value.valueString, value);
  strcpy(token->label, value);

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
  strcpy(token->label, value);

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
  strcpy(token->label, value);

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

  strcpy(token->label, value);

  return token;
}

TokenData *createCharLiteralToken(int line, char *value)
{
  printf("Creating char lexical value %c on line %d\n", value[1], line);
  TokenData *token = malloc(sizeof(TokenData));

  token->line = line;
  token->type = LITERAL_TOKEN;
  token->literal = LIT_CHAR;

  token->value.valueChar = (char)value[1];
  char str[2] = "\0";
  str[0] = value[1];
  strcpy(token->label, str);

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

  strcpy(token->value.valueString, tempString);
  strcpy(token->label, tempString);

  free(tempString);

  return token;
}

void freeToken(TokenData *token)
{
  printf("Staring token %s's free operation\n", token->label);
  if (token != NULL)
  {
    printf("Token %s is not NULL, proceeding with free operation\n", token->label);
    free(token);
  }
  printf("Finished token free operation\n");

  return;
}