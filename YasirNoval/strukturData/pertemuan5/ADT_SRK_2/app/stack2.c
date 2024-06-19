#include "../lib/stack2.h"

void CreateStack(Stack *S) {
    Top(*S) = Nil;
}

address Alokasi(infoType x) {
    address newNode;

    newNode = (ElmStack *) malloc(sizeof(ElmStack));

    Info(newNode) = x;
    Next(newNode) = Nil;

    return newNode;
}

void DeAlokasi(address P) {
    free(P);
}

void Push(Stack *S, infoType X) {
    address newNode;

    newNode = Alokasi(X);

    if (IsStackEmpty(*S)) {
        Info(newNode) = X;
        Next(newNode) = Bottom(*S);

        Bottom(*S) = newNode;
        Top(*S) = Bottom(*S);
    } else {
        Info(newNode) = X;
        Next(newNode) = Nil;

        Next(Top(*S)) = newNode;
        Top(*S) = newNode;
    }
}

void Pop(Stack *S, infoType *X) {
    address delNode, current;

    delNode = Top(*S);
    current = Bottom(*S);

    while (Next(current) != Top(*S)) {
        current = Next(current);
    }

    *X = Info(Top(*S));
    Top(*S) = current;
    Next(Top(*S)) = Nil;

    DeAlokasi(delNode);
}

void CetakStack(Stack S) {
    address current;

    current = Bottom(S);
    while (current != Nil) {
        printf("[%d] -> ", Info(current));

        current = Next(current);
    }

    printf("Null");
}

boolean IsStackEmpty(Stack S) {
    if (Top(S) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean CariElemenStack(Stack S, infoType x) {
    address Current;

    Current = Bottom(S);
    while (Current != Nil) {
        if (Info(Current) == x) {
            return true;
        }

        Current = Next(Current);
    }

    return false;
}