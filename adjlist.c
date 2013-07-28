#include "adjlist.h"

void append (List **head, int virsune) {
    List *current = *head;
    List *naujas;
	
    naujas = malloc(sizeof(List));
    
    if (naujas == NULL) {
       fprintf(stderr, "Maloc klaida");
       exit (1);
    }
       
    naujas->virsune = virsune;
    naujas->next    = NULL;
	
    if (current == NULL) {
        *head = naujas;
    } else {
          while (current->next != NULL) {
              current = current->next;
	  }

          current->next = naujas;
    }
}

void print_list (List *head) {
    while (head != NULL) {
        printf("%d\n", head->virsune);
	head = head->next;
    }
} 

void prideti_virsune (Virsunes **head, int virsune, List *list) {
    Virsunes *current = *head;
    Virsunes *naujas;
	
    naujas = malloc(sizeof(Virsunes));
    
    if (naujas == NULL) {
       fprintf(stderr, "Maloc klaida");
       exit (1);
    }
    
    naujas->virsune   = virsune;
    naujas->list      = list;
    naujas->next_virs = NULL;
	
    if (current == NULL) {
        *head = naujas;  
    } else {
          while (current->next_virs != NULL) {
              current = current->next_virs;
	  } 
	  current->next_virs = naujas;
    }
}

void prideti_sarasa (Virsunes *virsune, List *list) {
    virsune->list = list;
}

void print_adj (Virsunes *head) {
    Virsunes *head_virs = head;
    List     *head_list;
	
    while (head_virs != NULL) {
        head_list  = head_virs->list;
        printf("%d ", head_virs->virsune);
        while ( head_list != NULL) {
            printf("%d ", head_list->virsune);
	    head_list = head_list->next;
	}

	printf("\n");
	head_virs = head_virs->next_virs;
    }
}

List*
gretimos_virsunes(Virsunes *head, int virsune) {
    List *sarasas = NULL;
    while (head != NULL) {
        if (head->virsune == virsune) {
            sarasas = head->list;
            break;
	}
        head = head->next_virs;
    }

    return sarasas;
}
		
		   
		    
	

int nuskaityti_faila(Virsunes **head) {
    FILE *input;
    int taskas, prad_taskas;
    List     *head_list = NULL;
    Virsunes *head_virs = *head;
	
    input = fopen("adjduom.txt", "r");
    if (input == NULL) {
       fprintf(stderr, "negali atidaryti failo\n");
       exit (1);
    }
    
    while ( !feof (input)) {
        fscanf(input, "%d", &prad_taskas);
        
        fscanf(input, "%d", &taskas);

        while (taskas != 0) {
	     append(&head_list, taskas);
	     fscanf(input, "%d", &taskas);
        }
        
       
        prideti_virsune(&head_virs, prad_taskas, head_list);
        head_list = NULL;
      
    }
    
    *head = head_virs;
    return prad_taskas;
}




