#include "stack.c"
#include "stack.h"
#include <stdio.h>
#include <conio.h>

int main()
{
    Stack MyStack;
    infotype popElm;
    infotype cariELm;
    addres idx;
    CreateStack(&MyStack);
    // printf("%d", Top(MyStack));
    // BacaStack(&MyStack);
    // printf("%d", Top(MyStack));
    if (IsStackEmpty)
    {
        printf("\nStack kosong");
    }else
    {
        printf("\nStack tidak kosong");
    }
    if (IsStackFull)
    {
        printf("\nStack penuh");
    }else
    {
        printf("\nStack tidak penuh");
    }

    // PrintStackInfo(MyStack);

    // pop(&MyStack, &popElm);
    // printf("\nElemen stack yang di pop : %d", popElm);
    
    // printf("\nMasukan elemen yang di cari :");
    // scanf("%d", &cariELm);
    
    // if (IsKetemu(MyStack,cariELm))
    // {
    //     printf("\nElm ketemu");
    // }else
    // {
        
    //     printf("\nElm tidak ketemu");
    // }
    
    // printf("\nMasukan elemen yang di cari :");
    // scanf("%d", &cariELm);
    
    // idx = CariElemenStack(MyStack, cariELm);
    // printf("\nELemen berada di %d", idx);
    return 0;
}