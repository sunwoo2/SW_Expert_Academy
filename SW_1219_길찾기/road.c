#include "road.h"

ROAD* create_road(){
	ROAD* new_road = (ROAD*)malloc(sizeof(ROAD)*100);
	int i;

	for(i=0; i<100; i++){
		(new_road+i)->next = 0;
		(new_road+i)->processed = 0;
	}

	return new_road;
}

int DFT(ROAD* road1, ROAD* road2, int road_size){
	STACK* stack = create_stack();
	int temp = 0, i;

	for(i=0; i<road_size; i++){
		if( ((road1+temp)->next > 0 & (road1+temp)->next <=99) & (road1[road1[temp].next]).processed != 1)
			push(stack, &road1[temp].next); 	
		if( ((road2+temp)->next > 0 & (road2+temp)->next <=99) & (road2[road2[temp].next]).processed != 1)
			push(stack, &road2[temp].next); 	

		if(stack->count != 0){
			temp = *(int*)pop(stack);
			if(temp == 99){
				free(stack);
				for(i=0; i<100; i++){
					(road1+i)->processed = 0;
					(road2+i)->processed = 0;
				}
				return 1;
			}
			road1[temp].processed = 1;
			road2[temp].processed = 1;
		}
	}
	free(stack);
	for(i=0; i<100; i++){
		(road1+i)->processed = 0;
		(road2+i)->processed = 0;
	}
	return 0;
}

