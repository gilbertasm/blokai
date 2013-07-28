#include "stekas.h"

Elem *head = NULL;

void push(int u, int v) {
	 
   Elem *elem = NULL;
   elem = malloc(sizeof(elem));
   if (elem == NULL) {
       fprintf(stderr, "Maloc klaida");
       exit (1);
   }
       
   Briauna *briauna = malloc(sizeof(briauna));
   
   if (elem == NULL) {
       fprintf(stderr, "Maloc klaida");
       exit (1);
   }
       
   briauna->pradzia =  u;
   briauna->pabaiga  = v;
   
   elem->briauna = briauna;
   elem->next = head;
   head = elem;
}

Briauna*
pop() {
	
	if (head != NULL) {
	    Briauna* briauna = head->briauna;
	    head = head->next;
	    return briauna;
    } 
    
    return (Briauna*) NULL;
}

void print_briauna (Briauna *briauna) {
	printf("%d -> %d\n", briauna->pradzia, briauna->pabaiga);
}

int briaunos_lygios(Briauna *briauna1, Briauna *briauna2) {
    if ( (briauna1->pradzia == briauna2->pradzia) &&
         (briauna1->pabaiga == briauna2->pabaiga)) {
	         return 1;
    } else { 
	    return 0;
    }
} 

void unstack (int u, int v) {
	Briauna *briauna2, *briauna1 = malloc(sizeof(briauna1));
	briauna1->pradzia = u;
	briauna1->pabaiga = v;
	
	printf("Naujas blokas\n");
	printf("----------------\n");
	
	do {
		briauna2 = pop();
		print_briauna(briauna2);
	} while ( briaunos_lygios(briauna1, briauna2) == 0);
	printf("----------------\n");
}




         	
	