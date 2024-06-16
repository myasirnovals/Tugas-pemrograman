#include <stdio.h>
#include <stdlib.h>

int main(){
	int x = 1;
	int y = 2;
	
	printf ("x = $d \n", x);
	printf ("y = $d \n", y);
	printf ("hasil ekspresi = (x<y)?x:y = %d \n", (x < y) ? x: y); 
	return 0;
}
