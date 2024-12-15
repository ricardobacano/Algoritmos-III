#ifndef __HASH_H__
#define __HASH_H__

#define M 11      // Tamanho das tabelas de hash
#define EMPTY -1  // Constante para representar uma posição vazia
#define DELETED -2 // Constante para representar uma posição deletada

/**
 * Estrutura que representa a tabela de hash com duas tabelas, T1 e T2.
 */
typedef struct {
    int T1[M];  // Tabela 1
    int T2[M];  // Tabela 2
} HashTable;

/**
 * Inicializa as tabelas T1 e T2 com valores que indicam posições vazias.
 * @param table Ponteiro para a estrutura da tabela de hash a ser inicializada.
 */
void initialize_table(HashTable* table);

/**
 * Função hash h1.
 * @param key Chave inteira para a qual será calculada a posição.
 * @return Retorna a posição calculada para a chave na tabela T1.
 */
int h1(int key);

/**
 * Função hash h2.
 * @param key Chave inteira para a qual será calculada a posição.
 * @return Retorna a posição calculada para a chave na tabela T2.
 */
int h2(int key);

/**
 * Busca uma chave na tabela de hash, aplicando a função de hash apropriada.
 * @param table Ponteiro para a estrutura da tabela de hash.
 * @param key Chave inteira a ser buscada.
 * @param i Índice que indica qual função de hash utilizar (0 para h1, 1 para h2).
 * @return Retorna a posição da chave na tabela se for encontrada, ou -3 se não for encontrada.
 */
int find(HashTable* table, int key, int i);

/**
 * Insere uma chave na tabela de hash.
 * @param table Ponteiro para a estrutura da tabela de hash.
 * @param key Chave inteira a ser inserida.
 */
void insert(HashTable* table, int key);

/**
 * Remove uma chave da tabela de hash, marcando-a como deletada.
 * @param table Ponteiro para a estrutura da tabela de hash.
 * @param key Chave inteira a ser removida.
 */
void remove_key(HashTable* table, int key);

/**
 * Imprime os elementos da tabela T1 em ordem crescente.
 * @param table Ponteiro para a estrutura da tabela de hash.
 */
void print_hash1(HashTable* table);

/**
 * Imprime os elementos da tabela T2 em ordem crescente.
 * @param table Ponteiro para a estrutura da tabela de hash.
 */
void print_hash2(HashTable* table);

/**
 * Imprime os elementos de ambas as tabelas (T1 e T2) em ordem crescente.
 * @param table Ponteiro para a estrutura da tabela de hash.
 */
void print_tables(HashTable* table);

#endif
