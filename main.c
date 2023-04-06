#include <stdio.h>
#include "libAgenda.h"
#define ANO_AT 2023      /*ano atual*/

int main(){
    char entrada;                  /*variavel de saida*/
    struct agenda ag;               
    struct compromisso compr;       
    ag = criaAgenda(ANO_AT);      /*função para zerar todos os horários da agenda de 2023*/
    do{
        printf("Qual a data do seu compromisso?");
        compr = leCompromisso();                  /*leitura de compromisso*/
        if (validaData(compr.data_compr,ag)){
            if (verificaDisponibilidade(compr,ag)){
                ag = marcaCompromisso(ag, compr);
            }
            else{
                printf("data indisponivel\n");
            }
        } 
        else{
            printf("data inválida\n");
        }
        printf("Deseja sair? s = sim; n = nao ");
        while( (entrada = fgetc(stdin)) != EOF && entrada != '\n' ){}      /*limpeza de teclado (gambiarra)*/
        scanf("%c", &entrada);
        printf("\n\n");
    }while (entrada != 's');
    listaCompromissos(ag);     /*impressão de compromissos marcados*/
return 0;
};