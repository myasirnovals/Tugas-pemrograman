/*	program : segitiga.c
	author : 2350081008
	date : 17/10/2023
	desc : menentukan apakah segetiga dapat dibentuk dari 3 masukan
*/

#include <stdio.h>
#include <conio.h>

int main() {
	//kamus 
	int a, b, c;
	
	//algoritma
	printf("masukan nilai a :"); scanf("%d", &a);
	printf("masukan nilai b :"); scanf("%d", &b);
	printf("masukan nilai c :"); scanf("%d", &c);
	
	//kondisional
	if (a >= 0 && b >= 0 && c >= 0){
		printf("sebuah segitiga");
	}else{
		printf("bukan sebuah segitiga");
	}
	
	return 0;
}

