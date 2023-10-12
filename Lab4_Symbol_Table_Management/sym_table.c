#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int type;
  int scope;
} Symbol;

typedef struct {
  Symbol *symbols;
  int size;
} SymbolTable;

SymbolTable *create_symbol_table() {
  SymbolTable *table = malloc(sizeof(SymbolTable));
  table->symbols = NULL;
  table->size = 0;
  return table;
}

void destroy_symbol_table(SymbolTable *table) {
  for (int i = 0; i < table->size; i++) {
    free(table->symbols[i].name);
  }
  free(table->symbols);
  free(table);
}

void add_symbol(SymbolTable *table, Symbol *symbol) {
  table->symbols = realloc(table->symbols, sizeof(Symbol) * (table->size + 1));
  table->symbols[table->size] = *symbol;
  table->size++;
}

Symbol *lookup_symbol(SymbolTable *table, char *name) {
  for (int i = 0; i < table->size; i++) {
    if (strcmp(table->symbols[i].name, name) == 0) {
      return &table->symbols[i];
    }
  }
  return NULL;
}
