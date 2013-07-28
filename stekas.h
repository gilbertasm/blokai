#include <stdio.h>
#include <stdlib.h>

typedef struct briauna_ {
	int pradzia;
	int pabaiga;
} Briauna;


typedef struct elem_ {
	Briauna *briauna;
	struct elem_ *next;
} Elem;

void push(int u, int v);
Briauna* pop();
void print_briauna (Briauna *briauna);
int briaunos_lygios(Briauna *briauna1, Briauna *briauna2);
void unstack (int u, int v);

