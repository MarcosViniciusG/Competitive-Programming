#include <stdio.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    no *pilha[10000];
    int p=0;
    pilha[p++] = raiz;
    while(1) {
        no *x = pilha[--p];
        if(x!=NULL) {
            pilha[p++] = x;
            pilha[p++] = x->esq;
        }
        else {
            if(p==0) break;
            x = pilha[--p];
            printf("%d ", x->dado);
            pilha[p++] = x->dir;
        }
    }
    printf("\n");
}