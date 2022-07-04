//
// Created by heito on 10/06/2022.
//
#include "index.h"
float random_range(int i, int f) { return ((rand() % f) + i); }
float random_range(int f) { return ((rand() % f)); }
float random_range() { return ((float)rand() / RAND_MAX); }