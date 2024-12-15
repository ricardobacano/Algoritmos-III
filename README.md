# Trabalhos Práticos - Algoritmos e Estrutura de Dados III

Este repositório contém três trabalhos práticos desenvolvidos em **C**, que envolvem a implementação de estruturas de dados avançadas: **Árvore AVL**, **Tabelas Hash** e **Árvore Rubro-Negra**.

---

## Trabalho 1: Árvore AVL

### Descrição
Implementação de inclusão e remoção de valores em uma **Árvore AVL**. Após cada operação, a árvore é balanceada automaticamente para garantir suas propriedades.

### Entrada
- O arquivo `teste.in` contém operações:
  - `i X`: Inserção do valor **X**.
  - `r X`: Remoção do valor **X**.

### Saída
- O arquivo `teste.out` contém os valores em **ordem** com o nível de cada nó, no formato:
  ```
  (valor, nível)
  ```

### Execução
```bash
$ make
$ ./myavl < teste.in > teste.out
$ diff teste.sol teste.out
```

---

## Trabalho 2: Tabelas Hash

### Descrição
Implementação de **Tabelas Hash** com **endereçamento aberto**, utilizando o método **Cuckoo Hashing** (sem rehashing):
- Duas tabelas de tamanho fixo **T1** e **T2**.
- Tratamento de colisões ao mover chaves entre as tabelas.

### Funções Hash:
- **T1**: `h1(k) = k mod 11`
- **T2**: `h2(k) = floor(11 * (k * 0.9 - floor(k * 0.9)))`

### Entrada
- O arquivo `teste.in` contém operações:
  - `i X`: Inserção do valor **X**.
  - `r X`: Remoção do valor **X**.

### Saída
- O arquivo `teste.out` contém o estado das tabelas após cada operação:
  ```
  (posição, tabela, chave)
  ```

### Execução
```bash
$ make
$ ./myhash < teste.in > teste.out
$ diff teste.sol teste.out
```

---

## Trabalho 3: Árvore Rubro-Negra

### Descrição
Implementação de inclusão e remoção de valores em uma **Árvore Rubro-Negra**. A cor do nó é mantida para garantir o balanceamento da árvore.

### Entrada
- O arquivo `teste.in` contém operações:
  - `i X`: Inserção do valor **X**.
  - `r X`: Remoção do valor **X**.

### Saída
- O arquivo `teste.out` contém os valores em **ordem**, o nível e a cor de cada nó, no formato:
  ```
  (valor, nível, cor)
  ```
  - Cor: `0` para **preto** e `1` para **vermelho**.

### Execução
```bash
$ make
$ ./myrb < teste.in > teste.out
$ diff teste.sol teste.out
```

---

## Relatórios

Cada trabalho acompanha um **relatório de até 2 páginas**, contendo:
- Descrição dos algoritmos utilizados.
- Particularidades de implementação.
- Testes realizados e resultados obtidos.

Os relatórios estão dentro de cada pasta contendo o trabalho específico.
