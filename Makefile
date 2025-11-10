# Makefile para o projeto de Criptografia
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = criptografia

# Arquivos fonte
SOURCES = main.c criptografia.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = criptografia.h

# Regra padrão
all: $(TARGET)

# Compila o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compila arquivos objeto
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET)

# Executa o programa
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
