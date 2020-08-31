typedef struct complexos Complexos;
Complexos *cria_nro(float a, float b);
void libera_nro(Complexos *num);
Complexos *soma(Complexos *x, Complexos *y);
Complexos *subtracao(Complexos *x, Complexos *y);
Complexos *mult(Complexos *x, Complexos *y);
void get_value(Complexos *x, float *real, float *imaginary);
