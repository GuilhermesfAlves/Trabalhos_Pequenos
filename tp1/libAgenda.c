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
	struct tm tipodata = {0};
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


/*função para zerar todos os horários da agenda de 2023*/
struct agenda criaAgenda(int ano){              
	struct agenda agenda = {0};
	agenda.ano = ano;
	return agenda;
}

/*função para leitura de data e hora de um novo compromisso*/
struct compromisso leCompromisso(){
	struct compromisso compr;
	scanf("%d %d %d %d", &compr.data_compr.dia, &compr.data_compr.mes, &compr.data_compr.ano, &compr.hora_compr);
	compr.hora_compr = obtemHora(compr);
	return compr;
}

/*retorna a hora de um compromisso*/
int obtemHora(struct compromisso compr){    
	return compr.hora_compr;
}

/*retorna o ano de uma agenda*/
int obtemAno(struct agenda ag){        
	return ag.ano;
}

int validaData(struct data d, struct agenda ag){
/*data inválida para compromissos em datas negativas e acima de 31 e ano diferente da agenda*/
	if ((d.dia<1) || (d.dia > 31) || (d.ano != ag.ano)){       
		return 0;
	}
/*data inválida para meses que terminam em 30 e data no dia 31*/
	if ((d.mes == 4) || (d.mes == 6) || (d.mes == 9) || (d.mes == 11)){   
		if (d.dia > 30){
			return 0;
		}
	}
/*data inválida para dias acima de 28 em fevereiro*/
	if (d.mes == 2){                          
		if (d.dia > 28){
			return 0;
		}
	}
	return 1;	
}

/*função que verifica se já há um compromisso nessa data e hora*/
int verificaDisponibilidade(struct compromisso compr, struct agenda ag){
	int dia = obtemDiaDoAno(compr.data_compr);
	if ((ag.agenda_do_ano[dia].horas[compr.hora_compr]) == 0){             
	/*se em tal data do ano e tal horario, a agenda estiver ocupado (1), não será marcada*/
		return 1;
	}
	return 0;
}

/*função que põe o compromisso na agenda*/
struct agenda marcaCompromisso(struct agenda ag, struct compromisso compr){
	int dia = obtemDiaDoAno(compr.data_compr);
	ag.agenda_do_ano[dia].horas[compr.hora_compr] = 1;                       
	printf("Compromisso inserido com sucesso!\n");
	return ag;
}

/*função que lista todos os compromissos*/
void listaCompromissos(struct agenda ag){
	for (int i=0; i<DIAS_DO_ANO; i++){
		for (int j=0; j<HORAS_DO_DIA; j++){
			if ((ag.agenda_do_ano[i].horas[j]) == 1){
				printf("dia: %d, ano: %d, hora: %d, compromisso!\n", i, ag.ano, j);
			}
		}
	}
}