    #include <stdlib.h>
#include "libfila.h"

/* 
 * Cria e retorna uma nova fila.
 * Retorna NULL em caso de erro de alocação.
*/
fila_t *fila_cria (){
    fila_t *f;

    if (!(f = malloc(sizeof(fila_t))))
        return NULL;

    f -> tamanho = 0;
    f -> cabeca = NULL;
    f -> cauda = NULL;

    return f;
}

/* Desaloca toda memoria da fila e faz fila receber NULL. */
void fila_destroi (fila_t **fila){
    nodo_t *aux;
    fila_t *f;

    f = *fila;

    while (!fila_vazia(f)){
        aux = f -> cabeca;
        f -> cabeca = aux -> prox;
        free (aux);
        f -> tamanho--; 
    };

    free(*fila); 
    *fila = NULL;
}

/* 
 * Insere dado no final da fila (politica FIFO). Retorna 1
 * em caso de sucesso e 0 em caso de falha.
*/
int enqueue (fila_t *fila, int dado){
    nodo_t *aux ;

    if (!(aux = malloc(sizeof(nodo_t))))
        return 0;

    aux -> dado = dado; 
    aux -> prox = NULL;

    if (fila_vazia(fila))
        fila -> cabeca = aux;
    else 
        fila -> cauda -> prox = aux;

    fila -> cauda = aux;
    fila -> tamanho++;
 
    return 1;
}

/* 
 * Remove o elemento do inicio da fila (politica FIFO) e o retorna
 * no parametro dado. Nao confundir com o retorno da funcao.
 * A funcao retorna 1 em caso de sucesso e 0 no caso da fila estar vazia.
*/
int dequeue (fila_t *fila, int *dado){
    nodo_t *aux;

    if (fila_vazia(fila))
        return 0;

    *dado = fila -> cabeca -> dado;
    aux = fila -> cabeca;

    if (fila_tamanho(fila)>1)
        fila -> cabeca = aux -> prox;

    else {
        fila -> cabeca = NULL;
        fila -> cauda = NULL;
    }
    free (aux);

    fila -> tamanho--;
    return 1;
}
 
/* Retorna o numero de elementos da fila, que pode ser 0. */
int fila_tamanho (fila_t *fila){
    
    return fila -> tamanho;
}

/* Retorna 1 se fila vazia, 0 em caso contrario. */ 
int fila_vazia (fila_t *fila){
    
    if (fila_tamanho(fila))
        return 0;

    return 1;
}
