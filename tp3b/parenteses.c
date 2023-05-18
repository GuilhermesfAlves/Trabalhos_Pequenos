#include "libpilha.h"
#include <stdio.h>
#define MAX 100

char oposto(char t){
    if (t == '(')
        return ')';
    if (t == '[')
        return ']';
    if (t == '{')
        return '}';
    return '-';
}

int main(){
    char s[MAX] = {'\n'};
    int i=0, t;
    struct pilha *p;
    
    /*Este programa funciona da seguinte maneira:
    * é lido, do usuário, uma string com os caracteres
    * da expressão que se quer analisar, então e feita
    * a análise dos parenteses, jogando numa pilha
    * todos que abrem, e assim que for fechado, o topo é
    * retirado*/

    if (!(p = pilha_cria())){
        printf("erro na alocação da pilha\n");
        return 1;
    }

    /*leitura de string*/
    do {
        scanf("%c",&s[i]);
        i++;
    } while (s[i-1] != '\n');

    /*analise dos parenteses*/
    i = 0;
    while (s[i] != '\n'){

        if (((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))){
            if (pilha_topo(p,&t)){
                if (s[i] == oposto(t)){
                    pop(p, &t);
                    /*caso onde o topo é '(' e o atual da string é ')'*/
                }
                else
                    break;
                    /*caso onde há topo, porém não corresponde ao anterior ex: (]*/
            }
            else {
                if (!push(p,s[i])){
                    printf("erro de alocação no push");
                    return 1;
                }
                break;
                /*caso onde a pilha está vazia e o char da vez é de fechar parenteses*/
                /*o push serve somente para colocar algo na pilha, e então cair no
                * caso onde a pilha não está vazia e então incorreta
                ]()*/
                }
            }
        
        /*caso onde se coloca o abre parenteses na pilha*/
        else if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            if (!push(p,s[i])){
                printf("erro de alocação no push");
                return 1;
            }
        i++;
    };

    /*veredito*/
    if (pilha_vazia(p))
        printf("CORRETA\n");
    else 
        printf("INCORRETA\n");

    /*aterramento da pilha*/
    pilha_destroi(&p);
    return 0;
};