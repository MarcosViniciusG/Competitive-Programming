#include <stdio.h>
// #include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pos_ordem(no *raiz) {
    no *pilha[10000];
    int p=0;

    no *ultimo = NULL;
    while(p > 0 || raiz) {
        if(raiz) {
            pilha[p++] = raiz;
            raiz = raiz->esq;
        }
        else {
            no *x = pilha[p-1];
            if(x->dir && ultimo != x->dir)
                raiz = x->dir;
            else {
                printf("%d ", raiz->dado);
                ultimo = pilha[--p];
            }
        }
    }
    printf("\n");
}

// int main() {
//     no *raiz = malloc(sizeof(no));
//     raiz->dado = 2;

//     no *novo = malloc(sizeof(no));
//     novo->dado = 5;
//     raiz->esq = novo;

//     novo = malloc(sizeof(no));
//     novo->dado = 7;
//     raiz->dir = novo;

//     novo = malloc(sizeof(no));
//     novo->dado = 3;
//     raiz->esq->esq = novo;

//     novo = malloc(sizeof(no));
//     novo->dado = 8;
//     raiz->esq->dir = novo;

//     novo = malloc(sizeof(no));
//     novo->dado = 4;
//     raiz->esq->dir->esq = novo;

//     novo = malloc(sizeof(no));
//     novo->dado = 1;
//     raiz->dir->esq = novo;

//     novo = malloc(sizeof(no));
//     novo->dado = 9;
//     raiz->dir->esq->dir = novo;

//     novo = malloc(sizeof(no));
//     novo->dado = 6;
//     raiz->dir->dir = novo;

//     pos_ordem(raiz);

//     return 0;
// }