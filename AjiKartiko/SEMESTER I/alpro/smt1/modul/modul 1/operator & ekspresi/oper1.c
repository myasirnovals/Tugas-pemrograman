#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 10;
	int x = 1;
	int y = 2;
	
	printf ("n = %d \n", n);
	printf ("x = %d \n", x);
	printf ("y = %d \n", y);
	
	printf ("n & 8 = %d \n", n & 8);
	printf ("x & ~ 8 = %d \n", x & ~8);
	printf ("y << 2 = %d \n", y << 2);
	printf ("y >> 3 = %d \n", y >> 3);
	return 0;
}
