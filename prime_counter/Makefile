# Parametros de Ambiente

CC = gcc
 
CFLAGS = -g -Wall -fopenmp


# Parametros de Projeto

SRC = main.c primes.c

OBJS = $(SRC:%.c=build/%.o)

primes: bin/primes

bin/primes: $(OBJS)
	@echo "+ Compilando programa \"$@\""
	@$(CC) $(CFLAGS) $(OBJS) -o bin/primes


# Objetos

build/%.o: src/%.c src/%.h
	@echo "- Compilando objeto \"$@\""
	@$(CC) -c $(CFLAGS) $< -o $@

build/%.o: src/%.c
	@echo "- Compilando objeto \"$@\""
	@$(CC) -c $(CFLAGS) $< -o $@


# Auxiliares

clean:
	rm -f bin/*