# Parametros de Ambiente

CC = gcc
 
CFLAGS = -g -Wall -fopenmp

RFLAGS = -fopenmp

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


# Release


release: $(OBJS)
	@echo "Building release candidate"
	@$(CC) $(RFLAGS) $(OBJS) -o ../release/primes

# Auxiliares

clean:
	rm -f bin/*