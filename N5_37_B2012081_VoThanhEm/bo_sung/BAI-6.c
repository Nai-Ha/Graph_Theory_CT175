//ma tr?n k? c?a d? th? này.

//Gi? s? d? th? du?c cho là d? th? vô hu?ng don.


#include <stdio.h>
#define MAX_N 100
typedef struct {
	int n,m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG,int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG,int u,int v) {
	pG->A[u][v] = 1;
	pG->A[v][u] = 1;
	pG->m++;
}

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}
int main(){
	Graph G;
	int n,m,u,v;
	freopen("dt1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int i;
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	printGraph(G);
	return 0;
}
