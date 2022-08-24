//

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

void add_edge(Graph *pG,int x,int y){
	pG->A[x][y] = 1;
	pG->A[y][x] = 1;
}

int degree(Graph *pG,int x){
	int e,deg = 0;
	for(e=1;e<=pG->n;e++)
		if(pG->A[x][e] > 0)
			deg++;
	return deg;
}

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

int getVerticleMaxDegree(Graph *pG){
	int i,e,max = 1;
	for(i=1;i<=pG->n;i++)
		if(degree(pG,max) < degree(pG,i))
			max = i;
	return max;
}
int main(){
	Graph G;
	int n, m, u, v, w, e;
	freopen("dothi.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
//	printGraph(G);
	int max_ver = getVerticleMaxDegree(&G);
	printf("%d %d",max_ver,degree(&G,max_ver));
	return 0;
}
