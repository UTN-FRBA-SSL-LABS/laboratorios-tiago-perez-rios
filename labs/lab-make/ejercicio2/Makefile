# Nombre del ejecutable final
PROGRAMA := scanner2

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

# Regla para construir el scanner
# Dependencias: scanner2.l (Flex genera lex.yy.c a partir de él)
$(PROGRAMA): scanner2.l
	flex scanner2.l

	$(CC) -o $(PROGRAMA) lex.yy.c
# Regla para limpiar archivos generados
clean:
	rm -f $(PROGRAMA) lex.yy.c

.PHONY: all clean
