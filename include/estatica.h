#ifndef ESTATICA_H
#define ESTATICA_H

#include <stdbool.h>

#define MAX 10000 

// Estrutura do Aluno (Nó)
typedef struct {
    int id;
    float nota;
    int prox;  
} No;

// Estrutura de Controle da Lista
typedef struct {
    No dados[MAX]; 
    int inicio;          
    int dispo;           
    int quantidade;      
} ListaEstatica;

void inicializa_lista(ListaEstatica *l);
bool insere_elemento(ListaEstatica *l, int id, float nota);
bool remove_elemento(ListaEstatica *l, int id);
int busca_elemento(ListaEstatica *l, int id); 
void imprime_lista(ListaEstatica *l);
int tamanho_lista(ListaEstatica *l);

#endif