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
	Graph G;
	int n;
	freopen("test3.txt","r",stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	int e,x,u,count,i;
	for(e=1; e<=n; e++) {
		scanf("%d%d:",&x,&count);
//		printf("%d %d: ",x,count);
		for(i=1; i<=count; i++) {
			scanf("%d",&u);
//			printf("%d ",u);
			add_edge(&G,x,u);
		}
	}
	printf("%d\n",n);
	printGraph(G);
	return 0;
}
