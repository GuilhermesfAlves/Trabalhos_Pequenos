#include <stdio.h>
#include "libAgenda2.h"

int main (){
    char saida; /*variavel de saida do loop*/
    struct agenda agenda, *p_agenda;
    struct compromisso compromisso, *p_compromisso;
    p_agenda = &agenda;
    p_compromisso = &compromisso;

    scanf("%d", &p_agenda -> ano);
    agenda = criaAgenda(obtemAno(p_agenda));

    do{
        if (leCompromisso(p_agenda,p_compromisso))
            marcaCompromisso(p_agenda,p_compromisso);

        scanf(" %c", &saida);
    }while (saida != 's');
    
    listaCompromissos(p_agenda);
    return 0;
}