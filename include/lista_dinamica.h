#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

struct no {
    struct no *ant;
    int id;
    float nota;
    struct no *prox;
};

typedef struct no No;

struct lista {
    No *inicio;
    No *fim;
    int quantidade;
};

typedef struct lista ListaDinamica;

/**
 * @brief Aloca e inicializa a estrutura de controle da lista.
 * * Cria a estrutura da lista dinâmica, definindo os ponteiros
 * * de início e fim como NULL e a quantidadee como 0.
 * 
 * @return Lista* Ponteiro para a nova lista criada e zerada.
 */
ListaDinamica* inicializa_lista(void);

/**
 * @brief Cria um novo Nó e o insere ao fim da lista encadeada.
 * * Realiza a alocação dinâmica de um Nó e atualiza os ponteiros 'fim' da lista
 * * para garantir inserção em tempo constante.
 * 
 * @param lista Ponteiro para a lista onde o elemento será inserido
 * @param id Identificador único do aluno
 * @param nota Valor da nota do aluno
 */
void insere_elemento(ListaDinamica *lista, int id, float nota);

/**
 * @brief Percorre a lista e imprime os dados de todos os nós no console.
 * * Exibe o ID e a Nota de cada aluno.
 * Caso a lista esteja vazia, informa o usuário adequadamente.
 * 
 * @param lista Ponterio para a lista a ser exibida
 */
void imprimir_lista(ListaDinamica *lista);

/**
 * @brief Percorre a lista em ordem invertida e imprime os dados de todos os nós no console.
 * * Exibe o ID e a Nota de cada aluno.
 * Caso a lista esteja vazia, informa o usuário adequadamente.
 * 
 * @param lista Ponteiro para a lista a ser exibida
 */
void imprimir_inverso(ListaDinamica *lista);

/**
 * @brief Procura a posição (índice) de um elemento pelo seu ID.
 * Percorre a lista sequencialmente a partir do início.
 * 
 * @param lista Ponteiro para a lista onde a busca deve ser realizada
 * @param id_alvo O ID do aluno que se deseja encontrar
 * @return int O índice do elemento (iniciando em 0) ou -1 caso não seja encontrado
 */
int busca_elemento(ListaDinamica *lista, int id_alvo);

/**
 * @brief Localiza, remove e desaloca um elemento da lista através do ID.
 * Trata automaticamente os casos de remoção no início, meio ou fim da lista, 
 * garantindo que a integridade dos ponteiros e a contagem sejam mantidas.
 * 
 * @param lista Ponteiro para a lista de onde o elemento será removido
 * @param id_alvo O ID do aluno a ser excluído
 */
void remove_elemento(ListaDinamica *lista, int id_alvo);

/**
 * @brief Libera toda a memória dinâmica utilizada pela lista.
 * Percorre todos os nós dando free individualmente e, por fim,
 * libera a estrutura de controle da Lista.
 * 
 * @param lista Ponterio para a lista que será destruída.
 */
void libera_lista(ListaDinamica *lista);

#endif