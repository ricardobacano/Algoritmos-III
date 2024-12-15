#include <stdio.h>
#include "hash.h"

int main() {
    HashTable table;
    initialize_table(&table);

    char operation;
    int key;

    while (scanf(" %c %d", &operation, &key) != EOF) {
        if (operation == 'i') {
            insert(&table, key);
        } else if (operation == 'r') {
            remove_key(&table, key);
        }
    }

    print_tables(&table);
    return 0;
}