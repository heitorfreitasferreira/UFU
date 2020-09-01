typedef struct Ponto Ponto;
Ponto *createPoint(float x, float y, float z);
void freePoint(Ponto *p);
float distancePoint(Ponto *p1, Ponto *p2);