#define nMax 10

typedef struct {
    int T[nMax + 1];
    int neff;
} TabInt;

// Function to insert x after the first occurrence of y in TabInt
void insertXBetweenY(TabInt *tab, int x, int y) {
    int index = -1;

    for (int i = 1; i <= tab->neff; i++) {
        if (tab->T[i] == y) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        // If y is not found in the array, append x to the end.
        if (tab->neff < nMax) {
            tab->neff++;
            tab->T[tab->neff] = x;
        }
    } else {
        // If y is found, insert x after the first occurrence of y.
        if (tab->neff < nMax) {
            for (int i = tab->neff + 1; i > index + 1; i--) {
                tab->T[i] = tab->T[i - 1];
            }
            tab->T[index + 1] = x;
            tab->neff++;
        }
    }
}

int main() {
    TabInt MyTab;
    int N, i, y, x;

    MyTab.neff = 0;

    printf("Membuat tabel\n");
    printf("Masukan bilangan: ");
    scanf("%d", &N);

    while (N != 999) {
        if (MyTab.neff < nMax) {
            MyTab.neff++;
            MyTab.T[MyTab.neff] = N;
        }

        printf("Masukan bilangan: ");
        scanf("%d", &N);
    }

    printf("\nTabel pertama\n");
    for (i = 1; i <= MyTab.neff; i++) {
        printf("<%d>", MyTab.T[i]);
    }
    printf("\n");

    printf("Masukan nilai X: ");
    scanf("%d", &x);

    printf("Masukan nilai Y: ");
    scanf("%d", &y);

    insertXBetweenY(&MyTab, x, y);

    printf("Tabel kedua");
    for (i = 1; i <= MyTab.neff; i++) {
        printf("<%d>", MyTab.T[i]);
    }

    return 0;
}