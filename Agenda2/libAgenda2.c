/* 
 * Feito por Marcos Castilho em 06/04/2023
 * para a disciplina CI1001 - Programacao 1
 * obs.: a funcao obtemDiaDoAno foi feita
 * pelo prof. Andre Gregio.
 */

#include <stdio.h>
#include <time.h>
#include "libAgenda2.h"

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


struct agenda criaAgenda(int ano){
    struct agenda agenda;
    for (int i = 0; i<DIAS_DO_ANO; i++)
        for (int j = 0; j<HORAS_DO_DIA; j++)
            agenda.agenda_do_ano[i].horas[j] = 0;
    agenda.ano = ano;
	return agenda;
}

/* Dado um compromisso, retorna a hora definida */
int obtemHora(struct compromisso *compr){
    return compr -> hora_compr; 
}

/* Retorna o ano atribuido a uma agenda criada */
int obtemAno(struct agenda *ag){
    return ag -> ano;
}

/* Le um compromisso do teclado (dia, mes, ano e hora, nesta ordem) 
 * Devolve o compromisso no parametro e retorna 1 se o compromisso
 * eh valido ou 0 caso contrario */
int leCompromisso(struct agenda *ag, struct compromisso *compr){
    scanf("%d %d ", &compr -> data_compr.dia, &compr -> data_compr.mes);
    scanf("%d %d", &compr -> data_compr.ano, &compr -> hora_compr);
    if ((validaData(ag, &compr -> data_compr)) && (validaHora(compr)))
        if (verificaDisponibilidade(ag,compr))
            return 1;
    return 0;
}

/* Valida um data lida do usuario; 
 * Retorna 1 se a data for valida e 0 caso contrario */
int validaData(struct agenda *ag, struct data *d){
    int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (d -> dia > meses[d -> mes-1])
        return 0;
    if (d -> dia<1)
        return 0;
    if (d -> ano != ag -> ano)
        return 0;
    return 1;
}

/* Valida uma hora lida do usuario; 
 * Retorna 1 se a hora for valida e 0 caso contrario */
int validaHora(struct compromisso *compr){
    if ((compr -> hora_compr <= 23) && (compr -> hora_compr >= 0))
        return 1;
    return 0;
}

/* Retorna 0 se data e horario já estiverem ocupados, ou 1 caso contrario */
int verificaDisponibilidade(struct agenda *ag, struct compromisso *compr){
    int dia = obtemDiaDoAno(compr -> data_compr);
    if (ag -> agenda_do_ano[dia].horas[compr -> hora_compr] != OCUPADA)        
	/*se em tal data do ano e tal horario, a agenda estiver ocupado (1), não será marcada*/
		return 1;
	return 0;
}

/* Esta funcao considera que o comprimisso eh valido e a agenda esta livre
 * para da data/hora fornecidos, portanto quem chama esta funcao tem que
 * garantir estas informacoes. Portanto, a funcao simplesmente muda o valor
 * da hora do compromisso de livre para ocupado */
void marcaCompromisso(struct agenda *ag, struct compromisso *compr){
    int dia = obtemDiaDoAno(compr -> data_compr);
	ag -> agenda_do_ano[dia].horas[compr -> hora_compr] = OCUPADA;                       
}

/* Mostra as datas e horas de todos os compromissos marcados na agenda.
 * Se a agenda nao tiver compromissos agendados nao imprime nada */
void listaCompromissos(struct agenda *ag){
	for (int i=0; i<DIAS_DO_ANO; i++)
		for (int j=0; j<HORAS_DO_DIA; j++)
			if (ag -> agenda_do_ano[i].horas[j] == OCUPADA)
				printf("dia: %d, ano: %d, hora: %d, compromisso!\n", i, ag -> ano, j);	
}