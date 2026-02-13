#ifndef ESTATICA_H
#define ESTATICA_H

#include <stdbool.h>

#define MAX 10000 

// Estrutura do Aluno (Nó)
typedef struct {
    int id;
    float nota;
    int prox;
    int ant;  // Ponteiro para o nó anterior (lista duplamente encadeada)
} No;

// Estrutura de Controle da Lista
typedef struct {
    No dados[MAX]; 
    int inicio;          
    int dispo;           
    int quantidade;      
} ListaEstatica;

void inicializa_lista(ListaEstatica *l);
void insere_elemento(ListaEstatica *l, int id, float nota);
void remove_elemento(ListaEstatica *l, int id);
int busca_elemento(ListaEstatica *l, int id); 
void imprime_lista(ListaEstatica *l);
int tamanho_lista(ListaEstatica *l);

#endif