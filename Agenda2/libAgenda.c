/* 
 * Feito por Marcos Castilho em 06/04/2023
 * para a disciplina CI1001 - Programacao 1
 * obs.: a funcao obtemDiaDoAno foi feita
 * pelo prof. Andre Gregio.
 */

#include <stdio.h>
#include <time.h>
#include "libAgenda.h"

#define LIVRE 0
#define OCUPADA 1

int obtemDiaDoAno(struct data d){
    struct tm tipodata={0};
    time_t segundos;
    int dia_do_ano;

    tipodata.tm_mday = d.dia;
    tipodata.tm_mon = d.mes - 1;
    tipodata.tm_year = d.ano - 1900;
    tipodata.tm_isdst = -1;
    tipodata.tm_hour = 0;

    /* converte data para epoca, isto eh, segundos desde 1970 */
    segundos = mktime(&tipodata);

    /* converte epoca em data, obtendo assim automaticamente
     * o campo 'dia do ano' (tm_yday) que sera o indice do
     * vetor necessario para marcar um compromisso */
    tipodata = *localtime(&segundos);

    /* da reconversao da data, obtem o dia do ano, um numero
     * entre 0 e 364 */
    dia_do_ano = tipodata.tm_yday;

    return dia_do_ano;
}

/* Daqui para frente eh com voces! */

/* Inicializa a agenda */
struct agenda criaAgenda(int ano){
    struct agenda agenda;
<<<<<<< HEAD:Agenda2/libAgenda.c

=======
>>>>>>> 4007142a73acee1f90065a2ce07827d0c9c0349a:Agenda2/libAgenda2.c
    for (int dias=0; dias<DIAS_DO_ANO; dias++)
        for (int horas=0; horas<HORAS_DO_DIA; horas++)
            agenda.agenda_do_ano[dias].horas[horas] = LIVRE;
    agenda.ano = ano;
	return agenda;
}

/* Retorna a hora de um compromiso */
int obtemHora(struct compromisso *compr){
    return compr -> hora_compr; 
}

/* Retorna o ano de uma agenda */
int obtemAno(struct agenda *ag){
    return ag -> ano;
}

/* Le o dia, mes, ano e hora, caso validas, retorna 1 */
int leCompromisso(struct agenda *ag, struct compromisso *compr){
    scanf("%d %d ", &compr -> data_compr.dia, &compr -> data_compr.mes);
    scanf("%d %d", &compr -> data_compr.ano, &compr -> hora_compr);
    if ((validaData(ag, &compr -> data_compr)) && (validaHora(compr))){
        if (verificaDisponibilidade(ag,compr))
            return 1;
        }
    else 
        printf("Data e/ou hora invalidos, compromisso nao inserido\n");
    return 0;
}

/* Valida uma data para determinada agenda
 * 1 = valido, 0 = invalido */
int validaData(struct agenda *ag, struct data *d){
    int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (d -> dia > meses[d -> mes-1])
        return 0;
    if (d -> dia < 1)
        return 0;
    if (d -> ano != obtemAno(ag))
        return 0;
    return 1;
}

/* Valida a hora de determinado compromisso 
 * 1 = valido, 0 = invalido */
int validaHora(struct compromisso *compr){
    if ((obtemHora(compr) <= 23) && (obtemHora(compr) >= 0))
        return 1;
    return 0;
}

/* Verifica se já há outro compromisso nesta mesma data e hora  
 * numa agenda, 1 = data disponivel, 0 = data indisponivel */
int verificaDisponibilidade(struct agenda *ag, struct compromisso *compr){
    int dia = obtemDiaDoAno(compr -> data_compr);
<<<<<<< HEAD:Agenda2/libAgenda.c
    
=======
>>>>>>> 4007142a73acee1f90065a2ce07827d0c9c0349a:Agenda2/libAgenda2.c
    if (ag -> agenda_do_ano[dia].horas[obtemHora(compr)] != OCUPADA)
		return 1;
    printf("Data/Hora ocupada, compromisso nao inserido\n");
	return 0;
}

/* Marca o compromisso em uma agenda, determinando numa data e hora Ocupada */
void marcaCompromisso(struct agenda *ag, struct compromisso *compr){
    int dia = obtemDiaDoAno(compr -> data_compr);
<<<<<<< HEAD:Agenda2/libAgenda.c
	
    ag -> agenda_do_ano[dia].horas[obtemHora(compr)] = OCUPADA;    
=======
	ag -> agenda_do_ano[dia].horas[obtemHora(compr)] = OCUPADA;    
>>>>>>> 4007142a73acee1f90065a2ce07827d0c9c0349a:Agenda2/libAgenda2.c
    printf("Compromisso inserido com sucesso!\n");               
}

/* Lista todos os compromissos em determinada agenda */
void listaCompromissos(struct agenda *ag){
	for (int dias=0; dias<DIAS_DO_ANO; dias++)
		for (int horas=0; horas<HORAS_DO_DIA; horas++)
<<<<<<< HEAD:Agenda2/libAgenda.c
			if (ag -> agenda_do_ano[dias].horas[horas] == OCUPADA)
=======
			if (ag -> agenda_do_ano[i].horas[j] == OCUPADA)
>>>>>>> 4007142a73acee1f90065a2ce07827d0c9c0349a:Agenda2/libAgenda2.c
				printf("dia: %3d, ano: %4d, hora: %2d, compromisso!\n", dias, obtemAno(ag), horas);	
}