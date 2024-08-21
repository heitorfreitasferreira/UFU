// Boolean constants
#define TRUE 1
#define FALSE 0

// Token types
#define TOK_ID "ID"
#define TOK_RELOP "RELOP"
#define TOK_SEP "SEPARATOR"
#define TOK_INT "NUM_INT"
#define TOK_FLOAT "NUM_FLOAT"
#define TOK_COMMENT "COMMENT"
#define TOK_EOF "EOF"
#define TOK_ASSIGN "ASSIGN"
#define TOK_BEGIN "BEGIN"
#define TOK_END "END"
#define TOK_WHILE "WHILE"
#define TOK_REPEAT "REPEAT"
#define TOK_UNTIL "UNTIL"
#define TOK_ERROR "ERROR"

#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

#define PARESQ 0
#define PARDIR 1

// Token structure
typedef struct
{
  char *type;
  char *value;
} Token;

extern Token *token();
extern Token *yylex();
