/* Program 		:  stack2.c 
   Author		:  2350081062 Aji Kartiko Hartanto
				   2350081064 Jarwo Eddy Wicaksono
				   2350081079 Rifqi Fauzi Anwar
   Kelas		:  C
   Deskripsi	:  Body File ADT Stack List
   Tanggal  	:  15 Mei 2024
*/ 
#include "stack2.h"
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Konstruktor
void CreateStack(Stack *S){
	TOP(*S) = nil;
}

address Alokasi(infotype x){
	address P;

	P = (address) malloc(sizeof(ElmStack));
	if(P != nil){
		info(P) = x;
		next(P) = nil;
		return P;
	} 
	else{
		printf("Alokasi Gagal");
		return(nil);
	}
}

//Destruktor
void Dealokasi(address P){
	free(P);
}

//Operasi Stack
void Push(Stack *S, infotype X){
	address PX;
	
	PX = Alokasi(X);
	next(PX) = TOP(*S);
	TOP(*S) = PX;
}

void Pop(Stack *S, infotype *X){
	address atas;
	
	atas = TOP(*S);
	*X = info(atas);
	TOP(*S) = next(atas);
	Dealokasi(atas);	
}

void CetakStack(Stack S){
	address atas;
	
	atas = TOP(S);
	if(atas != nil){
		while(atas != nil){
			printf("->[%d]",info(atas));
			atas = next(atas);
		}
	} 
	else{
		printf("Stack Kosong");
	}
}

boolean IsStackEmpty(Stack S){
	if(TOP(S) == nil){
		return true;
	}else
		return false;
}

boolean CariElemenStack(Stack S, infotype x){
	address atas;
	
	atas = TOP(S);
    while (atas != nil) {
        if (info(atas) == x) {
            return true;
        }
        atas = next(atas);
    }
    return false;
}

