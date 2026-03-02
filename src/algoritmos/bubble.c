#include "bubble.h"
#include <stddef.h>

// Bubble Sort = ordena as notas dos alunos de maneira crescente

void bubble_sort(Aluno v[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        
        // flag para detectar se houve troca
        int trocou = 0;
        
        // percorre array comparando elementos adjacentes
        for (int j = 0; j < n - 1 - i; j++) {
            
            // se elemento atual for maior que o próximo, troca
            if (v[j].nota > v[j + 1].nota) {
                Aluno temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        
        // se não houve troca, o array já está ordenado
        if (!trocou) {
            break;
        }
    }
}

// Bubble Sort para Lista Dinâmica - ordena por nota (crescente)
// Troca apenas os dados (id e nota), mantém os ponteiros intactos
void bubble_sort_dinamica(ListaDinamica *l) {
    if (l == NULL || l->quantidade < 2) {
        return; // lista vazia ou com 1 elemento já está ordenada
    }
    
    int n = l->quantidade;
    
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        NoDinamico *atual = l->inicio;
        
        // percorre a lista comparando nós adjacentes
        for (int j = 0; j < n - 1 - i; j++) {
            if (atual->prox == NULL) {
                break;
            }
            
            // compara nota do nó atual com o próximo
            if (atual->nota > atual->prox->nota) {
                // troca apenas os dados (id e nota), não os ponteiros
                int temp_id = atual->id;
                float temp_nota = atual->nota;
                
                atual->id = atual->prox->id;
                atual->nota = atual->prox->nota;
                
                atual->prox->id = temp_id;
                atual->prox->nota = temp_nota;
                
                trocou = 1;
            }
            
            atual = atual->prox;
        }
        
        // se não houve troca, a lista já está ordenada
        if (!trocou) {
            break;
        }
    }
}

// Bubble Sort para Lista Estática - ordena por nota (crescente)
// Troca apenas os dados (id e nota), mantém os índices intactos
void bubble_sort_estatica(ListaEstatica *l) {
    if (l == NULL || l->quantidade < 2) {
        return; // lista vazia ou com 1 elemento já está ordenada
    }
    
    int n = l->quantidade;
    
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        int atual = l->inicio;
        
        // percorre a lista comparando nós adjacentes
        for (int j = 0; j < n - 1 - i; j++) {
            if (l->dados[atual].prox == -1) {
                break;
            }
            
            int proximo = l->dados[atual].prox;
            
            // compara nota do nó atual com o próximo
            if (l->dados[atual].nota > l->dados[proximo].nota) {
                // troca apenas os dados (id e nota), não os índices
                int temp_id = l->dados[atual].id;
                float temp_nota = l->dados[atual].nota;
                
                l->dados[atual].id = l->dados[proximo].id;
                l->dados[atual].nota = l->dados[proximo].nota;
                
                l->dados[proximo].id = temp_id;
                l->dados[proximo].nota = temp_nota;
                
                trocou = 1;
            }
            
            atual = l->dados[atual].prox;
        }
        
        // se não houve troca, a lista já está ordenada
        if (!trocou) {
            break;
        }
    }
}
