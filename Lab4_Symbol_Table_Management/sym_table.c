#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

// Structure to represent a symbol
typedef struct {
    char name[50];
    char type[20];
    int address;
} Symbol;

// Array to store symbols
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

// Function to add a symbol to the symbol table
void addSymbol(char name[], char type[], int address) {
    if (symbolCount < MAX_SYMBOLS) {
        strcpy(symbolTable[symbolCount].name, name);
        strcpy(symbolTable[symbolCount].type, type);
        symbolTable[symbolCount].address = address;
        symbolCount++;
    } else {
        printf("Symbol table is full. Cannot add more symbols.\n");
    }
}

// Function to search for a symbol in the symbol table
int searchSymbol(char name[]) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Symbol not found
}

int main() {
    // Adding symbols to the symbol table
    addSymbol("x", "int", 100);
    addSymbol("y", "float", 200);
    addSymbol("z", "char", 300);

    // Searching for a symbol
    char searchName[50];
    printf("Enter the symbol name to search: ");
    scanf("%s", searchName);
    int index = searchSymbol(searchName);

    if (index != -1) {
        printf("Symbol found:\n");
        printf("Name: %s\n", symbolTable[index].name);
        printf("Type: %s\n", symbolTable[index].type);
        printf("Address: %d\n", symbolTable[index].address);
    } else {
        printf("Symbol not found in the symbol table.\n");
    }

    return 0;
}