%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"
%{
#include "exp.h"
#include "string.h"
%}

DIGIT [0-9]
DIGITS {DIGIT}+
FRACTION \.{DIGITS}
LETTER [a-zA-Z]
LETTERS {LETTER}+

%%
begin { return token(TOK_BEGIN, NULL); }
end { return token(TOK_END, NULL); }
while { return token(TOK_WHILE, NULL); }
repeat { return token(TOK_REPEAT, NULL); }
until { return token(TOK_UNTIL, NULL); }
(_{LETTER}|{LETTER})({LETTER}|{DIGIT}|_)* { return token(TOK_ID, yytext); }
[=<!>]=? { return token(TOK_RELOP, yytext); }
[[:space:]\n\t] { return token(TOK_SEP, NULL); }
{DIGITS} { return token(TOK_INT, yytext); }
{DIGITS}{FRACTION} { return token(TOK_FLOAT, yytext); }
\/\*([^*]|\*+[^*/])*\*+\/ { return token(TOK_COMMENT, NULL); }
<<EOF>> { return token(TOK_EOF, NULL); }
:= { return token(TOK_ASSIGN, NULL); }
. { return token(TOK_ERROR, "0"); }

%%

Token tok;
Token* token(char* type, char* value) {
 	tok.type = NULL;
	tok.value = NULL;

	if (type != NULL) {
		tok.type = (char*) malloc(strlen(type) + 1);
		if (tok.type == NULL) {
			fprintf(stderr, "Memory error (tok.type)\n");
			exit(1);
		}

		strcpy(tok.type, type);
	}

	if (value != NULL) {
		tok.value = (char*) malloc(strlen(value) + 1);
		if (tok.value == NULL) {
			fprintf(stderr, "Memory error (tok.value)\n");
			exit(1);
		}

		strcpy(tok.value, value);
	}

 	return &tok;
}
