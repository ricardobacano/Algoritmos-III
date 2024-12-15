CC = gcc              
CFLAGS = -Wall -g     
OBJ = main.o librb.o    
EXEC = myrb         

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c librb.h
	$(CC) $(CFLAGS) -c main.c

librb.o: librb.c librb.h
	$(CC) $(CFLAGS) -c librb.c

clean:
	rm -f $(OBJ) $(EXEC)

test: $(EXEC)
	./$(EXEC) < teste.in > teste.out
	diff teste.sol teste.out
