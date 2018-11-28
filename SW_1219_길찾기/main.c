#include "road.h"

int main(){
	ROAD* r1 = create_road();
	ROAD* r2 = create_road();
	int a1[3] = {1,2,3};

	r1[0].next = 1;
	r1[1].next = 2;
	r1[2].next = 97;
	r2[3].next = 10;
	r2[2].next = 98;

	printf("%d\n", (r1+2)->next);		
	printf("%d\n", r2[5].next);		
	printf("%d\n", DFT(r1, r2, 3));		// 1 -> exist

	return 0;
}
