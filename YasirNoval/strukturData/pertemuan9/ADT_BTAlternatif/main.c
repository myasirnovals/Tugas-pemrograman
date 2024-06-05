#include "app/binaryTree.c"

int main(void) {
    // kamus
    Tree MyTree;
    infoType N;

    // algoritma
    createTree(&MyTree);

    // memasukan bilangan kearah kiri root
    insertLeft(&MyTree, 1);
    insertLeft(&MyTree, 2);
    insertLeft(&MyTree, 3);

    // cetak tree;
    printf("\n\n");
    cetakTree(MyTree);

    return 0;
}
