# Makefile para Projeto de Estrutura de Dados

CC = gcc
CFLAGS = -Wall -Wextra -g -I./include
SRCDIR = src
TESTSDIR = tests
INCLUDIR = include
OBJDIR = obj
BINDIR = .

# Arquivos fonte
SOURCES = \
    $(SRCDIR)/main.c \
    $(SRCDIR)/algoritmos/bubble.c \
    $(SRCDIR)/algoritmos/selection.c \
    $(SRCDIR)/algoritmos/insertion.c \
    $(SRCDIR)/algoritmos/merge.c \
    $(SRCDIR)/algoritmos/quick.c \
    $(SRCDIR)/listas/dinamica.c \
    $(SRCDIR)/listas/estatica.c \
    $(SRCDIR)/utils/gerador.c \
    $(SRCDIR)/utils/merge_utils.c \
    $(SRCDIR)/utils/timer.c \
    $(SRCDIR)/utils/csv_io.c \
    $(TESTSDIR)/testes_manuais.c \
    $(TESTSDIR)/teste_bubble.c \
    $(TESTSDIR)/teste_selection.c \
    $(TESTSDIR)/teste_insertion.c \
    $(TESTSDIR)/teste_merge.c \
    $(TESTSDIR)/teste_performance.c

# Arquivos objeto
OBJECTS = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCES))

# Nome do executável
TARGET = $(BINDIR)/programa

# Regra padrão
all: $(TARGET)

# Compilar executável
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "✅ Projeto compilado com sucesso: $(TARGET)"

# Compilar arquivos objeto
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(OBJDIR)
	rm -f $(TARGET)
	@echo "✅ Arquivos de compilação removidos"

# Compilar e executar
run: $(TARGET)
	./$(TARGET)

# Compilar com otimizações
release: CFLAGS += -O2
release: clean $(TARGET)

# Exibir informações
.PHONY: all clean run release info

info:
	@echo "Fonte: $(SOURCES)"
	@echo "Objetos: $(OBJECTS)"
	@echo "Alvo: $(TARGET)"