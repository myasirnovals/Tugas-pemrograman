/**
 * Program: TabInt.c
 * Author: (2350081004, Muhamad Yasir Noval)
 * Kelas: A
 * Deskripsi: Header file dari prototype queue
 * Tanggal: 28 Maret 2024
 */

#include <stdio.h>

#include "../lib/TabInt.h"

/*konstruktor*/
void CreateTabInt(TabInt *T) {
    (*T).neff = 0;
}

/*selektor tabint*/
int GetJumElmt(TabInt T) {
    if (IsEmpty(T)) {
        return 0;
    } else {
        return T.neff;
    }
}

int GetFirstIdx(TabInt T) {
    return T.Tb[1];
}

int GetLlastIdx(TabInt T) {
    return T.Tb[T.neff];
}

int GetElmt(TabInt T, int index) {
    // kamus
    int i;

    // algoritma
    if (index <= nMax) {
        for (i = 1; i <= T.neff; i++) {
            if (T.Tb[i] == index) {
                return T.Tb[i];
            }
        }

        return false;
    } else {
        return false;
    }
}

/*set nilai*/
void SetElm(TabInt *T, int i, int v) {
    if (i <= (*T).neff) {
        (*T).Tb[i] = v;
    } else {
        printf("index ke-%d tidak diketahui", i);
    }
}

/*kelompok operasi cek elemen kosong atau penuh*/
boolean IsEmpty(TabInt T) {
    if (T.neff == 0) {
        return true;
    } else {
        return false;
    }
}

boolean IsFull(TabInt T) {
    if (T.neff == nMax) {
        return true;
    } else {
        return false;
    }
}

/*kelompok operasi input output device*/
void BacaElm(TabInt *T) {
    int Elm;

    printf("Masukan Elemen :");
    scanf("%d", &Elm);

    while (Elm != 999) {
        AddElm(&(*T), Elm);
        printf("Masukan Elemen :");
        scanf("%d", &Elm);
    }
}

void CetakTabInt(TabInt T) {
    for (int i = 1; i <= T.neff; i++) {
        printf("[%d] ", T.Tb[i]);
    }
}

void AddElm(TabInt *T, int x) {
    if (!IsFull((*T))) {
        (*T).neff++;
        (*T).Tb[(*T).neff] = x;
    } else {
        printf("Tabel penuh");
    }
}

/*kelompok operasi aritmatika*/
TabInt KaliTab(TabInt Tab1, TabInt Tab2) {
    TabInt NewTab;
    int i;

    CreateTabInt(&NewTab);

    if (!IsEmpty(Tab1) && !IsEmpty(Tab2) && IsEQTab(Tab1, Tab2)) {
        for (i = 1; i <= Tab1.neff; i++) {
            AddElm(&NewTab, Tab1.Tb[i] * Tab2.Tb[i]);
        }
    } else {
        return NewTab;
    }

    return NewTab;
}

TabInt KaliKons(TabInt T, int c) {
    TabInt NewTab;
    int i;

    CreateTabInt(&NewTab);

    for (i = 1; i <= T.neff; i++) {
        AddElm(&NewTab, T.Tb[i] * c);
    }

    return NewTab;
}

/*kelompok operasi relasional terhadap TabInt*/
boolean IsEQTab(TabInt Tab1, TabInt Tab2) {
    if (Tab1.neff == Tab2.neff) {
        return true;
    } else {
        return false;
    }
}

/*kelompok operasi lain terhadap type*/
void CopyTab(TabInt Tabin, TabInt *Tabout) {
    (*Tabout) = Tabin;
}

TabInt InversTab(TabInt T) {
    TabInt NewTab;
    int i;

    CreateTabInt(&NewTab);

    for (i = T.neff; i >= 1; i--) {
        AddElm(&NewTab, T.Tb[i]);
    }

    return NewTab;
}

boolean IsElemenAda(TabInt T, ElType X) {
    int i;
    boolean hasil;

    i = 1;
    hasil = false;
    while (i <= T.neff && !hasil) {
        if (T.Tb[i] == X) {
            hasil = true;
        } else {
            i++;
        }
    }

    return hasil;
}

int CariElemen(TabInt T, ElType X) {
    int i;

    if (IsEmpty(T)) {
        return IdxUndef;
    } else {
        for (i = 1; i <= T.neff ; i++) {
            if (T.Tb[i] == X) {
                return i;
            }
        }

        return IdxUndef;
    }
}