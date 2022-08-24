//MA TRAN KE
//don do thi vo huong
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n,m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG,int n) {
	int i,j;
	pG->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			pG->A[i][j] = 0;
	pG->m = 0;
}

void add_edge(Graph *pG,int u,int v) {
	//vo huong =1; chua da cung la +=1;
	pG->A[u][v] = 1;
	pG->A[v][u] = 1;
	pG->m++;
}
