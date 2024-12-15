#include <stdio.h>
#include <stdlib.h>
#include "librb.h"

int main() {

    rb_tree_t* Tree = create_rb_tree();

    char comand;
    int key_value;
    
    while (scanf(" %c", &comand) != EOF) {
        if (comand == 'i') { 
            if (scanf("%d", &key_value) == 1) {
                insert_rb_node(Tree, key_value, 'i');
            }
        } 
        else if (comand == 'r') {  
            if (scanf("%d", &key_value) == 1) {
                remove_rb_node(Tree, key_value);
            }
        } 
    }
    print_rb_tree(Tree);

    printf("\n");

    delete_rb_tree(Tree);
    return 0;
}
