%{
    #include "ast.h"
    #include "parser.tab.h"
    int lineCount = 1;

    void inc_lines();
%}
%option yylineno

%s multi_line_comment

letter [A-Za-z_]
digit [0-9]
identifier {letter}({digit}|{letter})*
integer {digit}+
exp [E|e][+|-]{integer}

%%

 /* Comentarios */

"//"[^\n]* {  }

"/*" { BEGIN(multi_line_comment); }

<multi_line_comment>"*/" { BEGIN(INITIAL); }
<multi_line_comment>[^*/\n]*
<multi_line_comment>[\n] { inc_lines(); }
<multi_line_comment>. { }

 /* Palavras Reservadas da Linguagem */

"int"       { return TK_PR_INT       ; }
"float"     { return TK_PR_FLOAT     ; }
"bool"      { return TK_PR_BOOL      ; }
"char"      { return TK_PR_CHAR      ; }
"string"    { return TK_PR_STRING    ; }
"if"        { return TK_PR_IF        ; }
"then"      { return TK_PR_THEN      ; }
"else"      { return TK_PR_ELSE      ; }
"while"     { return TK_PR_WHILE     ; }
"do"        { return TK_PR_DO        ; }
"input"     { return TK_PR_INPUT     ; }
"output"    { return TK_PR_OUTPUT    ; }
"return"    { return TK_PR_RETURN    ; }
"const"     { return TK_PR_CONST     ; }
"static"    { return TK_PR_STATIC    ; }
"foreach"   { return TK_PR_FOREACH   ; }
"for"       { return TK_PR_FOR       ; }
"switch"    { return TK_PR_SWITCH    ; }
"case"      { return TK_PR_CASE      ; }
"break"     { return TK_PR_BREAK     ; }
"continue"  { return TK_PR_CONTINUE  ; }
"class"     { return TK_PR_CLASS     ; }
"private"   { return TK_PR_PRIVATE   ; }
"public"    { return TK_PR_PUBLIC    ; }
"protected" { return TK_PR_PROTECTED ; }
"end"       { return TK_PR_END       ; }
"default"   { return TK_PR_DEFAULT   ; }

 /* Caracteres Especiais */

"," { return yytext[0]; }
";" { return yytext[0]; }
":" { return yytext[0]; }
"(" { return yytext[0]; }
")" { return yytext[0]; }
"[" { return yytext[0]; }
"]" { return yytext[0]; }
"{" { return yytext[0]; }
"}" { return yytext[0]; }
"+" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"-" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"|" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"*" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"/" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"<" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
">" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"=" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"!" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"&" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"%" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"#" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"^" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"." { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"$" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }
"?" { createNonLiteralToken(yylineno, SPECIAL_CHAR_TOKEN, yytext); return yytext[0]; }


 /* Operadores Compostos */

"<=" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_LE ; }
">=" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_GE ; }
"==" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_EQ ; }
"!=" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_NE ; }
"&&" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_AND ; }
"||" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_OR ; }
">>" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_SL ; }
"<<" { yylval.valor_lexico = createNonLiteralToken(yylineno, COMPOSITE_OPERATOR_TOKEN, yytext); return TK_OC_SR ; }

 /* Literais */

{integer} { yylval.valor_lexico = createIntegerLiteralToken(yylineno, yytext); return TK_LIT_INT; }
{integer}\.{digit}+{exp}? { yylval.valor_lexico = createFloatLiteralToken(yylineno, yytext); return TK_LIT_FLOAT; }

['][^\']['] { yylval.valor_lexico = createCharLiteralToken(yylineno, yytext); return TK_LIT_CHAR; }
[']\\[tbnrf]['] { yylval.valor_lexico = createCharLiteralToken(yylineno, yytext); return TK_LIT_CHAR; }
["][^\"\n]*["] { yylval.valor_lexico = createStringLiteralToken(yylineno, yytext); return TK_LIT_STRING; }

true { yylval.valor_lexico = createBooleanLiteralToken(yylineno, yytext); return TK_LIT_TRUE; }
false { yylval.valor_lexico = createBooleanLiteralToken(yylineno, yytext); return TK_LIT_FALSE; }

 /* Identificadores */

{identifier} { yylval.valor_lexico = createNonLiteralToken(yylineno, IDENTIFIER_TOKEN, yytext); return TK_IDENTIFICADOR; }

[-+]?{digit}+{letter}({letter}|{digit}|_)* { return TOKEN_ERRO; }

 /* Outros */

[ \t]+ {  }

[\n] { inc_lines(); }

. { return TOKEN_ERRO; }

%%

int get_line_number() {
    return lineCount;
}

void inc_lines() {
    lineCount++;
}
