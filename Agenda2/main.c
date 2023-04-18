#include <stdio.h>
#include "libAgenda2.h"

int main (){
    char saida; /* Variavel de saida do loop */
    struct agenda agenda, *p_agenda;
    struct compromisso compromisso, *p_compromisso;
    int ano; /* Variavel para determinar o ano da agenda */
    p_agenda = &agenda;
    p_compromisso = &compromisso;

    /* Setagem de ano que o usuario quer na agenda */
    scanf("%d", &ano);
    agenda = criaAgenda(ano);

    /* Loop para leitura de compromissos ate o usuario
     * digitar 's' */
    do{
        if (leCompromisso(p_agenda,p_compromisso))
            marcaCompromisso(p_agenda,p_compromisso);

        scanf(" %c", &saida);
    }while (saida != 's');
    
    listaCompromissos(p_agenda);
    return 0;
}