#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node3{
	void* data_ptr;
	struct node3* link;
} STACK_NODE;

typedef struct{
	int count;
	STACK_NODE* top;
} STACK;

typedef struct{
	int next;
	short processed;
} ROAD;

STACK* create_stack();
int push(STACK* stack, void* in);
void* pop(STACK* stack);

ROAD* create_road();
int DFT(ROAD* road1, ROAD* road2, int road_size);

int main(){
	ROAD* r1 = create_road();
	ROAD* r2 = create_road();
	int test_number, road_size, i,j,  a,b,c,d;
    printf("\n");
   
    for(j=0; j<10; j++){
        // process input
        scanf("%d %d\n", &test_number, &road_size);
         for(i=0; i<road_size; i++){
            scanf("%d %d ", &a, &b);
            if( (r1+a)->next == 0){
                (r1+a)->next = b;
            }
            else if( (r2+a)->next == 0){
                (r2+a)->next = b;
            }
        }
        // process output
       printf("#%d ", test_number);
        int e = DFT(r1,r2, 3);
       printf("%d\n", DFT(r1, r2, road_size));
   
        // initialization
        r1 = create_road();
        r2 = create_road();
    }
	return 0;
}

STACK* create_stack() {
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if( !stack )
		return 0;
	stack->count = 0;	
	stack->top = 0;  
	return stack;	
}

int push(STACK* stack, void* in) {
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!node)
		return 0;
	node->data_ptr = in;
	node->link = stack->top; // my next become old boss
	stack->top = node; // I am a new boss	
	stack->count++;

	return 1;
}

void* pop(STACK* stack) {
	STACK_NODE* temp;
	if(stack->count == 0)
		return 0;
	else{
		temp = stack->top;
		void* data_out = stack->top->data_ptr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
		return data_out;
	}	
}

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
		if( ((road1+temp)->next > 0 & (road1+temp)->next <=99) & (road1[road1[temp].next]).processed != 1){
			push(stack, &road1[temp].next);
//            printf("1stack's size: %d\n", stack->count);
        }
		if( ((road2+temp)->next > 0 & (road2+temp)->next <=99) & (road2[road2[temp].next]).processed != 1){
			push(stack, &road2[temp].next); 	
//        	printf("2stack's size: %d\n", stack->count);
        }
		if(stack->count != 0){
            temp = *(int*)pop(stack);
    //        printf("현재위치: %d\n", temp);
      //      printf("stack's size: %d\n", stack->count);
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
