typedef struct pilha *StaticStack;
#define max 20
StaticStack create_stack();
int empty_stack(StaticStack);
int full_stack(StaticStack);
int push(StaticStack, char);
int pop(StaticStack, char *);