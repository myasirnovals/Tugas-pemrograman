#include <stdio.h>
#include <stdlib.h>
#include "TabInt.h"
#include "TabInt.c"

int main()
{
    TabInt MyTab, Tab1, Tab2, Tab3, TabCopy;
    int index, newElm, cons, Elm;

    CreateTabInt(&MyTab);
    BacaElm(&MyTab);
    CetakTabInt(MyTab);

    /*selektor*/
    printf("\nJumlah elemen pada tabel : %d", GetJumElmt(MyTab));
    printf("\nElemen pertama pada tabel : %d", GetFirstIdx(MyTab));
    printf("\nELemen terakhir pada tabel : %d", GetLlastIdx(MyTab));
    printf("\nMasukan index elemen yang akan di ambil : ");
    scanf("%d", &index);
    printf("\nElemen index ke-%d adalah : %d", index, GetElmt(MyTab, index));
    printf("\nMasukan index elemen yang akan di ubah :");
    scanf("%d", &index);
    printf("\nMasukan elemen yang baru :");
    scanf("%d", &newElm);
    SetElm(&MyTab, index, newElm);
    CetakTabInt(MyTab);
    if (isEmpty(MyTab))
    {
        printf("\nTabel kosong");
        /* code */
    }
    else
    {
        printf("\nTabel tidak kosong");
    }
    if (IsFull(MyTab))
    {
        printf("\nTabel penuh");
        /* code */
    }
    else
    {
        printf("\nTabel tidak penuh");
    }
    printf("\n\nMasukan elemen Tab1 untuk perkalian\n");
    CreateTabInt(&Tab1);
    BacaElm(&Tab1);
    CetakTabInt(Tab1);
    CreateTabInt(&Tab2);
    Tab2 = KaliTab(MyTab, Tab1);
    printf("\nHasil kali antar tabel Tab2:");
    CetakTabInt(Tab2);
    printf("\nMasukan konstasta yang akan di kalikan :");
    scanf("%d", &cons);
    CreateTabInt(&Tab3);
    Tab3 = KaliKons(MyTab, cons);
    printf("\nHasil perkalian tabel dengan konstasta Tab3:");
    CetakTabInt(Tab3);
    if (IsEQTab(MyTab, Tab1))
    {
        printf("\n\n MyTab dan Tab1 memiliki jumlah elemen yang sama");
        /* code */
    }
    else
    {
        printf("\n\n MyTab dan Tab1 memiliki jumlah elemen berbeda");
    }
    CreateTabInt(&TabCopy);
    CopyTab(MyTab, &TabCopy);
    printf("\nOperasi menyalin tabel MyTab ke TabCopy :");
    CetakTabInt(TabCopy);
    printf("\nInvers MyTab : ");
    CetakTabInt(InversTab(TabCopy));
    printf("\nMasukan elemen yang akan di cari pada TabCopy :");
    scanf("%d", &Elm);
    if (IsElemenAda(TabCopy, Elm))
    {
        printf("Elemen Ada");
        /* code */
    }
    else
    {
        printf("Elemen Tidak ada");
    }
    printf("\nMasukan elemen yang akan di cari pada MyTab :");
    scanf("%d", &Elm);
    printf("\nElemen yang di cari berada pada index ke-%d", CariElemen(MyTab, Elm));

    return 0;
}