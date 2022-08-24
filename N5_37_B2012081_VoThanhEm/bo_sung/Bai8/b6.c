#include <stdio.h>
#define MAX_N 100
#define MAX_M 500
typedef struct {
	int A[100][100];
	int n;
} Graph;

void init_graph(Graph *pG,int n) {
	pG->n = n;
}

void add_edge(Graph *pG,int x,int y) {
	pG->A[x][y]++;
}

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

int main() {
	int n;
	Graph G;
	freopen("test4.txt","r",stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	int i;
	int u,e;
	for(e=1; e<=n; e++) {
		for(i=1;i<=n;i++){
			scanf("%d",&u);
			if(u == 1)
				add_edge(&G,e,i);
		}
	}
//	printGraph(G);
	for(e=1;e<=n;e++){
		printf("%d: ",e);
		for(i=1;i<=n;i++){
			if(G.A[e][i] == 1)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
