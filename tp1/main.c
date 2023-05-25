#include <stdio.h>
#include "libAgenda.h"

int main(){
    char saida;  /*variavel de saida do loop */
    struct agenda agenda; 
    struct compromisso compromisso;  
    printf("--> Entre com o ano:\n");
	scanf("%d",&agenda.ano);     

    /*função para zerar todos os horários da agenda de 2023*/
    agenda = criaAgenda(agenda.ano);      
    
    /*do while até que o usuario digite s*/
    do {
        printf("--> Entre com dia, mes, ano, hora:\n");
        /*leitura de compromisso*/
        compromisso = leCompromisso();              
        
        if ((compromisso.hora_compr > 23) || (compromisso.hora_compr < 0)){
            /*valida a hora*/
            printf("Hora invalida, compromisso nao inserido\n");
        }
        else if ((validaData(compromisso.data_compr,agenda)) && (verificaDisponibilidade(compromisso,agenda))){
            /*valida a disponibilidade e a validade*/
            agenda = marcaCompromisso(agenda, compromisso);
        }
        else{
            printf("Data inválida, compromisso nao inserido\n");
        }

        printf("--> Digite um char qualquer ou s para sair\n");
        scanf(" %c", &saida);

    } while (saida != 's');
     
    /*impressão de compromissos marcados*/
    listaCompromissos(agenda);

    return 0;
};