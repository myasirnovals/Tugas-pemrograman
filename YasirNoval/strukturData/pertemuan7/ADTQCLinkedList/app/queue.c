#include "../lib/queue.h"

void CreateQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

address Alokasi(infoType x) {
    address newNode;

    newNode = (ElmQueue *) malloc(sizeof (ElmQueue));

    Info(newNode) = x;
    Next(newNode) = Nil;

    return newNode;
}

void DeAlokasi(address P) {
    free(P);
}

boolean IsQueueEmpty(Queue Q) {
    if (Head(Q) == Nil && Tail(Q) == Nil) {
        return true;
    } else {
        return false;
    }
}

void AddQueue(Queue *Q, infoType X) {
    address newNode;

    newNode = Alokasi(X);

    if (IsQueueEmpty(*Q)) {
        Info(newNode) = X;
        Next(newNode) = Head(*Q);

        Head(*Q) = newNode;
        Tail(*Q) = Head(*Q);
    } else {
        Info(newNode) = X;
        Next(newNode) = Nil;

        Next(Tail(*Q)) = newNode;
        Tail(*Q) = newNode;
    }
}

void DelQueue(Queue *Q, infoType *X) {
    address delNode;

    delNode = Head(*Q);
    Head(*Q) = Next(Head(*Q));

    *X = Info(delNode);
    DeAlokasi(delNode);
}

void CetakQueue(Queue Q) {
    address current;

    current = Head(Q);
    while (current != Nil) {
        printf("[%d] -> ", Info(current));

        current = Next(current);
    }
    printf("Null");
}

boolean CariElemenQueue(Queue Q, infoType X) {
    address current;
    boolean ketemu;

    current = Head(Q);
    ketemu = tidak;
    while (current != Nil && !ketemu) {
        if (Info(current) == X) {
            ketemu = ya;
        }

        current = Next(current);
    }

    return ketemu;
}
