#include <stdio.h>
#include <stdlib.h>
#include "lib_avltree.h"
#include "lib_bsttree.h"

// ************************* Funções de máximo ********************************

// Função para retornar o maior entre duas chaves
int max_key(int key_1, int key_2)
{
    if (key_1 > key_2)
        return key_1;  // Retorna key_1 se for maior que key_2
    return key_2;      // Caso contrário, retorna key_2
}

// Função para encontrar o nó com a maior chave em uma árvore
struct node *find_max_node(struct node *node_tree)
{
    // Percorre a subárvore direita até encontrar o último nó
    while(node_tree->right != NULL)
    {
        node_tree = node_tree->right;
    }  

    return node_tree;  // Retorna o nó que contém a maior chave
}

// ************************* Funções de rotação ********************************

// Função para realizar rotação à esquerda
struct node *rotate_left(struct node *node_tree)
{
    struct node *aux = node_tree->right;   // O nó à direita se torna o novo nó raiz temporário
    
    // Atualiza os nós com uma troca
    node_tree->right = aux->left;          
    aux->father = node_tree->father;       
    node_tree->father = aux;               

    // Se a subárvore esquerda de aux não for nula, atualiza o pai de aux->left
    if(aux->left != NULL)
        aux->left->father = node_tree;  
    aux->left = node_tree;                 // Coloca o nó original à esquerda do novo nó raiz

    // Ajusta as referências do pai do novo nó para garantir que a árvore esteja conectada corretamente
    if(aux->father != NULL)
    {
        if(aux->father->left == node_tree) {
            aux->father->left = aux;
        }
        else if(aux->father->right == node_tree) {
            aux->father->right = aux;
        }
    }

    // Atualiza as alturas dos nós envolvidos na rotação
    node_tree->height = max_key(node_balance(node_tree->left), node_balance(node_tree->right)) + 1;
    aux->height = max_key(node_balance(aux->left), node_balance(aux->right)) + 1;

    return aux;  // Retorna a nova raiz da subárvore
}

// Função para realizar rotação à direita
struct node *rotate_right(struct node *node_tree)
{
    struct node *aux = node_tree->left;    // O nó à esquerda se torna o novo nó raiz temporário

    // Atualiza os nós com uma troca
    node_tree->left = aux->right;          
    aux->father = node_tree->father;       
    node_tree->father = aux;               

    // Se a subárvore direita de aux não for nula, atualiza o pai de aux->right
    if(aux->right != NULL) 
        aux->right->father = node_tree;
    aux->right = node_tree;                // Coloca o nó original à direita do novo nó raiz

    // Ajusta as referências do pai do novo nó para garantir que a árvore esteja conectada corretamente
    if(aux->father != NULL)
    {
        if(aux->father->left == node_tree) {
            aux->father->left = aux;
        }
        else if(aux->father->right == node_tree) {
            aux->father->right = aux;
        }
    }

    // Atualiza as alturas dos nós envolvidos na rotação
    node_tree->height = max_key(node_balance(node_tree->left), node_balance(node_tree->right)) + 1;
    aux->height = max_key(node_balance(aux->left), node_balance(aux->right)) + 1;

    return aux;  // Retorna a nova raiz da subárvore
}

// ************************* Funções de balanceamento ********************************

// Função para balancear a árvore AVL
struct node *tree_balancing(struct node *node_tree)
{
    int current_balance;
    int subtree_balance;

    if (node_tree == NULL) {
        return NULL;  // Se a árvore estiver vazia, retorna NULL
    }

    // Atualiza a altura do nó atual
    node_tree->height = max_key(node_balance(node_tree->left), node_balance(node_tree->right)) + 1;
    
    current_balance = balancing_test(node_tree);  // Calcula o balanceamento do nó atual

    // Se a árvore está desbalanceada para a esquerda (balanceamento > 1)
    if (current_balance > 1) {
        subtree_balance = balancing_test(node_tree->left);  // Verifica o balanceamento da subárvore esquerda

        // Caso a subárvore esquerda esteja desbalanceada para a esquerda, faz rotação simples à direita
        if (subtree_balance > 0) {
            return rotate_right(node_tree);
        }
        // Caso contrário, faz rotação dupla (esquerda-direita)
        else {
            node_tree->left = rotate_left(node_tree->left);
            return rotate_right(node_tree);
        }
    }

    // Se a árvore está desbalanceada para a direita (balanceamento < -1)
    if (current_balance < -1) {
        subtree_balance = balancing_test(node_tree->right);  // Verifica o balanceamento da subárvore direita

        // Caso a subárvore direita esteja desbalanceada para a direita, faz rotação simples à esquerda
        if (subtree_balance < 0) {
            return rotate_left(node_tree);
        }
        // Caso contrário, faz rotação dupla (direita-esquerda)
        else {
            node_tree->right = rotate_right(node_tree->right);
            return rotate_left(node_tree);
        }
    }

    return node_tree;  // Retorna o nó atual se estiver balanceado
}

// Função para calcular o balanceamento de um nó 
// (diferença entre altura da subárvore esquerda e direita)
int balancing_test(struct node *node_tree)
{
    int right_balance;
    int left_balance;

    left_balance = node_balance(node_tree->left);  // Altura da subárvore esquerda
    right_balance = node_balance(node_tree->right);  // Altura da subárvore direita

    return left_balance - right_balance;  // Retorna a diferença entre as alturas
}

// Função para obter a altura de um nó
int node_balance(struct node *node_tree)
{
    if(node_tree == NULL) 
    {
        return -1;  // Retorna -1 se o nó for NULL (indicando que estamos antes das folhas)
    }

    return node_tree->height;  // Retorna a altura do nó
}
