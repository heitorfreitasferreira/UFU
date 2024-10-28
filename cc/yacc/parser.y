%{
#include "lexer.h"
#include <string.h>
#include <stdlib.h>

#define YYSTYPE double 
void yyerror(char *);

char posfix[1000] = "";

void append(const char* str) {
    strcat(posfix, str);
    strcat(posfix, " ");
}

void appendNum(double num) {
    char buffer[50];
    sprintf(buffer, "%.2f", num);
    append(buffer);
}
%}

%token NUM
%left '+' '-'
%left '*' '/'
%right NEGAR

%%
lines : { printf("Digite a expressao desejada:\n"); } lines_
     ;

lines_ : lines_ expr '\n' { 
         printf("%s= %.2lf\n", posfix, $2); 
         posfix[0] = '\0';
       }
     | lines_ '\n' { return 0; }
     |
     | error '\n' { yyerror("Erro na ultima linha"); yyerrok; }
     ;

expr : expr '+' expr {
         $$ = $1 + $3;
         append("+");
       }
     | expr '-' expr {
         $$ = $1 - $3;
         append("-");
       }
     | expr '*' expr {
         $$ = $1 * $3;
         append("*");
       }
     | expr '/' expr {
         $$ = $1 / $3;
         append("/");
       }
     | '(' expr ')' {
         $$ = $2;
       }
     | '-' expr %prec NEGAR {
         $$ = -$2;
         append("(-)");
       }
     | NUM {
         $$ = $1;
         appendNum($1);
       }
     ;

%%

/* yacc error handler */
void yyerror(char * s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    return yyparse();
}