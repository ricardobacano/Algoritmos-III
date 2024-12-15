#include <stdio.h>
#include <stdlib.h>
#include "lib_avltree.h"
#include "lib_bsttree.h"

// Função para criar um novo nó com uma chave específica
struct node *create_node(int value_key)
{
    // Aloca memória para o novo nó
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL) {
        exit(1);  // Sai do programa se a alocação falhar
    }
    
    // Inicializa o novo nó
    new_node->key = value_key;    
    new_node->left = NULL;        
    new_node->right = NULL;       
    new_node->father = NULL;      
    new_node->height = 0;         

    return new_node;  // Retorna o ponteiro para o novo nó
}

// Função para deletar um nó da árvore com base na chave
struct node *delete_node(struct node *root, int value_key)
{
    if(root == NULL) {
        return root;  // Retorna se a árvore estiver vazia
    }

    // Se o nó a ser deletado for encontrado
    if(value_key == root->key){
        // Caso o nó tenha dois filhos
        if(root->left && root->right)
        {
            root = transplant_node(root);  // Substitui pelo antecessor
        }
        // Caso o nó tenha apenas o filho à esquerda
        else if(root->left && !root->right)
        {   
            root->key = root->left->key;   
            free(root->left);              
            root->left = NULL;             
        }
        // Caso o nó tenha apenas o filho à direita
        else if(!root->left && root->right)
        {   
            root->key = root->right->key; 
            free(root->right);            
            root->right = NULL;            
        }
        // Caso o nó seja uma folha (sem filhos)
        else {
            free(root);                    
            return NULL;                  
        }
    }
    // Caso a chave seja menor que a chave do nó atual, move para a subárvore esquerda
    else if(value_key < root->key)    
        root->left = delete_node(root->left, value_key);
    // Caso a chave seja maior, move para a subárvore direita
    else
        root->right = delete_node(root->right, value_key);   

    // Balanceia a árvore após a exclusão
    root = tree_balancing(root);

    return root;  // Retorna a raiz da árvore
}

// Função para inserir um novo nó com uma chave na árvore
struct node *insert_node(struct node *root, int value_key)
{
    if (root == NULL) {
        struct node *new_node = create_node(value_key);  // Cria um novo nó
        return new_node;  // Retorna o novo nó se a árvore estava vazia
    }

    // Se a chave a ser inserida é menor, insere na subárvore esquerda
    if (value_key < root->key) {
        root->left = insert_node(root->left, value_key);  // Chama recursivamente para a esquerda
        root->left->father = root;  // Atualiza o pai do novo nó
    } 

    // Se a chave a ser inserida é maior, insere na subárvore direita
    if (value_key > root->key) {
        root->right = insert_node(root->right, value_key);  // Chama recursivamente para a direita
        root->right->father = root;  // Atualiza o pai do novo nó
    }

    // Balanceia a árvore após a inserção
    root = tree_balancing(root);

    return root;  // Retorna a raiz da árvore (potencialmente balanceada)
}

// Função para substituir o nó deletado pelo antecessor
struct node *transplant_node(struct node *root)
{
    struct node *predecessor;

    // Encontra o nó com a maior chave na subárvore esquerda (antecessor)
    predecessor = find_max_node(root->left);  
    root->key = predecessor->key;  // Copia a chave do antecessor para o nó atual
    root->left = delete_node(root->left, predecessor->key);  // Deleta o antecessor

    return root;  // Retorna o nó atualizado
}

// Função para imprimir os nós da árvore em ordem 
void inoder(struct node *root, int height_node)
{
    if(root != NULL)
    {
        inoder(root->left, height_node + 1);  
        printf("%d,%d\n", root->key, height_node);  
        inoder(root->right, height_node + 1);  
    }
}
