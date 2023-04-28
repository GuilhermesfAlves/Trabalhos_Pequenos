#include <stdio.h>
#include "libAgenda.h"

int main (){
    char saida; /* Variavel de saida do loop */
<<<<<<< HEAD
    struct agenda agenda;
    struct compromisso compromisso;
    int ano; /* Variavel para determinar o ano da agenda */
=======
    struct agenda agenda, *p_agenda;
    struct compromisso compromisso, *p_compromisso;
    int ano; /* Variavel para determinar o ano da agenda */
    p_agenda = &agenda;
    p_compromisso = &compromisso;
>>>>>>> 4007142a73acee1f90065a2ce07827d0c9c0349a

    /* Setagem de ano que o usuario quer na agenda */
    scanf("%d", &ano);
    agenda = criaAgenda(ano);

    /* Loop para leitura de compromissos ate o usuario
     * digitar 's' */
<<<<<<< HEAD
    do {
        if (leCompromisso(&agenda,&compromisso))
            marcaCompromisso(&agenda,&compromisso);
=======
    do{
        if (leCompromisso(p_agenda,p_compromisso))
            marcaCompromisso(p_agenda,p_compromisso);
>>>>>>> 4007142a73acee1f90065a2ce07827d0c9c0349a

        scanf(" %c", &saida);
    } while (saida != 's');
    
    listaCompromissos(&agenda);
    return 0;
}