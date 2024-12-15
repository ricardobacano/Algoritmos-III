CFLAGS = -Wall 

# Arquivos objeto necessários
obj = lib_bsttree.o lib_avltree.o main.o

# Regra padrão para quando `make` for executado
all: myavl

# Regra para criar o executável 'myavl'
myavl: $(obj)
	gcc ${CFLAGS} -o myavl $(obj)

# Compilar 'main.c' para 'main.o'
main.o: main.c lib_avltree.h lib_bsttree.h
	gcc ${CFLAGS} -c main.c

# Compilar 'lib_bsttree.c' para 'lib_bsttree.o'
lib_bsttree.o: lib_bsttree.c lib_bsttree.h
	gcc ${CFLAGS} -c lib_bsttree.c

# Compilar 'lib_avltree.c' para 'lib_avltree.o'
lib_avltree.o: lib_avltree.c lib_avltree.h
	gcc ${CFLAGS} -c lib_avltree.c

# Limpar os arquivos temporários e objetos
clean:
	rm -f myavl $(obj) *~

# Regra para limpeza completa
purge: clean
	rm -f myavl
