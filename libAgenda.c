#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "libAgenda.h"
#define HORAS_DO_DIA 24
#define DIAS_DO_ANO 365

/* esta função transforma uma data lida pelo usuário para uma struct data
 * em uma data do tipo struct tm definida pela biblioteca time.h. 
 * Esta data é então transformada em segundos com a função mktime, para que
 * os outros membros da struct sejam preenchidos automaticamente, e então
 * reconvertida para uma data do tipo struct tm, reescrevendo a variável 
 * original. Com isso, pode-se obter o membro tm_yday, que representa o
 * dia do ano representado pela data: um inteiro entre 0 e 364 */
int obtemDiaDoAno(struct data d) {
	struct tm tipodata;
	time_t segundos;
	int dia_do_ano;

	tipodata.tm_mday = d.dia;
    tipodata.tm_mon = d.mes-1;
    tipodata.tm_year = d.ano-1900;
    tipodata.tm_isdst = -1;
	tipodata.tm_hour = 0;

	/* converte data para época, isto é, segundos desde 1970 */
	segundos = mktime(&tipodata);
	/* converte época em data, obtendo assim automaticamente
	 * o campo 'dia do ano' (tm_yday) que será o índice do
	 * vetor necessário para marcar um compromisso */
	tipodata = *localtime(&segundos);
	/* da reconversão da data, obtém o dia do ano, um número
	 * entre 0 e 364 */
    dia_do_ano = tipodata.tm_yday;
	
	return dia_do_ano;
}

/* DAQUI PARA BAIXO É COM VOCÊS! SIGAM O ENUNCIADO E O HEADER DISPONÍVEL */
//problemas na função obtemdiadoano

struct agenda criaAgenda(int ano){
	struct agenda agenda;
	agenda.ano = ano;
	for (int i=0; i<DIAS_DO_ANO; i++){
		for (int j=0; j<HORAS_DO_DIA; j++){
			agenda.agenda_do_ano[i].horas[j] = 0;
		};
	};
	return agenda;
}

struct compromisso leCompromisso(){
	struct compromisso compr;
	scanf("%d %d %d ", &compr.data_compr.dia, &compr.data_compr.mes, &compr.data_compr.ano);
	compr.hora_compr = obtemHora(compr);
	return compr;
}

int obtemHora(struct compromisso compr){
	scanf("%d", &compr.hora_compr);
	return compr.hora_compr;
}

int obtemAno(struct agenda ag){
	printf("--> Entre com o ano:\n");
	scanf("%d",&ag.ano);
	return ag.ano;
}

int validaData(struct data d, struct agenda ag){
	if ((d.dia<1) || (d.ano != ag.ano)){
		return 0;
	}
	if ((d.mes == 4) || (d.mes == 6) || (d.mes == 9) || (d.mes == 11)){
		if (d.dia > 30){
			return 0;
		}
	}
	if (d.mes == 2){
		if (d.dia > 28){
			return 0;
		}
	}
	else{
		if (d.dia > 31){
			return 0;
		}
	}
	return 1;	
}

int verificaDisponibilidade(struct compromisso compr, struct agenda ag){
	int dia = obtemDiaDoAno(compr.data_compr);
	if ((ag.agenda_do_ano[dia].horas[compr.hora_compr]) == 0){
		return 1;
	}
	return 0;
}

struct agenda marcaCompromisso(struct agenda ag, struct compromisso compr){
	int dia = obtemDiaDoAno(compr.data_compr);
	ag.agenda_do_ano[dia].horas[compr.hora_compr] = 1;                       /*põe o compromisso na agenda*/
	printf("Compromisso inserido com sucesso!\n");
	return ag;
}

void listaCompromissos(struct agenda ag){
	for (int i=0; i<DIAS_DO_ANO; i++){
		for (int j=0; j<HORAS_DO_DIA; j++){
			if ((ag.agenda_do_ano[i].horas[j]) == 1){   /*de acordo com a yday do compromisso marcado, é transformado de volta no formato DD/MM/YY*/
				printf("dia: %d, ano: %d, hora: %d, compromisso!\n", i, ag.ano, j);
			}
		}
	}
}