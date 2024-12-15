#ifndef _RB_LIB_
#define _RB_LIB_

// Enum das cores do nó
typedef enum { RED, BLACK } Color;

// Estrutura da árvore
typedef struct rb_tree {
    struct rb_node* root;  // Nó raiz da árvore
} rb_tree_t;

// Estrutura do nó
typedef struct rb_node {
    int key;               // Chave (valor) do nó
    Color color;             // Cor do nó (VERMELHO ou PRETO)
    char letter;           // Primeira letra associada à chave
    struct rb_node* parent; // Ponteiro para o nó pai
    struct rb_node* left;  // Ponteiro para o nó filho à esquerda
    struct rb_node* right; // Ponteiro para o nó filho à direita
} rb_node_t;

/**
 * Cria uma nova Árvore Vermelho-Preto.
 * @return Um ponteiro para a nova árvore vermelha-preta criada.
 */
rb_tree_t* create_rb_tree();

/**
 * Deleta todos os nós da árvore Vermelho-Preto e libera a memória alocada.
 * @param tree A árvore a ser deletada.
 */
void delete_rb_tree(rb_tree_t* tree);

/**
 * Aloca memória para um novo nó e retorna o ponteiro para ele.
 * @param key A chave (valor) do nó.
 * @param letter A primeira letra associada à chave.
 * @return Um ponteiro para o novo nó criado.
 */
rb_node_t* create_rb_node(int key, char letter);

/**
 * Insere um novo nó na árvore Vermelho-Preto.
 * @param tree A árvore Vermelho-Preto onde o nó será inserido.
 * @param key A chave (valor) a ser inserida.
 * @param letter A primeira letra associada à chave.
 * @return 1 se a inserção for bem-sucedida, 0 se a chave já existir na árvore.
 */
int insert_rb_node(rb_tree_t* tree, int key, char letter);

/**
 * Realiza uma travessia em ordem da árvore e imprime os detalhes dos nós.
 * @param tree A árvore Vermelho-Preto a ser percorrida.
 */
void inorder_traversal_rb_tree(rb_tree_t* tree);

/**
 * Busca um nó com a chave fornecida na árvore Vermelho-Preto.
 * @param tree A árvore Vermelho-Preto onde a busca será realizada.
 * @param key A chave a ser buscada.
 * @return A letra associada à chave se encontrada, caso contrário '\0'.
 */
char search_rb_tree(rb_tree_t* tree, int key);

/**
 * Garante que todos os caracteres da tabela ASCII farão parte da estrutura de decodificação.
 * @param tree A árvore Vermelho-Preto onde os caracteres serão inseridos.
 * @param table A tabela ASCII onde a presença de cada caractere será verificada.
 * @param i O índice atual para inserir os caracteres.
 */
void integrate_rb_tree(rb_tree_t* tree, char table[], int i);

/**
 * Busca o nó com a chave fornecida na árvore Vermelho-Preto.
 * @param tree A árvore Vermelho-Preto onde a busca será realizada.
 * @param key A chave a ser buscada.
 * @return Um ponteiro para o nó com a chave fornecida, caso encontrado.
 */
rb_node_t* search_node_rb_tree(rb_tree_t* tree, int key);

/**
 * Realiza a rotação à esquerda em um nó.
 * @param node O nó que sofrerá a rotação à esquerda.
 */
void rotate_left(rb_node_t* node);

/**
 * Realiza a rotação à direita em um nó.
 * @param node O nó que sofrerá a rotação à direita.
 */
void rotate_right(rb_node_t* node);

/**
 * Encontra o antecessor (máximo da subárvore esquerda) de um nó.
 * @param node O nó cujo antecessor será encontrado.
 * @return O antecessor do nó.
 */
rb_node_t* find_predecessor(rb_node_t* node);

/**
 * Remove um nó da árvore Vermelho-Preto.
 * @param tree A árvore Vermelho-Preto da qual o nó será removido.
 * @param key A chave do nó a ser removido.
 */
void remove_rb_node(rb_tree_t* tree, int key);

/**
 * Retorna a cor de um nó.
 * @param node O nó cuja cor será verificada.
 * @return A cor do nó (PRETO ou VERMELHO).
 */
Color get_color(rb_node_t* node);

/**
 * Realiza o balanceamento da árvore após a remoção de um nó.
 * @param tree A árvore Vermelho-Preto a ser balanceada.
 * @param node O nó que está sendo removido.
 */
void balance_removal(rb_tree_t* tree, rb_node_t* node);

/**
 * Imprime os nós da árvore em uma travessia em ordem, mostrando o nível de cada nó.
 * @param node O nó a ser impresso.
 * @param level O nível do nó na árvore.
 */
void print_rb_tree_inorder(rb_node_t* node, int level);

/**
 * Inicia a impressão da árvore Vermelho-Preto.
 * @param tree A árvore Vermelho-Preto a ser impressa.
 */
void print_rb_tree(rb_tree_t* tree);

#endif