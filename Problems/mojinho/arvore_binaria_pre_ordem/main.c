#include <stdio.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pre_ordem(no *raiz) {
    no *pilha[10000];
    int p=0;
    pilha[p++] = raiz; 
    while(1) {
        no *x = pilha[--p];
        if(x!=NULL) {
            printf("%d ", x->dado);
            pilha[p++] = x->dir;
            pilha[p++] = x->esq;
        }
        if(p==0) {
            printf("\n");
            break;
        }
    }
}