typedef struct Ponto Point;
Point *createPoint(float x, float y);
void freePoint(Point *p);
float distancePoint(Point *p1, Point *p2);