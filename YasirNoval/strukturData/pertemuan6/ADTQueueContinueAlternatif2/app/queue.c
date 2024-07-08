#include "../lib/queue.h"

void CreateQueue(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

int NBElmt(Queue Q) {
    if (Head(Q) == 0 && Tail(Q) == 0) {
        return 0;
    } else {
        return Tail(Q) + 1 - Head(Q);
    }
}

boolean IsQueueEmpty(Queue Q) {
    if (Head(Q) == Nil && Tail(Q) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean IsQueueFull(Queue Q) {
    if (Tail(Q) == MaxEl) {
        return true;
    } else {
        return false;
    }
}

void AddQueue(Queue *Q, infotype X) {
    if (IsQueueEmpty(*Q)) {
        Head(*Q)++;
        InfoHead(*Q) = X;

        Tail(*Q) = Head(*Q);
    } else {
        if (!IsQueueFull(*Q)) {
            Tail(*Q)++;
            InfoTail(*Q) = X;
        } else {
            printf("Stack penuh");
        }
    }
}

void DelQueue(Queue *Q, infotype *X) {
    if (!IsQueueEmpty(*Q)) {
        if (Head(*Q) == Tail(*Q)) {
            *X = InfoHead(*Q);

            CreateQueue(Q);
        } else {
            *X = InfoHead(*Q);
            Head(*Q)++;
        }
    } else {
        printf("Queue kosong");
    }
}

void PrintQueueInfo(Queue S) {
    int i;

    if (!IsQueueEmpty(S)) {
        for (i = Head(S); i <= Tail(S); i++) {
            printf("[%d] <- ", InfoElm(S));
        }

        printf("Null");
    }
}

boolean isInfoKetemu(Queue S, infotype X) {
    int i;

    if (IsQueueEmpty(S)) {
        return false;
    } else {
        for (i = 1; i <= Tail(S); i++) {
            if (InfoElm(S) == X) {
                return true;
            }
        }

        return false;
    }
}

address CariElemenQueue(Queue Q, int X) {
    int i;

    if (IsQueueEmpty(Q)) {
        return IdxUndef;
    } else {
        for (i = 1; i <= Tail(Q); i++) {
            if (InfoElm(Q) == X) {
                return i;
            }
        }
        return IdxUndef;
    }
}
