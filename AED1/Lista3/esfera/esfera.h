typedef struct Ponto Ponto;
typedef struct Esfera Esfera;
Esfera *cria_esfera(float x1, float y1, float z1, float x2, float y2, float z2);
void libera_esfera(Esfera *e);
void libera_esfera(Esfera *e);
float raio(Esfera *e);
float area(Esfera *e);
double volume(Esfera *e);