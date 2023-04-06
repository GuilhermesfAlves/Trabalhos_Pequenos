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


struct agenda criaAgenda(int ano){
	struct agenda agenda;
	for (int i=0; i<DIAS_DO_ANO; i++){
		for (int j=0; j<HORAS_DO_DIA; j++){
			agenda.agenda_do_ano[i].horas[j] = 0;
		};
	};
	agenda.ano = ano;
	return agenda;
}

struct compromisso leCompromisso(){
	struct compromisso data;
	printf("\nData: ");
	scanf("%d %d %d", &data.data_compr.dia, &data.data_compr.mes, &data.data_compr.ano);
	printf("Horário: ");
	scanf("%d", &data.hora_compr);
	printf("\n");
	return data;
}

int obtemHora(struct compromisso compr){
	return compr.hora_compr;
}

int obtemAno(struct agenda ag){
	return ag.ano;
}

int validaData(struct data d, struct agenda ag){
	if ((d.dia>30) || (d.dia<0)){
		return 0;
	};
	if ((d.mes>12) || (d.mes<0)){
		return 0;
	};
	if (obtemAno(ag) != d.ano){
		return 0;
	};
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
	return ag;
}

void listaCompromissos(struct agenda ag){
	struct data data;
	printf("DIAS OCUPADOS NA AGENDA:\n");
	printf("------------------------------ \n| \n");
	for (int i=0; i<DIAS_DO_ANO; i++){
		for (int j=0; j<HORAS_DO_DIA; j++){
			if ((ag.agenda_do_ano[i].horas[j]) == 1){   /*de acordo com a yday do compromisso marcado, é transformado de volta no formato DD/MM/YY*/
				data.ano = 2023;
				if (i<31){        /*janeiro*/
					data.dia= i+1;
					data.mes= 1;
				}
				else if (i<59){   /*fevereiro*/
					data.dia= i-30;
					data.mes= 2;
				}
				else if (i<90){   /*março*/
					data.dia= i-58;
					data.mes= 3;
				}
				else if (i<120){  /*abriu*/
					data.dia= i-89;
					data.mes= 4;
				}
				else if (i<151){  /*maio*/
					data.dia= i-119;
					data.mes= 5;
				}
				else if (i<181){  /*junho*/
					data.dia= i-150;
					data.mes= 6;
				}
				else if (i<212){  /*julho*/
					data.dia= i-180;
					data.mes= 7;
				}
				else if (i<243){  /*agosto*/
					data.dia= i-211;
					data.mes= 8;
				}
				else if (i<273){  /*setembro*/
					data.dia= i-242;
					data.mes= 9;
				}
				else if (i<304){  /*outubro*/
					data.dia= i-272;
					data.mes= 10;
				}
				else if (i<334){  /*novembro*/
					data.dia= i-303;
					data.mes= 11;
				}
				else {            /*dezembro*/
					data.dia= i-333;
					data.mes= 12;
				}
				printf("| %d/%d/%d às %d:00 está ocupado\n", data.dia, data.mes, data.ano, j);
			}
		}
	}
	printf("| \n------------------------------\n");
}
