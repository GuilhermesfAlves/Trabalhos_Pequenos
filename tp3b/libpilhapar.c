#include "libpilhapar.h"
#include <stdlib.h>

/* 
 * Cria e retorna uma nova pilha.
 * Retorna NULL em caso de erro de alocação.
*/
struct pilha *pilha_cria (){
    struct pilha *p;

    if ((p = malloc(sizeof (struct pilha)))){
        p -> tamanho = 0;
        p -> topo = NULL;
        return p;
    }
    return NULL;
}

/* Desaloca toda memoria da pilha e faz pilha receber NULL. */
void pilha_destroi (struct pilha **pilha){
    struct nodo *aux;
    struct pilha *p;

    p = *pilha;
    while (!pilha_vazia(p)){
        aux = aux -> prox;
        free(p -> topo);
        p -> topo = aux;
        p -> tamanho--;
    };
    free(*pilha);
    *pilha = NULL;
}

/* 
 * Insere dado na pilha (politica LIFO). Retorna 1
 * em caso de sucesso e 0 em caso de falha.
*/
int push (struct pilha *pilha, char dado){
    struct nodo *aux;

    aux = pilha -> topo;
    if (!(pilha -> topo = malloc(sizeof(struct nodo))))
        return 0;
    aux -> dado = dado;
    pilha -> topo = aux;
    pilha -> tamanho++;
    return 1;
}

/* 
 * Remove o topo (politica LIFO) e retorna o elemento 
 * no parametro dado. A funcao retorna 1 em caso de 
 * sucesso e 0 no caso da pilha estar vazia.
*/
int pop (struct pilha *pilha, char *dado){
    struct nodo *aux;

    if (!(pilha -> tamanho))
        return 0;
    aux = pilha -> topo;
    aux = aux -> prox;
    free(pilha -> topo);
    pilha -> topo = aux;
    pilha -> tamanho--;
    return 1;
}

/* Similar ao pop, mas retorna o elemento dado sem remove-lo. */
int pilha_topo (struct pilha *pilha, char *dado){
    struct nodo *aux;
 
    if (pilha_vazia(pilha)){
        aux = pilha -> topo;
        dado = &aux -> dado;
        return 1;}
    return 0;
}

/* Retorna o numero de elementos da pilha, que pode ser 0. */
int pilha_tamanho (struct pilha *pilha){
    return pilha -> tamanho;
}

/* Retorna 1 se pilha vazia, 0 em caso contrario. */ 
int pilha_vazia (struct pilha *pilha){
    if (!(pilha -> tamanho))
        return 1;
    return 0;
}