#include <stdio.h>
#include "libAgenda.h"

int main (){
    char saida; /* Variavel de saida do loop */
    struct agenda agenda;
    struct compromisso compromisso;
    int ano; /* Variavel para determinar o ano da agenda */

    /* Setagem de ano que o usuario quer na agenda */
    scanf("%d", &ano);
    agenda = criaAgenda(ano);

    /* Loop para leitura de compromissos ate o usuario
     * digitar 's' */
    do {
        if (leCompromisso(&agenda,&compromisso))
            marcaCompromisso(&agenda,&compromisso);

        scanf(" %c", &saida);
    } while (saida != 's');
    
    listaCompromissos(&agenda);
    return 0;
}