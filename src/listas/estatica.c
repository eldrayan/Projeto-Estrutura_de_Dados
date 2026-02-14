#include <stdio.h>
#include <stdbool.h>
#include "estatica.h" 

/**
 * Inicializa a lista duplamente encadeada estática.
 * 
 * Prepara a estrutura da lista, configurando o início como vazio (-1),
 * organizando a lista de nós disponíveis e inicializando os ponteiros
 * anterior e próximo de cada nó.
 * 
 * @param l Ponteiro para a estrutura ListaEstatica a ser inicializada
 */
void lista_estatica_inicializa(ListaEstatica *l) {
    int i;
    l->inicio = -1;
    l->dispo = 0;
    for (i = 0; i < MAX - 1; i++) {
        l->dados[i].prox = i + 1;
        l->dados[i].ant = -1;
    }
    l->dados[MAX - 1].prox = -1;
    l->dados[MAX - 1].ant = -1;
    l->quantidade = 0;
}

/**
 * Insere um novo elemento no final da lista duplamente encadeada.
 * 
 * Aloca um nó da lista de disponíveis, armazena os dados do aluno
 * (id e nota) e insere no final da lista, atualizando os ponteiros
 * anterior e próximo adequadamente.
 * 
 * @param l Ponteiro para a estrutura ListaEstatica
 * @param id Identificador único do aluno
 * @param nota Nota do aluno (valor decimal)
 */
void lista_estatica_insere(ListaEstatica *l, int id, float nota) {
    if (l->dispo == -1) {
        return; 
    }
    
    // Pega um nó da lista de disponíveis
    int novo = l->dispo;
    l->dispo = l->dados[novo].prox;
    
    // Insere os dados no nó
    l->dados[novo].id = id;
    l->dados[novo].nota = nota;
    l->dados[novo].prox = -1;
    l->dados[novo].ant = -1;
    
    // Se a lista está vazia
    if (l->inicio == -1) {
        l->inicio = novo;
    } else {
        int atual = l->inicio;
        while (l->dados[atual].prox != -1) {
            atual = l->dados[atual].prox;
        }
        l->dados[atual].prox = novo;
        l->dados[novo].ant = atual;  // Liga o ponteiro anterior
    }
    
    l->quantidade++;
}

/**
 * Remove um elemento da lista procurando pelo ID.
 * 
 * Busca o elemento com o ID especificado e o remove da lista,
 * ajustando os ponteiros anterior e próximo dos nós adjacentes.
 * O nó removido é devolvido para a lista de disponíveis para reutilização.
 * 
 * @param l Ponteiro para a estrutura ListaEstatica
 * @param id Identificador do elemento a ser removido
 */
void lista_estatica_remove(ListaEstatica *l, int id) {
    if (l->inicio == -1) {
        return;
    }
    
    int atual = l->inicio;
    
    // Busca o elemento
    while (atual != -1 && l->dados[atual].id != id) {
        atual = l->dados[atual].prox;
    }
    
    // Elemento não encontrado
    if (atual == -1) {
        return;
    }
    
    // Remove o elemento
    int anterior = l->dados[atual].ant;
    int proximo = l->dados[atual].prox;
    
    if (anterior == -1) {
        // Remove o primeiro elemento
        l->inicio = proximo;
        if (proximo != -1) {
            l->dados[proximo].ant = -1;
        }
    } else {
        // Remove elemento do meio ou fim
        l->dados[anterior].prox = proximo;
        if (proximo != -1) {
            l->dados[proximo].ant = anterior;
        }
    }
    
    // Devolve o nó para a lista de disponíveis
    l->dados[atual].prox = l->dispo;
    l->dados[atual].ant = -1;
    l->dispo = atual;
    
    l->quantidade--;
}

/**
 * Busca um elemento na lista pelo ID.
 * 
 * Percorre a lista sequencialmente procurando por um elemento
 * com o ID especificado.
 * 
 * @param l Ponteiro para a estrutura ListaEstatica
 * @param id Identificador do elemento a ser buscado
 * @return Índice do nó no array onde o elemento está armazenado, ou -1 se não encontrado
 */
int lista_estatica_busca(ListaEstatica *l, int id) {
    int atual = l->inicio;
    
    while (atual != -1) {
        if (l->dados[atual].id == id) {
            return atual; // Retorna o índice onde está o elemento
        }
        atual = l->dados[atual].prox;
    }
    
    return -1; 
}

/**
 * Imprime todos os elementos da lista na ordem de encadeamento.
 * 
 * Percorre a lista do início ao fim, exibindo o ID e a nota de cada aluno.
 * Se a lista estiver vazia, exibe uma mensagem informativa.
 * 
 * @param l Ponteiro para a estrutura ListaEstatica
 */
void lista_estatica_imprime(ListaEstatica *l) {
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

/**
 * Retorna o número de elementos atualmente armazenados na lista.
 * 
 * @param l Ponteiro para a estrutura ListaEstatica
 * @return Quantidade de elementos na lista
 */
int lista_estatica_tamanho(ListaEstatica *l) {
    return l->quantidade;
}