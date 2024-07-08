#include "../lib/stack.h"

void CreateStack(Stack *S) {
    Top(*S) = Nil;
}

boolean IsStackEmpty(Stack S) {
    if (Top(S) == Nil) {
        return true;
    } else {
        return false;
    }
}

boolean IsStackFull(Stack S) {
    if (Top(S) == MaxEl) {
        return true;
    } else {
        return false;
    }
}

void Push(Stack *S, infoType X) {
    if (!IsStackFull(*S)) {
        Top(*S)++;
        InfoTop(*S) = X;
    } else {
        printf("Stack penuh");
    }
}

void Pop(Stack *S, infoType *X) {
    if (!IsStackEmpty(*S)) {
        *X = InfoTop(*S);
        Top(*S) = PopTop(*S);
    } else {
        printf("Stack kosong");
    }
}

void PrintStackInfo(Stack S) {
    int i;

    for (i = 1; i <= Top(S); i++) {
        printf("[%d] ", ElemenTop(S));
    }
}

boolean IsInfoKetemu(Stack S, infoType X) {
    int i;
    boolean ketemu;

    i = 1;
    ketemu = tidak;
    while (i <= Top(S) && !ketemu) {
        if (ElemenTop(S) == X) {
            ketemu = ya;
        } else {
            i++;
        }
    }

    return ketemu;
}

address CariElemenStack(Stack S, infoType X) {
    int i;

    if (!IsStackEmpty(S)) {
        for (i = 1; i <= Top(S); i++) {
            if (ElemenTop(S) == X) {
                return i;
            }
        }

        return IdxUndef;
    } else {
        return IdxUndef;
    }
}