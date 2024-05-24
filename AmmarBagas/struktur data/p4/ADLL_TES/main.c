#include "list.c"
#include <stdio.h>

int main () {
    //deklarasi
    List NodeLi, InNodeLi;
    InfoType x, Delval, ElmInfo, CountLi;
    addres SearchElm;

    //algoritma
    CreateList(&NodeLi);
    BacaList(&NodeLi);
    printf("Print Info List Node List :");
    PrintInfo(NodeLi);

    if (ListEmpty(NodeLi))
    {
        printf("\nNode List kosong\n");
    }else
    {
        printf("\nNode List tidak kosong\n");
    }

    printf("\nDelete First\n");
    DelFirst(&NodeLi,&Delval);
    printf("Print info node list yang sudah di Delete :");
    PrintInfo(NodeLi);
    printf("\nElemen info yang sudah di hapus :%d\n", Delval);
    
    printf("\nInsert First\n");
    printf("Masukan info yang akan dimasukan ke dalam node list :");
    scanf("%d", &x);
    InsFirst(&NodeLi, x);


    printf("\nDelete Last\n");
    DelLast(&NodeLi,&Delval);
    printf("Masukan info yang akan dimasukan ke dalam node list :");
    PrintInfo(NodeLi);
    printf("\nElemen info yang sudah di hapus :%d\n", Delval);

    printf("\nDelete After\n");
    printf("Masukan info elemen list sebelum list yang akan di hapus :");
    scanf("%d",&ElmInfo);
    DelAfter(&NodeLi,&Delval,ElmInfo);
    printf("\nPrint info node list yang sudah di Delete :");
    PrintInfo(NodeLi);
    printf("\nElemen info yang sudah di hapus :%d\n", Delval);
    
    printf("\nMenghitung banyaknya elemen list\n");
    CountLi = NbElm(NodeLi);
    printf("Jumlah banyak nya elemen pada list : %d", CountLi);

    printf("\nSearch elemen pada list\n");
    printf("Masukan elemen yang akan dicari :");scanf("%d",&ElmInfo);
    SearchElm = Search(NodeLi,ElmInfo);
    if (SearchElm != Nil)
    {
        printf("\nElemen yang di cari %d berada pada alamat : %d", ElmInfo,SearchElm);

    }else
    {
        printf("\nElemen yang dicari %d tidak ada pada list", ElmInfo);
    }
    
    printf("\nInvers List\n");
    printf("Info elemen List sebelum di invers :");
    PrintInfo(NodeLi);
    InNodeLi = GetNewInvers(NodeLi);
    printf("\n\nInfo elemen List setelah di invers :");
    PrintInfo(InNodeLi);
    

    


    return 0;
}