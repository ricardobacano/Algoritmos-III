#ifndef __AVL__
#define __AVL__
#include "lib_bsttree.h"

/**
 * Compara dois valores de chave e retorna o maior.
 * Esta função é utilizada para determinar o maior valor
 * entre dois inteiros.
 *
 * @param key_1 O primeiro valor de chave.
 * @param key_2 O segundo valor de chave.
 * @return O maior valor entre key_1 e key_2.
 */
int max_key(int key_1, int key_2);

/**
 * Retorna o nó com o maior valor em uma subárvore.
 * A função percorre a subárvore à direita para encontrar
 * o nó que contém o maior valor de chave.
 *
 * @param node_tree A raiz da subárvore.
 * @return Um ponteiro para o nó com o maior valor na subárvore.
 */
struct node *find_max_node(struct node *node_tree);

/**
 * Realiza uma rotação à esquerda em um nó.
 * A rotação ajusta os ponteiros para reequilibrar a árvore,
 * movendo o filho direito para a posição do nó e ajustando
 * os filhos de ambos.
 *
 * @param node_tree O nó onde será realizada a rotação à esquerda.
 * @return Um ponteiro para a nova raiz após a rotação.
 */
struct node *rotate_left(struct node *node_tree);

/**
 * Realiza uma rotação à direita em um nó.
 * A rotação ajusta os ponteiros para reequilibrar a árvore,
 * movendo o filho esquerdo para a posição do nó e ajustando
 * os filhos de ambos.
 *
 * @param node_tree O nó onde será realizada a rotação à direita.
 * @return Um ponteiro para a nova raiz após a rotação.
 */
struct node *rotate_right(struct node *node_tree);

/**
 * Realiza o balanceamento da árvore.
 * A função verifica o fator de balanceamento do nó e, caso
 * seja necessário, aplica rotações simples ou duplas para
 * reequilibrar a árvore AVL.
 *
 * @param node_tree A raiz da árvore a ser balanceada.
 * @return Um ponteiro para a raiz da árvore balanceada.
 */
struct node *tree_balancing(struct node *node_tree);

/**
 * Retorna o fator de balanceamento de um nó.
 * O fator de balanceamento é a diferença entre a altura
 * do filho esquerdo e a altura do filho direito.
 * Usado para determinar a necessidade de rotação.
 *
 * @param node_tree O nó para o qual será calculado o fator de balanceamento.
 * @return O fator de balanceamento do nó.
 */
int node_balance(struct node *node_tree);

/**
 * Retorna a diferença entre os fatores de balanceamento dos filhos.
 * Essa função é usada para verificar o grau de desbalanceamento
 * de um nó, considerando a diferença entre seus filhos esquerdo
 * e direito.
 *
 * @param node_tree O nó para o qual a diferença será calculada.
 * @return A diferença entre o balanceamento dos filhos.
 */
int balancing_test(struct node *node_tree);

#endif
