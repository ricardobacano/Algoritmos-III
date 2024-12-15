#include <stdio.h>
#include "hash.h"

// Inicializa as duas tabelas com EMPTY
void initialize_table(HashTable* table) {
    for (int i = 0; i < M; i++) {
        table->T1[i] = EMPTY;
        table->T2[i] = EMPTY;
    }
}

// Função hash para a Tabela 1
int h1(int key) {
    return key % M;
}

// Função hash para a Tabela 2
int h2(int key) {
    return (int)(M * (key * 0.9 - (int)(key * 0.9)));
}

// Busca um elemento na tabela
int find(HashTable* table, int key, int i) {
    int (*hash[2])(int) = {h1, h2}; // Array com as funções hash
    int pos = hash[i](key);

    // Verifica a tabela correspondente
    if (i == 0 && table->T1[pos] == key) {
        return pos;
    } else if (i == 1 && table->T2[pos] == key) {
        return pos;
    }
    
    return -3; // Não encontrado
}

// Insere um elemento na tabela
void insert(HashTable* table, int key) {
    int pos1 = h1(key);

    if (table->T1[pos1] == EMPTY || table->T1[pos1] == DELETED) {
        // Insere diretamente se a posição está livre ou marcada como deletada
        table->T1[pos1] = key;
    } else {
        // Colisão: move o elemento existente para T2
        int ki = table->T1[pos1];
        int pos2 = h2(ki);
        table->T2[pos2] = ki;

        // Insere o novo elemento na T1
        table->T1[pos1] = key;
    }
}

// Remove um elemento da tabela
void remove_key(HashTable* table, int key) {
    int pos1 = h1(key);
    int pos2 = h2(key);

    if (table->T2[pos2] == key) {
        // Remove da T2
        table->T2[pos2] = EMPTY;
    } else if (table->T1[pos1] == key) {
        // Marca como deletado na T1
        table->T1[pos1] = DELETED;
    } else {
        // Elemento não encontrado
        fprintf(stderr, "valor não presente na tabela hash \n");
    }
}

// Imprime os elementos da T1 em ordem crescente
void print_hash1(HashTable* table) {
    int tempT1[M];
    int countT1 = 0;

    // Copia elementos válidos de T1 para um array temporário
    for (int i = 0; i < M; i++) {
        if (table->T1[i] != EMPTY && table->T1[i] != DELETED) {
            tempT1[countT1++] = table->T1[i];
        }
    }

    // Ordena o array temporário
    for (int i = 0; i < countT1 - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < countT1; j++) {
            if (tempT1[j] < tempT1[minIndex]) {
                minIndex = j;
            }
        }
        // Troca elementos
        int tempValue = tempT1[minIndex];
        tempT1[minIndex] = tempT1[i];
        tempT1[i] = tempValue;
    }

    // Imprime os elementos ordenados
    for (int i = 0; i < countT1; i++) {
        printf("%d,T1,%d\n", tempT1[i], h1(tempT1[i]));
    }
}

// Imprime os elementos da T2 em ordem crescente
void print_hash2(HashTable* table) {
    int tempT2[M];
    int countT2 = 0;

    // Copia elementos válidos de T2 para um array temporário
    for (int i = 0; i < M; i++) {
        if (table->T2[i] != EMPTY) {
            tempT2[countT2++] = table->T2[i];
        }
    }

    // Ordena o array temporário
    for (int i = 0; i < countT2 - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < countT2; j++) {
            if (tempT2[j] < tempT2[minIndex]) {
                minIndex = j;
            }
        }
        // Troca elementos
        int tempValue = tempT2[minIndex];
        tempT2[minIndex] = tempT2[i];
        tempT2[i] = tempValue;
    }

    // Imprime os elementos ordenados
    for (int i = 0; i < countT2; i++) {
        printf("%d,T2,%d\n", tempT2[i], h2(tempT2[i]));
    }
}

// Imprime ambas as tabelas (T2 primeiro, depois T1)
void print_tables(HashTable* table) {
    print_hash2(table);
    print_hash1(table);
}
