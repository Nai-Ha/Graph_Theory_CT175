#include <stdio.h>
#define Max_N 100
#define NO_EDGE -1
#define OO 9999

typedef struct {
	int A[Max_N][Max_N];
	int n;
} Graph;

int pi[Max_N];
int p[Max_N];
int mark[Max_N];
int w[Max_N];

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

void Dijkstra(Graph *pG,int s) {
	// khoi tao
	int u,i,j,v,h;
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
	int n,m,u,i,j,k;
	int v,e;
	int i_ke,j_ke;
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n*m);
	for(i=0; i<n; i++) {
		for(j=0;j<m;j++){
			scanf("%d",&u);
			w[i*m+j+1] = u;
		}
	}
	
//	for(i=0; i<n; i++) {
//		for(j=0;j<m;j++){
//			printf("%d ",w[i*m+j+1]);
//		}
//		printf("\n");
//	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int di[] = {-1,1,0,0};
			int dj[] = {0,0,-1,1};

			for(k=0;k<4;k++){
				i_ke = i + di[k];
				j_ke = j + dj[k];

				if((i_ke >= 0) && (i_ke < n)
				&& (j_ke >=0) && (j_ke<m)){
					v = i_ke*m + j_ke +1; // Tinh ra dinh ke cua nut dang dung
					e = i*m + j +1; // Tinh ra dinh dang dung
					G.A[e][v] = w[v];
				}
			}
		}

	}
	Dijkstra(&G,1);
	printf("%d",pi[G.n]);

	return 0;
}


