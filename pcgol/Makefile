# Parametros de Ambiente

CC = gcc
 
CFLAGS = -g -std=c11 -Wall -Wextra -pedantic -pthread -lGL -lGLU -lglut

RFLAGS = 

# Parametros de Projeto

SRC = pcgol.c cell.c board.c display.c

OBJS = $(SRC:%.c=build/%.o)

pcgol: bin/pcgol

bin/pcgol: $(OBJS)
	@echo "+ Compilando programa \"$@\""
	@$(CC) $(OBJS) -o bin/pcgol $(CFLAGS)


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