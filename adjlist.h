#include <stdio.h>
#include <stdlib.h>

typedef struct list_ {
	struct list_  *next;
	int           virsune;
} List;

typedef struct virsunes_ {
	struct virsunes_  *next_virs;
	int               virsune;
	List              *list;
} Virsunes;



void append (List **head, int virsune);
void print_list (List *head);
void prideti_virsune (Virsunes **head, int virsune, List *list);
void prideti_sarasa (Virsunes *virsune, List *list);
void print_adj (Virsunes *head);
int nuskaityti_faila(Virsunes **head);
List*
gretimos_virsunes(Virsunes *head, int virsune);



