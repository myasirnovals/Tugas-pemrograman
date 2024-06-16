#include <stdio.h>
#include <conio.h>

//Program menghitung deret dengan repeat n times

int main(){
	//KAMUS
	int N;
	float i, s;
	
	//KAMUS
	system("cls");
	printf("masukkan N:");
	scanf("%d", &N);
	s = 1.0;
	
	printf("s = 1+");
	for(i = 2; i <= N; i++){
		printf("%1.3f", 1/i);
		if(i<N)
			printf("+");
		s = s + 1/i;
}
printf("\nNilai s : %3.2f", s);

return 0;

}
