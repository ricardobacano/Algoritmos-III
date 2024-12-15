#include <stdio.h>
#include <stdlib.h>
#include "lib_bsttree.h"
#include "lib_avltree.h"

int main(){

    struct node *root = NULL;
    char operator_key;
    int value_key;        

    while(scanf("%c %d", &operator_key, &value_key) != EOF)
    {
        if (operator_key == 'i'){
            root = insert_node(root, value_key);
        }

        else if (operator_key == 'r'){
            root = delete_node(root, value_key);
        }
        getchar();
    }

    inoder(root, 0);
    return 0;
}