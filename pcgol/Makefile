# Parametros de Ambiente

CC = gcc
 
CFLAGS = -g -std=c11 -Wall -Wextra -pedantic

RFLAGS = 

# Parametros de Projeto

SRC = pcgol.c cell.c board.c

OBJS = $(SRC:%.c=build/%.o)

pcgol: bin/pcgol

bin/pcgol: $(OBJS)
	@echo "+ Compilando programa \"$@\""
	@$(CC) $(CFLAGS) $(OBJS) -o bin/pcgol


# Objetos

build/%.o: src/%.c src/%.h
	@echo "- Compilando objeto \"$@\""
	@$(CC) -c $(CFLAGS) $< -o $@

build/%.o: src/%.c
	@echo "- Compilando objeto \"$@\""
	@$(CC) -c $(CFLAGS) $< -o $@


# Release


release: $(OBJS)
	@echo "Building release candidate"
	@$(CC) $(RFLAGS) $(OBJS) -o release/primes

# Auxiliares

clean:
	rm -f bin/*