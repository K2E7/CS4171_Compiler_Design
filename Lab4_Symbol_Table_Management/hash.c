#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOL_NAME_SIZE 20
#define TABLE_SIZE 10

typedef struct t_symbol {
    char name[SYMBOL_NAME_SIZE];
    int dtype;
    int scope;
    int line_number;
} symbol;

typedef struct t_node {
    symbol *data;
    struct t_node *next;
} node;

typedef struct t_symbol_table {
    node *buckets[TABLE_SIZE];
    int size;
} symbol_table;

unsigned int hash_function(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + (*str++);
    }
    return hash % TABLE_SIZE;
}

symbol *create_symbol(char *name, int dtype, int scope, int line_number) {
    symbol *s = (symbol *)malloc(sizeof(symbol));
    if (s == NULL) {
        perror("Failed to allocate memory for symbol");
        exit(EXIT_FAILURE);
    }
    strncpy(s->name, name, SYMBOL_NAME_SIZE - 1);
    s->name[SYMBOL_NAME_SIZE - 1] = '\0';  // Ensure null-terminated
    s->dtype = dtype;
    s->scope = scope;
    s->line_number = line_number;
    return s;
}

void display_symbol(symbol *s) {
    if (s == NULL) {
        printf("Cannot display NULL symbol\n");
        return;
    }

    printf("%-20s %-10d %-10d %-10d\n", s->name, s->dtype, s->scope, s->line_number);
}

symbol_table *create_table() {
    symbol_table *table = (symbol_table *)malloc(sizeof(symbol_table));
    if (table == NULL) {
        perror("Failed to allocate memory for symbol table");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABLE_SIZE; ++i) {
        table->buckets[i] = NULL;
    }

    table->size = 0;
    return table;
}

void insert_table(symbol_table *table, symbol *data) {
    unsigned int index = hash_function(data->name);
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
    table->size++;
}

void iterate_table(symbol_table *table) {
    printf("\n[SYMBOL TABLE]\n%-20s %-10s %-10s %-10s\n", "Name", "Data Type", "Scope", "Line Number");
    printf("------------------------------------------------\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        node *current = table->buckets[i];
        while (current != NULL) {
            display_symbol(current->data);
            current = current->next;
        }
    }
}

symbol *lookup_table(symbol_table *table, char *name, int scope) {
    unsigned int index = hash_function(name);
    node *current = table->buckets[index];
    while (current != NULL) {
        if ((strcmp(current->data->name, name) == 0) && (current->data->scope <= scope)) {
            return current->data;
        }
        current = current->next;
    }
    printf("Symbol not found\n");
    return NULL;
}

void remove_table(symbol_table *table, int scope) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        node *current = table->buckets[i];
        node *previous = NULL;
        while (current != NULL) {
            if (current->data->scope == scope) {
                if (previous == NULL) {
                    table->buckets[i] = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                table->size--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    printf("Symbol not found\n");
}

void free_table(symbol_table *table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        node *current = table->buckets[i];
        while (current != NULL) {
            node *next = current->next;
            free(current->data);
            free(current);
            current = next;
        }
    }
    free(table);
}