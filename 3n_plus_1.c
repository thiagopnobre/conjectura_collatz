#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

unsigned long cache[MAX];

unsigned long lenCollatzNum(unsigned long n){
    if ((n < MAX) && (cache[n]))
        return cache[n];
    if (n & 1){
        if (n < MAX){
            cache[n] = 2 + lenCollatzNum(((3*n)+1)/2);
            return cache[n];
        }else
            return 2 + lenCollatzNum(((3*n)+1)/2);
    }else{
        if (n < MAX){
            cache[n] = 1 + lenCollatzNum(n/2);
            return cache[n];
        }else
            return 1 + lenCollatzNum(n/2);
    }
}

int main(){
    unsigned long i, j, aux, cont, maior;
    cache[1] = 1;
    for (aux = 2 ; aux < MAX ; aux++)
        cache[aux] = 0;

    while(scanf("%lu %lu", &i, &j) != EOF){
        maior = 0;
        if (i < j)
            for(aux = i ; aux <= j ; ++aux){
                cont = lenCollatzNum(aux);
                if (cont > maior)
                    maior = cont;
            }
        else
            for(aux = j ; aux <= i ; ++aux){
                cont = lenCollatzNum(aux);
                if (cont > maior)
                    maior = cont;
            }

        printf("%lu %lu %lu\n", i, j, maior);
    }

    return 0;
}
