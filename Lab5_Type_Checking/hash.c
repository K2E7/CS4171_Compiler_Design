#include <stdio.h>

//defining the max size of symbol table
#define TABLE_SIZE 500

/* Defining the Symbol Table data structure */

//keep trackk of scope during parsing
int scope = 0;
//variable to keep track of datatype
int dtype;
int flag = 0;
  
//structure defining the individual units of the symbol table
typedef struct val {
	char name[20];
	int dtype;
	int scope;
	//int isPointer;
	struct val *next;
} Symbol;

//defining the structure of the symbol table
typedef struct table {
	Symbol *entry[TABLE_SIZE];
	int size;
} SymTable;

//the global variable for the symbol table
SymTable table;

int hash (char *str) {
	int h = 5381;
	int c;
	
	while((c = *str++)) {
		h = ((h << 5) + h) + c;	//hash * 33 + c
	}
	
	return h % TABLE_SIZE;
}

//initializing the symbol table
void initTable() {
	for(int i=0;i<TABLE_SIZE;i++) {
		table.entry[i] = NULL;
	}
	table.size = 0;
}

//function to print symmbol table
void printTable() {
	printf("Entry no.\tSymbol name\tDatatype\tScope\n");
	for(int i=0;i<TABLE_SIZE;i++) {
		if(table.entry[i] != NULL) {
			Symbol *head = table.entry[i];
			while(head != NULL) {
				printf("%d\t\t%s\t\t%d\t\t%d\n", i, head->name, head->dtype, head->scope);
				head = head->next;
			}
		}
	}
}

//function to check is a symbol is present in the symbol table
int isPresent(char *sym) {
	int hval = hash(sym);
	Symbol *head = table.entry[hval];

	if(head == NULL) {
		return 0;
	}

	while(head != NULL) {
		if(strcmp(head->name, sym) == 0)
			return 1;
		
		head = head->next;
	}

	return 0;
}

//function to check for a redeclaration
int alreadyDeclared(char *sym) {
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	
	if(head == NULL) {
		return 0;
	}

	while(head != NULL) {
		//checking if the same symbol name exists in the same scope
		if(strcmp(head->name, sym) == 0 && head->scope == scope) {
			
			//checking if the datatype is also same
			if(head->dtype == dtype)
				return 1;

			else
				return 2;
		}

		head = head->next;
	}

	return 0;
}

//function to add a new entry in the table
int addSymbol(char *sym) {

	if(table.size == TABLE_SIZE) {
		return -1;
	}
	
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	
	Symbol *tmp = (Symbol *)malloc(sizeof(Symbol));
	strcpy(tmp->name, sym);
	tmp->dtype = dtype;
	tmp->scope = scope;
	tmp->next = NULL;

	//in case there is no collision
	if(head == NULL) {
		head = tmp;
		table.size++;
		table.entry[hval] = head;
		//printTable();
		return 0;
	}

	//in case of a collision, add to the end of list
	while(head->next != NULL) {
		head = head->next;
	}

	head->next = tmp;
	//printTable();
	return 0;
}

// function to add a user defined function identifier to symbol table
int addFunction(char *sym) {
	if(table.size == TABLE_SIZE) {
		return -1;
	}
	
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	Symbol *tmp = (Symbol *)malloc(sizeof(Symbol));
	strcpy(tmp->name, sym);
	tmp->dtype = dtype;
	tmp->scope = 0;
	tmp->next = NULL;
	
	//in case there is no collision
	if(head == NULL) {
		head = tmp;
		table.size++;
		table.entry[hval] = head;
		//printTable();
		return 0;
	}

	//in case of a collision, add to the end of list
	while(head->next != NULL) {
		head = head->next;
	}

	head->next = tmp;
	//printTable();
	return 0;
}

//function to get the datatype of a symbol from symbol table
int getDatatype(char *sym) {
	int hval = hash(sym);
	Symbol *head = table.entry[hval];
	while(head != NULL && strcmp(head->name, sym) != 0) {
		head = head->next;
	}
	if(head == NULL) return 0;
	return head->dtype;
}

//function to delete all nodes from a list with matching scope
void deleteNodes(int i, int key) {
	Symbol *tmp, *p, *q;
	Symbol *head = table.entry[i];

	while(head != NULL && head->scope == key) {
		tmp = head;
		head = head->next;
		free(tmp);
	}

	if(head == NULL) {
		table.entry[i] = head;
		return;
	}

	table.entry[i] = head;
	p = head;
	q = head->next;
	while(q != NULL) {
		if(q->scope == key) {
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
}

//function to delete the symbols of a scope when scope ends
void deleteScopeSyms(int s) {
	printf("Table before deleting scope %d:\n", s);
	printTable();
	printf("Table size = %d\n", table.size);
	for(int i=0;i<TABLE_SIZE;i++) {
		if(table.entry[i] != NULL) {
			deleteNodes(i, s);
			if(table.entry[i] == NULL) {
				table.size--;
			}
		}
	}
	printf("Table after deleting scope %d:\n", s);
	printTable();
	printf("Table size = %d\n", table.size);
}

//function to free memory by deleting entire symbol table
void freeTable() {
	for(int i=0;i<TABLE_SIZE;i++) {
		Symbol *head = table.entry[i];
		Symbol *tmp;
		while(head != NULL) {
			tmp = head;
			head = head->next;
			free(tmp);
		}
	}
}

/* Symbol Table DS definition ends */