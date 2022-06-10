#include "index.h"

float random_range() {return ((float) rand()/RAND_MAX);}
float random_range(int i, int f) {return ((rand() % f) + i);}
float random_range(int f) {return ((rand() % f));}
