#include <stdio.h>
#include <math.h>

int isprima(int n){
	int li;
	
	if (n == 2)
		return 1; //true
	
	if (n % 2 == 0 || n == 1)
		return 0; //false
		
	for(li = 3;li <= sqrt (n); li+=2){
		if (n % li == 0)
		return 0; //false
		
	}
	return 1; //true
}
int main(){
	int li;
	system("cls");
	printf("Bilangan prima dari 1 sampai 100 : \n");
	
	for(li = 1;li<=100;li++)
		if(isprima(li))
	printf("%3d", li);
		return 0;
}
