#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

typedef struct{
	int next;
	short processed;
} ROAD;

ROAD* create_road();
int DFT(ROAD* road1, ROAD* road2, int road_size);
