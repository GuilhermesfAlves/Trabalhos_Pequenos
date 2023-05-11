#include "libpilhapar.h"
#include <stdio.h>
#define MAX 100

int main(){
    char s[MAX] = {'\0'}, t=0;
    int i=0;
    struct pilha *p;
    
    p = pilha_cria();

    scanf("%c",&s[i]);
    while (s[i] != '\0'){
        scanf("%c",&s[i]);
        i++;
    };

    i = 0;
    while (s[i] != '\0'){
        if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            push(p,s[i]);

        if (pilha_topo(p, &t))
            if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}')) 
                if (t == s[i])
                    pop(p, &t);
        i++;
    }
    if (pilha_tamanho(p))
        printf("ok");
    else 
        printf("erro");
    pilha_destroi(&p);
}