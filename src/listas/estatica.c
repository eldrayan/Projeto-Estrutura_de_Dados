#include <stdio.h>
#include <stdbool.h>
#include "../../include/estatica.h" 

void inicializa_lista(ListaEstatica *l) {
    int i;
    l->inicio = -1;
    l->dispo = 0;
    for (i = 0; i < MAX - 1; i++) {
        l->dados[i].prox = i + 1;
    }
    l->dados[MAX - 1].prox = -1;
    l->quantidade = 0;
}

bool insere_elemento(ListaEstatica *l, int id, float nota) {
    if (l->dispo == -1) {
        return false; 
    }
    
    // Pega um nó da lista de disponíveis
    int novo = l->dispo;
    l->dispo = l->dados[novo].prox;
    
    // Insere os dados no nó
    l->dados[novo].id = id;
    l->dados[novo].nota = nota;
    l->dados[novo].prox = -1;
    
    // Se a lista está vazia
    if (l->inicio == -1) {
        l->inicio = novo;
    } else {
        int atual = l->inicio;
        while (l->dados[atual].prox != -1) {
            atual = l->dados[atual].prox;
        }
        l->dados[atual].prox = novo;
    }
    
    l->quantidade++;
    return true;
}

bool remove_elemento(ListaEstatica *l, int id) {
    if (l->inicio == -1) {
        return false;
    }
    
    int atual = l->inicio;
    int anterior = -1;
    
    // Busca o elemento
    while (atual != -1 && l->dados[atual].id != id) {
        anterior = atual;
        atual = l->dados[atual].prox;
    }
    
    // Elemento não encontrado
    if (atual == -1) {
        return false;
    }
    
    // Remove o elemento
    if (anterior == -1) {
        // Remove o primeiro elemento
        l->inicio = l->dados[atual].prox;
    } else {
        // Remove elemento do meio ou fim
        l->dados[anterior].prox = l->dados[atual].prox;
    }
    
    // Devolve o nó para a lista de disponíveis
    l->dados[atual].prox = l->dispo;
    l->dispo = atual;
    
    l->quantidade--;
    return true;
}

int busca_elemento(ListaEstatica *l, int id) {
    int atual = l->inicio;
    
    while (atual != -1) {
        if (l->dados[atual].id == id) {
            return atual; // Retorna o índice onde está o elemento
        }
        atual = l->dados[atual].prox;
    }
    
    return -1; 
}

void imprime_lista(ListaEstatica *l) {
    int atual = l->inicio;
    
    printf("Lista Estática (Total: %d elementos):\n", l->quantidade);
    
    if (atual == -1) {
        printf("Lista vazia.\n");
        return;
    }
    
    while (atual != -1) {
        printf("ID: %d, Nota: %.2f\n", l->dados[atual].id, l->dados[atual].nota);
        atual = l->dados[atual].prox;
    }
}

int tamanho_lista(ListaEstatica *l) {
    return l->quantidade;
}