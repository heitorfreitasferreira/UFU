%option noyywrap
%option outfile="lexer.c" header-file="lexer.h"
%{
#define YYSTYPE double // Define tipo yylval (extern YYSTYPE yylval no y.tab.h)
#include "y.tab.h" // Biblioteca Analisador Sintatico
%}

DIGITO [0-9]

%%
[\t ] { } /* ignora tabulacao e espaco */
{DIGITO}+([.]{DIGITO}+)? { yylval = atof(yytext); return NUM; }
. { return yytext[0]; }
\n { return yytext[0]; }
%%
// Seção de Código VAZIA