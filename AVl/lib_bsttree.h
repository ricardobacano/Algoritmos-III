#ifndef __BST__
#define __BST__

struct node {
    int key;
    struct node *left;
    struct node *right;
    struct node *father;
    int height;
};

/**
 * Cria um novo nó para a árvore.
 * O nó é inicializado com um valor de chave fornecido,
 * e seus ponteiros para os filhos (esquerda e direita) 
 * e o pai são definidos como NULL.
 * A altura do nó é inicialmente definida como 0.
 *
 * @param value_key O valor da chave para o novo nó.
 * @return Um ponteiro para o nó recém-criado.
 */
struct node *create_node(int value_key);

/**
 * Insere um nó com um valor de chave fornecido na árvore.
 * A inserção mantém a propriedade da árvore binária de busca,
 * posicionando o novo nó na posição correta.
 *
 * @param root A raiz da árvore onde o nó será inserido.
 * @param value_key O valor da chave do nó a ser inserido.
 * @return Um ponteiro para a raiz da árvore modificada.
 */
struct node *insert_node(struct node *root, int value_key);

/**
 * Remove um nó da árvore.
 * A função mantém a estrutura da árvore binária de busca
 * após a exclusão, ajustando os ponteiros dos nós afetados.
 *
 * @param root A raiz da árvore onde o nó será removido.
 * @return Um ponteiro para a raiz da árvore modificada.
 */
struct node *delete_node(struct node *root, int value_key);

/**
 * Substitui um nó por outro na árvore.
 * Essa função é tipicamente usada durante o processo de exclusão
 * para substituir um nó pelo seu filho.
 *
 * @param root A raiz da árvore.
 * @param value_key O valor da chave do nó a ser substituído.
 * @return Um ponteiro para a raiz da árvore modificada.
 */
struct node *transplant_node(struct node *root);

/**
 * Realiza a travessia em ordem da árvore.
 * Percorre a árvore visitando primeiro o filho esquerdo,
 * depois o nó atual, e por fim o filho direito, imprimindo
 * os valores em ordem crescente.
 *
 * @param root A raiz da árvore a ser percorrida.
 * @param height_node Um valor que pode ser usado para controle da altura ou profundidade.
 */
void inoder(struct node *root, int height_node);

#endif
