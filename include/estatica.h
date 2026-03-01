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
} NoEstatico;

// Estrutura de Controle da Lista
typedef struct {
    NoEstatico dados[MAX]; 
    int inicio;          
    int dispo;           
    int quantidade;      
} ListaEstatica;

void lista_estatica_inicializa(ListaEstatica *l);
void lista_estatica_insere(ListaEstatica *l, int id, float nota);
void lista_estatica_remove(ListaEstatica *l, int id);
int lista_estatica_busca(ListaEstatica *l, int id); 
void lista_estatica_imprime(ListaEstatica *l);
int lista_estatica_tamanho(ListaEstatica *l);

#endif