#include <stdio.h>
#include "libAgenda.h"

int main(){
    char entrada;                  /*variavel de saida*/
    struct agenda agenda;               
    struct compromisso compromisso;       
    agenda = criaAgenda(obtemAno(agenda));      /*função para zerar todos os horários da agenda de 2023*/
    do{
        printf("--> Entre com dia, mes, ano, hora:\n");
        compromisso = leCompromisso();                  /*leitura de compromisso*/
        if ((compromisso.hora_compr > 23) || (compromisso.hora_compr < 0)){
            printf("Hora invalida, compromisso nao inserido\n");
        }
        else if ((validaData(compromisso.data_compr,agenda)) && (verificaDisponibilidade(compromisso,agenda))){
            agenda = marcaCompromisso(agenda, compromisso);
            }
        printf("--> Digite um char qualquer ou s para sair\n");
        while( (entrada = fgetc(stdin)) != EOF && entrada != '\n' ){}      /*limpeza de teclado (gambiarra)*/
        scanf("%c", &entrada);
    }while (entrada != 's');
    listaCompromissos(agenda);     /*impressão de compromissos marcados*/
return 0;
};