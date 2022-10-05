#include <stdio.h>
#include <math.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
#define NO_EDGE 0
#define OO 9999
#define MIN_OO 9000

typedef int ElementType;
typedef struct {
	int A[Max_N][Max_N];
	int n;
} Graph;

int pi[Max_N][Max_N];
int p[Max_N][Max_N];
int next[Max_N][Max_N];

void init_graph(Graph *G,int n) {
	int i,j;
	G->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j] = NO_EDGE;
}

void add_edge(Graph *pG,int x,int y,int w) {
	pG->A[x][y] = w;
}

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

void floyd_shall(Graph *pG) {
	int u,v,k;
	for(u=1; u<=pG->n; u++) {
		for(v=1; v<=pG->n; v++) {
			pi[u][v] = OO;
			next[u][v] = -1;
		}
	}

	for(u=1; u<=pG->n; u++)
		pi[u][u] = 0;

	for(u=1; u<=pG->n; u++)
		for(v=1; v<=pG->n; v++) {
			if(pG->A[u][v] != NO_EDGE) {
				pi[u][v] = pG->A[u][v];
				next[u][v] = v;
			}
		}


	for(k=1; k<=pG->n; k++) {
		for(u=1; u<=pG->n; u++) {
			for(v=1; v<=pG->n; v++) {
				if(pi[u][k] + pi[k][v] < pi[u][v]){
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = v;	
				}
			}
		}
	}
}

int main() {
	Graph G;
	int n,m,u,v,e,i,j;
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&e);
		add_edge(&G,u,v,e);
	}
	printGraph(G);
	floyd_shall(&G);
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++){
			if(pi[i][j] != OO)
				printf("%d -> %d: %d\n",i,j,pi[i][j]);
			else
				printf("%d -> %d: NO PATH\n",i,j);
		}
	}
	return 0;
}


