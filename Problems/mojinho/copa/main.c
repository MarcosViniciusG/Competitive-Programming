#include <stdio.h>
#include <stdlib.h>

int diva(int a) {
    if(a % 2 == 0)
        return a / 2;
    return (a / 2) + 1;
}

int min(int a, int b) {
    if(a <= b) return a;
    else return b;
}

int max(int a, int b) {
    if(a >= b) return a;
    else return b;
}

int main() {
    int k, l;
    scanf("%d\n%d", &k, &l);

    int counter=1;
    int lesser = min(k, l);
    int bigger = max(k, l);
    while((abs(k - l) > 1 || (bigger & 1)) && k!=l) {
        counter++;
        k = diva(k);
        l = diva(l);
        bigger = max(k, l);
    }

    if(counter==1)
        printf("oitavas\n");
    else if(counter==2)
        printf("quartas\n");
    else if(counter==3)
        printf("semifinal\n");
    else
        printf("final\n");


    return 0;
}