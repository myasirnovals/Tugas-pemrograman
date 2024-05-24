/*
    Program: sapa.c
    Name: Muhamad Yusron Noval
    NIM: 2350081003
    Class: A
    Description: ...
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hallo(char sNama[], int nUmur);


int main()
{
    // Kamus
    int umur;
    char nama[100];

    // Algoritma
    printf("Masukan nama anda: ");
    scanf("%[^\n]", &nama);

    printf("Masukan umur anda: ");
    scanf("%d", &umur);

    hallo(nama, umur);

    return 0;
}

void hallo(char sNama[], int nUmur)
{
    if(nUmur < 17) {
        printf("\nHallo dik %s umurmu %d tahun, kamu belum dewasa\n\n", sNama, nUmur);
    
    } else {
        printf("\nHalo kak %s umurmu %d tahun, kamu sudah cukup dewasa\n\n", sNama, nUmur);
    }
}