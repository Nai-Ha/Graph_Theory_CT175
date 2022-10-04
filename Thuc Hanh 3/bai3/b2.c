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

void add_edge(Graph *pG,int x,int y,int w) {
	pG->A[x][y] = w;
	pG->A[y][x] = w;
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
	int h,k;
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&e);
		add_edge(&G,u,v,e);
	}
	scanf("%d%d",&h,&k);
	Dijkstra(&G,h);
	int A[Max_N];
	int temp = k;
	int len = 0;
	A[len] = k;
	while(1){
		if(temp == -1) break;
		printf("temp: %d\n",temp);
		temp = p[temp];
		len++;
		A[len] = temp; 
	}
	
	for(i=len-1;i>=0;i--){
		if(i == 0)
			printf("%d",A[i]);
		else
			printf("%d -> ",A[i]);
	}
		
	return 0;
}


