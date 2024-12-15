#include<stdio.h> 
#include<stdlib.h>
#include"librb.h"

#define ASCII_TABLE 256

// cria a árvore 
rb_tree_t* create_rb_tree() {
    rb_tree_t* tree;
    tree = malloc(sizeof(rb_tree_t));  
    if (!tree) {
        perror("Erro de alocação de memória\n");  
        return NULL;
    }
    tree->root = NULL;  
    return tree;    
} 

// deleta um nó e libera a memória alocada
void delete_rb_node(rb_node_t* node) {
    if (node->left != NULL)  
        delete_rb_node(node->left);
    
    if (node->right != NULL)  
        delete_rb_node(node->right);
    
    node->key = 0;  
    node->color = RED;  
    node->letter = '0'; 
    node->parent = NULL;  
    free(node);  
}

// deleta a arvore e libera a memoria 
void delete_rb_tree(rb_tree_t* tree) {
    if (tree->root != NULL)
        delete_rb_node(tree->root);  
    
    free(tree); 
} 

// função para criar no
rb_node_t* create_rb_node(int key, char letter) {
    rb_node_t *node;
    node = malloc(sizeof(rb_node_t));  
    if (!node) {
        perror("Erro ao alocar memória\n");  
        return NULL;
    }

    node->key = key;  
    node->letter = letter; 
    node->color = RED; 

    node->parent = NULL;  
    node->left = NULL;  
    node->right = NULL;  

    return node;
} 

// ajusta a árvore para garantir o balanceamento após a inserção
void fix_rb_tree (rb_tree_t* tree, rb_node_t* original_node) {
    rb_node_t *uncle, *grandparent, *node = original_node;

    // se não for a raiz e o pai for vermelho
    while (node->parent != NULL && node->parent->color == RED) {  
        grandparent = node->parent->parent;
        if (node->parent == grandparent->left) {  
            
            uncle = grandparent->right;  
            if (uncle != NULL && uncle->color == RED) { 
                
                // recolorir e mover para cima
                node->parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK;    

                node = grandparent; 
            }
            else {

                // se o nó for o filho direito do pai
                if (node == node->parent->right) {        
                    rotate_left(node->parent);  
                    node = node->left;  
                    grandparent = node->parent->parent;
                }
                
                rotate_right(grandparent);  
                grandparent->color = RED; 
                node->parent->color = BLACK;  
                if (node->parent->parent != NULL)
                    fix_rb_tree(tree, node->parent->parent);  // ajusta o balanceamento acima
                else
                    tree->root = node->parent;  // se for a raiz, ajusta a raiz
            }
        }
        else {  // caso o pai seja o filho direito do avô
            
            uncle = grandparent->left; 
            if (uncle != NULL && uncle->color == RED) {  
                
                // recolorir para o lado esquerdo
                node->parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK; 

                node = grandparent;  // Move para o avô
            }
            else {       
                if (node == node->parent->left) {      
                    rotate_right(node->parent);  
                    node = node->right;  
                    grandparent = node->parent->parent;
                }

                // caso o nó seja filho direito com pai direito
                rotate_left(grandparent);  
                grandparent->color = RED;  
                node->parent->color = BLACK;  
                if (node->parent->parent != NULL)
                    fix_rb_tree(tree, node->parent->parent);  // ajusta o balanceamento acima
                else
                    tree->root = node->parent;  // se for a raiz, ajusta a raiz
            }
        }
    } // while
    
    tree->root->color = BLACK;  // A raiz deve sempre ser preta
}

// cria um nó com os valores passados e o insere na árvore
// no duplicado não entra na arvore 
int insert_rb_node(rb_tree_t* tree, int key, char letter) {
   
    if (tree->root == NULL) {  
        tree->root = create_rb_node(key, letter);
        if (tree->root == NULL)
            return 0;

        tree->root->color = BLACK;    
        return 1;     
    }

    rb_node_t *aux = tree->root, *parent, *new_node;

    while (aux != NULL) {
        parent = aux;
        
        /*
            1: se a chave for menor, vai para a subárvore esquerda
            2: se a chave for maior, vai para a subárvore direita
            3: caso a chave seja duplicada, não insere
        */
        if (key < aux->key)
            aux = aux->left;  
        else {
            if (key > aux->key)
                aux = aux->right;  
            else 
                return 0;  
        }
    }

    new_node = create_rb_node(key, letter);  
    if (new_node == NULL)
            return 0;

    if (key < parent->key)
        parent->left = new_node; 
    else
        parent->right = new_node;  

    new_node->parent = parent;  

    // ajusta a árvore depois da inserção
    fix_rb_tree(tree, new_node);  
    return 1;
}

// recebe uma chave e realiza a busca na árvore, retornando o caractere associado à chave
// se não encontrado, retorna '\0'
char search_rb_internal(rb_node_t* root, int key) {
    char letter;
    
    rb_node_t* node = root;
    
    while (node != NULL && node->key != key) {
        if (node->key > key)
            node = node->left; 
        else  
            node = node->right; 
    }
    if ((node != NULL) && (node->key == key)) {
        letter = node->letter;  
        return letter;
    }
    else
        return '\0';  
}

char search_rb(rb_tree_t* tree, int key) {
    if (tree->root != NULL)
        return search_rb_internal(tree->root, key);

    return '\0';  // caso a árvore esteja vazia, retorna '\0'
}

// garante que todos os caracteres ASCII sejam incluídos na árvore para decodificação
void integrate_rb_tree(rb_tree_t* tree, char table[], int i) {
    char c;

    for (int j = 33; j < 256; j++) {
        if (table[j] == '0') {
            c = j;
            // insere os caracteres ASCII na árvore
            insert_rb_node(tree, i, c); 
            i++;
        }
    }
}

// busaa no pela chave 
rb_node_t* search_rb_node(rb_tree_t* tree, int key) {
    rb_node_t* node = tree->root;
    while (node != NULL && node->key != key) {
        if (node->key > key)
            node = node->left;  
        else
            node = node->right; 
    }
    return node;
}

// rotação a esquerda
void rotate_left(rb_node_t* p) {
    rb_node_t* x = p->right;
    x->parent = p->parent;
    if (p->parent != NULL) {
        if (p->parent->left == p)
            p->parent->left = x;
        else
            p->parent->right = x;
    }
    p->right = x->left;
    if (x->left != NULL)
        x->left->parent = p;
    p->parent = x;
    x->left = p;
}

// rotação a direita
void rotate_right(rb_node_t* p) {
    rb_node_t* x = p->left;
    x->parent = p->parent;
    if (p->parent != NULL) {
        if (p->parent->right == p)
            p->parent->right = x;
        else
            p->parent->left = x;
    }
    p->left = x->right;
    if (x->right != NULL)
        x->right->parent = p;
    p->parent = x;
    x->right = p;
}

// enconntra o antecessor
rb_node_t* find_predecessor(rb_node_t* node) {
    rb_node_t* current = node->left;
    while (current != NULL && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// remove um nó 
void remove_rb_node(rb_tree_t* tree, int key) {
    rb_node_t* node = search_rb_node(tree, key);
    if (node == NULL) {
        return;  
    }

    if (node->left != NULL && node->right != NULL) {
        rb_node_t* predecessor = find_predecessor(node);
        
        node->key = predecessor->key;
        node->letter = predecessor->letter;
        
        node = predecessor;
    }

    /*
        1:se o nó tem filho esquerdo
        2:se o nó tem filho direito
    */
    rb_node_t* child;
    if (node->left != NULL) {
        child = node->left;  
    } else {
        child = node->right; 
    }

    if (node->color == BLACK && (child == NULL || child->color == BLACK)) {
        balance_removal(tree, node);  // balanceia a árvore após a remoção
    }

    if (child != NULL) {
        child->parent = node->parent;  // atualiza o pai do filho
    }

    /* 
        1: se for a raiz atualiza a raiz
        2: atualiza o filho esquerdo do pai
        3: atualiza o filho direito do pai
    */
    if (node->parent == NULL) {
        tree->root = child;  
    } else if (node == node->parent->left) {
        node->parent->left = child;  
    } else {
        node->parent->right = child;  
    }

    free(node);  
}

// retorna a cor preto ou vermelho
Color get_color(rb_node_t* node) {
    if (node == NULL) {
        return BLACK; // se for nulo é preto
    }
    return node->color;
}

// balanceamento apos remoção de um nó
void balance_removal(rb_tree_t* tree, rb_node_t* node) {

    // se não for a raiz e nem for preto
    while (node != tree->root && get_color(node) == BLACK) {
        if (node == node->parent->left) {
            rb_node_t* sibling = node->parent->right;  // irmão à direita

            // caso o irmão seja vermelho
            if (get_color(sibling) == RED) {  
                sibling->color = BLACK;
                node->parent->color = RED;
                rotate_left(node->parent);
                sibling = node->parent->right;
            }
            if (get_color(sibling->left) == BLACK && get_color(sibling->right) == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (get_color(sibling->right) == BLACK) {
                    rotate_right(sibling);
                    sibling = node->parent->right;
                }
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                rotate_left(node->parent);
                node = tree->root;
            }
        } else {
            // irmão a esquerda
            rb_node_t* sibling = node->parent->left;  
            if (get_color(sibling) == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotate_right(node->parent);
                sibling = node->parent->left;
            }
            if (get_color(sibling->right) == BLACK && get_color(sibling->left) == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (get_color(sibling->left) == BLACK) {
                    rotate_left(sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rotate_right(node->parent);
                node = tree->root;
            }
        }
    }
    node->color = BLACK;  // depois do balanceamento se torna preto
}

// impressão inorder (esq,raiz,dir)
void print_rb_inorder(rb_node_t* node, int level) {
    if (node == NULL) {
        return;
    }

    print_rb_inorder(node->left, level + 1);  

    printf("%d,%d,%d\n", node->key, level, node->color == BLACK ? 0 : 1); 

    print_rb_inorder(node->right, level + 1);  
}

// função para imprimir a redblack
void print_rb_tree(rb_tree_t* tree) {
    if (tree == NULL || tree->root == NULL) {
        return; 
    }

    print_rb_inorder(tree->root, 0);  
}
