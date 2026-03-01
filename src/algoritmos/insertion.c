#include "insertion.h"
#include "lista_dinamica.h"
#include "estatica.h"
#include <stddef.h>

// Insertion Sort para vetor - ordena as notas dos alunos de maneira crescente

void insertion_sort(Aluno v[], int n) {
    for (int i = 1; i < n; i++) {
        Aluno chave = v[i];
        int j = i - 1;
        
        // Move elementos maiores que a chave uma posição à frente
        while (j >= 0 && v[j].nota > chave.nota) {
            v[j + 1] = v[j];
            j--;
        }
        
        // Insere a chave na posição correta
        v[j + 1] = chave;
    }
}

// Insertion Sort para Lista Dinâmica - ordena por nota (crescente)
// Reconecta os ponteiros para inserir o nó na posição correta
void insertion_sort_dinamica(ListaDinamica *l) {
    if (l == NULL || l->quantidade < 2) {
        return; // lista vazia ou com 1 elemento já está ordenada
    }
    
    // O primeiro nó já está "ordenado", começamos do segundo
    NoDinamico *atual = l->inicio->prox;
    
    while (atual != NULL) {
        NoDinamico *proximo = atual->prox; // guarda o próximo antes de mover atual
        
        // Remove o nó atual da sua posição
        if (atual->ant != NULL) {
            atual->ant->prox = atual->prox;
        }
        if (atual->prox != NULL) {
            atual->prox->ant = atual->ant;
        } else {
            l->fim = atual->ant; // se era o último, atualiza o fim
        }
        
        // Busca a posição correta para inserir o nó
        NoDinamico *posicao = l->inicio;
        
        // Se deve ser inserido antes do primeiro nó
        if (atual->nota < l->inicio->nota) {
            // Insere no início
            atual->prox = l->inicio;
            atual->ant = NULL;
            l->inicio->ant = atual;
            l->inicio = atual;
        } else {
            // Procura a posição onde inserir
            while (posicao->prox != NULL && posicao->prox->nota < atual->nota) {
                posicao = posicao->prox;
            }
            
            // Insere após 'posicao'
            atual->prox = posicao->prox;
            atual->ant = posicao;
            
            if (posicao->prox != NULL) {
                posicao->prox->ant = atual;
            } else {
                l->fim = atual; // se inserir no fim, atualiza o fim
            }
            
            posicao->prox = atual;
        }
        
        // Avança para o próximo nó não ordenado
        atual = proximo;
    }
}

// Insertion Sort para Lista Estática - ordena por nota (crescente)
// Ajusta os índices .prox para simular a inserção na posição correta
void insertion_sort_estatica(ListaEstatica *l) {
    if (l == NULL || l->quantidade < 2) {
        return; // lista vazia ou com 1 elemento já está ordenada
    }
    
    // O primeiro nó já está "ordenado", começamos do segundo
    int atual_idx = l->dados[l->inicio].prox;
    
    while (atual_idx != -1) {
        int proximo_idx = l->dados[atual_idx].prox; // guarda o próximo antes de mover atual
        float nota_atual = l->dados[atual_idx].nota;
        
        // Remove o nó atual da cadeia
        int ant_idx = l->dados[atual_idx].ant;
        
        if (ant_idx != -1) {
            l->dados[ant_idx].prox = l->dados[atual_idx].prox;
        }
        if (l->dados[atual_idx].prox != -1) {
            l->dados[l->dados[atual_idx].prox].ant = ant_idx;
        }
        
        // Busca a posição correta para inserir o nó
        // Se deve ser inserido antes do primeiro nó
        if (nota_atual < l->dados[l->inicio].nota) {
            // Insere no início
            l->dados[atual_idx].prox = l->inicio;
            l->dados[atual_idx].ant = -1;
            l->dados[l->inicio].ant = atual_idx;
            l->inicio = atual_idx;
        } else {
            // Procura a posição onde inserir
            int posicao_idx = l->inicio;
            
            while (l->dados[posicao_idx].prox != -1 && 
                   l->dados[l->dados[posicao_idx].prox].nota < nota_atual) {
                posicao_idx = l->dados[posicao_idx].prox;
            }
            
            // Insere após 'posicao_idx'
            l->dados[atual_idx].prox = l->dados[posicao_idx].prox;
            l->dados[atual_idx].ant = posicao_idx;
            
            if (l->dados[posicao_idx].prox != -1) {
                l->dados[l->dados[posicao_idx].prox].ant = atual_idx;
            }
            
            l->dados[posicao_idx].prox = atual_idx;
        }
        
        // Avança para o próximo nó não ordenado
        atual_idx = proximo_idx;
    }
}
