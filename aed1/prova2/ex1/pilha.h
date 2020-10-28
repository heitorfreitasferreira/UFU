typedef struct pilha *StaticStack;
#define max 20
StaticStack create_stack();
int empty_stack(StaticStack);
int full_stack(StaticStack);
int push(StaticStack, int);
int pop(StaticStack, int *);
int get_top(StaticStack, int *);
int get_stack(StaticStack, int *);
int stack_size(StaticStack p);