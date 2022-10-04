#include <stdio.h>
#define Max_N 100
#define NO_EDGE -1
#define OO 9999
typedef int ElementType;
typedef struct {
	int A[Max_N][Max_N];
	int n;
} Graph;

int pi[Max_N];
int p[Max_N];
int mark[Max_N];

void init_graph(Graph *G,int n) {
	int i,j;
	G->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j] = NO_EDGE;
}
//don do thi vo huong
void add_edge(Graph *pG,int x,int y,int w) {
	pG->A[x][y] = w;
	pG->A[y][x] = w;
}

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

void Dijkstra(Graph *pG,int s) {
	// khoi tao
	int u = -1,i,j,v;
	for(u=1; u<=pG->n; u++) {
		pi[u] = OO;
		p[u] = -1;
		mark[u] = 0;
	}

	pi[s] = 0;
	p[s] = -1;
	for(i=1; i<=pG->n; i++) {
		int min_pi = OO;
		int u = -1;
		for(j=1; j<=pG->n; j++) {
			if(mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				u = j;
			}
		}

		if(u == -1) break;
		mark[u] = 1;
		for(v=1; v<=pG->n; v++) {
			if(pG->A[u][v] != NO_EDGE && mark[u] == 1
			        && pi[u] + pG->A[u][v] < pi[v]) {
				pi[v] = pi[u] + pG->A[u][v];
				p[v] = u;
			}
		}
	}
}

int main() {
	Graph G;
	int n,m,u,v,e,i;
	freopen("test2.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&e);
		add_edge(&G,u,v,e);
	}
	printGraph(G);
	Dijkstra(&G,1);
	if(pi[n] != OO){
		printf("%d",pi[n]);
	}else{
		printf("-1");
	}
	return 0;
}


