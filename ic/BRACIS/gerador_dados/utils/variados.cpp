#include "index.h"

float random_range() { return ((float)rand() / RAND_MAX); }
float random_range(int i, int f) { return ((rand() % f) + i); }
float random_range(int f) { return ((rand() % f)); }

float coef = 1;
double matrixCoef[3][3] =
    {
        {coef * 0.12, coef * 0.16, coef * 0.12},
        {coef * 0.08, 0, coef * 0.08},
        {coef * 0.04, coef * 0.002, coef * 0.04}};

// Function that allocates and returns a pointer to a new matrix of size m x m with set values.
