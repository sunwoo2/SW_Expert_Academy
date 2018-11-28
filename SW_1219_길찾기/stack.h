#include <stdio.h>
#include <stdlib.h>

typedef struct node3{
	void* data_ptr;
	struct node3* link;
} STACK_NODE;

typedef struct{
	int count;
	STACK_NODE* top;
} STACK;

STACK* create_stack();
int push(STACK* stack, void* in);
void* pop(STACK* stack);
