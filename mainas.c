#include "adjlist.h"
#include "stekas.h"

Virsunes *head_virs = NULL;
int n;
int *DFNum, *LowPt, *Parent;
int DFcount;

void DFSearch(int u) {
	List *sarasas = NULL;
	int  v;
	
	DFcount = DFcount + 1;
	DFNum[u] = DFcount;

	
	for (sarasas = gretimos_virsunes(head_virs, u); sarasas != NULL; sarasas = sarasas->next) {
		v = sarasas->virsune;
		
		if (DFNum[v] == 0) {
			Parent[v] = u;
			push(u, v);
			LowPt[v] = DFNum[u];
			DFSearch(v);
			
			if (LowPt[v] == DFNum[u]) {
				unstack(u, v);	
				
			} else {
				if (LowPt[v] < LowPt[u]) {
					LowPt[u] = LowPt[v];
				}
			}
		} else {
			
			if (v != Parent[u]) {
				if (DFNum[v] < DFNum[u]) {
					
					push(u,v);
					
					if (DFNum[v] < LowPt[u]) {
						LowPt[u] = DFNum[v];
					}
				}
			}
		}
		
	}
}
	
int
main (void)
{

	
    int u;
	
	n = nuskaityti_faila(&head_virs);
	print_adj(head_virs);
	DFNum   = calloc(n+1, sizeof(int));
	LowPt   = calloc(n+1, sizeof(int));
	Parent  = calloc(n+1 , sizeof(int));
    
    if ( (DFNum == NULL) || (LowPt  == NULL) ||  (Parent == NULL) ) {
        fprintf(stderr, "Calloc klaida\n");
        exit (1);
    }
	
	u = head_virs->virsune;
	LowPt[u] = 1;
	DFSearch(u); 
	
	return 0;
}


	