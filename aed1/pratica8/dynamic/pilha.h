#define max 20
typedef struct pilha *DynamicStack;
DynamicStack create_stack();
int empty_stack(DynamicStack *);
int full_stack(DynamicStack *);
int push(DynamicStack *, int);
int pop(DynamicStack *, int *);
int get_top(DynamicStack *, int *);
int get_stack(DynamicStack *, int *);
int stack_size(DynamicStack *);