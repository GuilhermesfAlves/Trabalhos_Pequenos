/*
 * TAD pilha
 * -> versao com lista ligada com nodo cabeca
 * Autores:
 *    André Ricardo Abed Gregio
 *    Marcos Alexandre Castilho
 *    Luis Carlos Erpen de Bona
 *
 * Versao 1.0.0 de 09/05/2023
*/

#ifndef _LIBpilha_par
#define _LIBpilha_par

struct nodo {
    char dado;
    struct nodo *prox;
};

struct pilha {
    struct nodo *topo;
    int tamanho;
};

/* 
 * Cria e retorna uma nova pilha.
 * Retorna NULL em caso de erro de alocação.
*/
struct pilha *pilha_cria ();

/* Desaloca toda memoria da pilha e faz pilha receber NULL. */
void pilha_destroi (struct pilha **pilha);

/* 
 * Insere dado na pilha (politica LIFO). Retorna 1
 * em caso de sucesso e 0 em caso de falha.
*/
int push (struct pilha *pilha, char dado);

/* 
 * Remove o topo (politica LIFO) e retorna o elemento 
 * no parametro dado. A funcao retorna 1 em caso de 
 * sucesso e 0 no caso da pilha estar vazia.
*/
int pop (struct pilha *pilha, char *dado);
 
/* Similar ao pop, mas retorna o elemento dado sem remove-lo. */
int pilha_topo (struct pilha *pilha, char *dado); 

/* Retorna o numero de elementos da pilha, que pode ser 0. */
int pilha_tamanho (struct pilha *pilha);

/* Retorna 1 se pilha vazia, 0 em caso contrario. */ 
int pilha_vazia (struct pilha *pilha);

void imprime_pilha (struct pilha *pilha);

char OpostoAbre (char c);  

#endif