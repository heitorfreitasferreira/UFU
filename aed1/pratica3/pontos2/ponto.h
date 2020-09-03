typedef struct Ponto Point;
Point *createPoint(float x, float y, float z);
void freePoint(Point *p);
float distancePoint(Point *p1, Point *p2);