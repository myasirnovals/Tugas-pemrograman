#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char i, j;
	
	i = 3;
	j = 4;
	
	printf ("i = %d \n", i);
	printf ("j = %d \n", j);
	
	printf ("i && j = %d \n", i && j);
	printf ("i & j = %d \n", i % j);
	printf ("i | j = &d \n", i || j);
	
	printf ("i | j = %d \n", i | j);
	printf (" i^j = %d \n", i ^ j);
	printf (" ~i = %d \n", ~i);
	return 0;
}
