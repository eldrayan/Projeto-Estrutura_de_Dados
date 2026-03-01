#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

/**
 * @brief Representa um Nó (elemento) da lista duplamente encadeada.
 * Armazena os dados do aluno e os ponteiros para navegar
 * em ambas as direções (trás e frente).
 */
struct no_dinamico {
    struct no_dinamico *ant;     ///< Ponteiro para o nó anterior (NULL se for o 1º)
    int id;             ///< Identificador único do aluno
    float nota;         ///< Nota obtida pelo aluno
    struct no_dinamico *prox;    ///< Ponteiro para o próximo nó (NULL se for o último)
};

/**
 * @brief Representa um Nó (elemento) da lista duplamente encadeada.
 * Armazena os dados do aluno e os ponteiros para navegar
 * em ambas as direções (trás e frente).
 */
typedef struct no_dinamico NoDinamico;

/**
 * @brief Estrutura de controle da Lista Dinâmica Duplamente Encadeada.
 * Mantém os metadados necessários para operações O(1) nas pontas
 * e gerencia o tamanho atual da coleção.
 */
struct lista_dinamica {
    NoDinamico *inicio;         ///< Aponta para o primeiro elemento da lista
    NoDinamico *fim;            ///< Aponta para o último elemento (facilita inserção no fim)
    int quantidade;     ///< Contador de elementos ativos (para acesso rápido ao tamanho)
};

/**
 * @brief Estrutura de controle da Lista Dinâmica Duplamente Encadeada.
 * Mantém os metadados necessários para operações O(1) nas pontas
 * e gerencia o tamanho atual da coleção.
 */
typedef struct lista_dinamica ListaDinamica;

/**
 * @brief Aloca e inicializa a estrutura de controle da lista.
 * * Cria a estrutura da lista dinâmica, definindo os ponteiros
 * * de início e fim como NULL e a quantidadee como 0.
 * 
 * @return Lista* Ponteiro para a nova lista criada e zerada.
 */
ListaDinamica* lista_dinamica_inicializa(void);

/**
 * @brief Cria um novo Nó e o insere ao fim da lista encadeada.
 * * Realiza a alocação dinâmica de um Nó e atualiza os ponteiros 'fim' da lista
 * * para garantir inserção em tempo constante.
 * 
 * @param lista Ponteiro para a lista onde o elemento será inserido
 * @param id Identificador único do aluno
 * @param nota Valor da nota do aluno
 */
void lista_dinamica_insere(ListaDinamica *lista, int id, float nota);

/**
 * @brief Percorre a lista e imprime os dados de todos os nós no console.
 * * Exibe o ID e a Nota de cada aluno.
 * Caso a lista esteja vazia, informa o usuário adequadamente.
 * 
 * @param lista Ponterio para a lista a ser exibida
 */
void lista_dinamica_imprimir(ListaDinamica *lista);

/**
 * @brief Percorre a lista em ordem invertida e imprime os dados de todos os nós no console.
 * * Exibe o ID e a Nota de cada aluno.
 * Caso a lista esteja vazia, informa o usuário adequadamente.
 * 
 * @param lista Ponteiro para a lista a ser exibida
 */
void lista_dinamica_imprimir_inverso(ListaDinamica *lista);

/**
 * @brief Procura a posição (índice) de um elemento pelo seu ID.
 * Percorre a lista sequencialmente a partir do início.
 * 
 * @param lista Ponteiro para a lista onde a busca deve ser realizada
 * @param id_alvo O ID do aluno que se deseja encontrar
 * @return int O índice do elemento (iniciando em 0) ou -1 caso não seja encontrado
 */
int lista_dinamica_busca(ListaDinamica *lista, int id_alvo);

/**
 * @brief Localiza, remove e desaloca um elemento da lista através do ID.
 * Trata automaticamente os casos de remoção no início, meio ou fim da lista, 
 * garantindo que a integridade dos ponteiros e a contagem sejam mantidas.
 * 
 * @param lista Ponteiro para a lista de onde o elemento será removido
 * @param id_alvo O ID do aluno a ser excluído
 */
void lista_dinamica_remove(ListaDinamica *lista, int id_alvo);

/**
 * @brief Libera toda a memória dinâmica utilizada pela lista.
 * Percorre todos os nós dando free individualmente e, por fim,
 * libera a estrutura de controle da Lista.
 * 
 * @param lista Ponterio para a lista que será destruída.
 */
void lista_dinamica_libera(ListaDinamica *lista);

#endif