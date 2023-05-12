#include "libpilhapar.h"
#include <stdio.h>
#define MAX 100

int main(){
    char s[MAX] = {'\n'}, t;
    int i=0;
    struct pilha *p;
    
    p = pilha_cria();

    do {
        scanf("%c",&s[i]);
        i++;
    } while (s[i-1] != '\n');

    i = 0;
    while (s[i] != '\n'){

        if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            push(p,s[i]);

        else if (pilha_topo(p, &t))
            if (((s[i] == ')') && (t == '(')) || ((s[i] == ']') && (t == '['))  || ((s[i] == '}') && (t == '{')))
                pop(p, &t);
        
        i++;
    };

    imprime_pilha(p);

    if (pilha_vazia(p))
        printf("ok\n");
    else 
        printf("erro\n");

    pilha_destroi(&p);
    return 0;
};