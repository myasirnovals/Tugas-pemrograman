/*
    Program: stack_1.c
    Author: 2350081003/Muhamad Yusron Noval
    Kelas: A
    Deskripsi: Memasukan instruksi yang akan dieksekusi didalam fungsi dan prosedur
    Tanggal: 02/04/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_1.h"

void createStack(Stack *S) {
    Top(*S) = Nil;
}

boolean isEmpty(Stack S) {
    if(Top(S) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean isFull(Stack S) {
    if(Top(S) == maxElm) {
        return true;
    } else {
        return false;
    }
}

void Push(Stack *S, infoType X) {
    if(!isFull(*S)) {
        Top(*S)++;
        infoTop(*S) = X;
    } else {
        printf("Stack sudah penuh");
    }
}

void Pop(Stack *S, infoType *X) {
    if(!isEmpty(*S)) {
        *X = infoTop(*S);
        Top(*S) = popTop(*S);
    } else {
        printf("Stack masih kosong");
    }
}

void cetakStack(Stack S) {
    int i;

    for(i=1; i<=Top(S); i++) {
        printf("%d", elmTop(S));
    }
}

boolean isKetemu(Stack S, infoType X) {
    int i;
    boolean ketemu;

    i = 1;
    ketemu = false;
    while(i <= Top(S) && !ketemu) {
        if(elmTop(S) == X) {
            ketemu = true;
        } else {
            i++;
        }
    }

    return ketemu;
}

address cariElm(Stack S, infoType X) {
    int i;

    if(!isEmpty(S)) {
        for(i=1; i<=Top(S); i++) {
            if(elmTop(S) == X) {
                return i;
            }
        }

        return false;
    } else {
        return false;
    }
}