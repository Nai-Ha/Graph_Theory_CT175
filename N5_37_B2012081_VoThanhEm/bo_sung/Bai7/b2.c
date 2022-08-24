#include <stdio.h>
#define MAX_N 100
typedef struct {
	int n,m;
	int A[MAX_N][MAX_N];
} Graph;


void add_edge(Graph *pG,int u,int v) {
	pG->A[u][v] = 1;
	pG->A[v][u] = 1;
	pG->m++;
}
void init_graph(Graph *pG,int n) {
	pG->n = n;
	pG->m = 0;
}


void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

int inSoDoiThucCanhTranChung(Graph G,int x,int y){
	int i,count = 0;
	for(i=1;i<=G.n;i++){
		if(G.A[x][i] == 1 && G.A[y][i] == 1)
		    	count++;
	} 
	return count;
}

int main(){
	Graph G;
	int n,m,u,v;
 	freopen("test2.txt","r",stdin);
	scanf("%d%d",&n,&m);	
	init_graph(&G,n);
	int i;
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}

	int x,y;
	scanf("%d%d",&x,&y);
	printGraph(G);
	printf("%d",inSoDoiThucCanhTranChung(G,x,y));

	return 0;
}
