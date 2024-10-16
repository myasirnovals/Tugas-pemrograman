/*
	Nama: Aji Kartiko Hartanto
	Nim: 2350081062
	Kelas: C
	1-Des-2023
*/

#include <stdio.h>
#include <stdlib.h>

/* File : RecVar.c */
/* Record Varian */
int main()
/* Kamus */
/* Cell adalah sebuah sel spread sheet, yang mungkin isinya: */
/* Formula: string; integer atau real */
{
	//KAMUS
	typedef enum {rumus, integer, riil} Trec;
	typedef union {char * form; int nili; float nilf; } IsiSel;
	
	typedef struct { 
	char adrbrs; int adrkol ; Trec Tsel; IsiSel Isel ;
	} Cell;
	/* variabel */
	Cell FCell, ICell, RCell;
	
	//ALGORITMA
	/* Cara mengisi nilai */
	/* Type cell adalah formula */ FCell.adrbrs = 'A';
	FCell.adrkol = 1;
	FCell.Tsel = rumus;
	
	FCell.Isel.form = (char ) malloc(15*sizeof(char)); 
	strcpy (FCell.Isel.form, "XYZ12");
	
	/* Type cell adalah integer */ 
	ICell.adrbrs = 'A';
	ICell.adrkol = 2;
	ICell.Tsel = integer; 
	ICell.Isel.nili = 10;
	
	/* Type cell adalah bilangan */ 
	RCell.adrbrs = 'A';
	RCell.adrkol = 3;
	RCell.Tsel = riil; 
	RCell.Isel.nilf = 10.55;
	
	return 0;
}
