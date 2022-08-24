//d? th? có hu?ng và in các cung c?a nó ra màn hình.
//MA TRan Dinh Ke -> danh sach cung

#include <stdio.h>
#define MAX_N 100

typedef struct {
	int u,v;
} Edge;

typedef struct {
	int n,m;
	Edge Edges[MAX_N];
} Graph;

void init_graph(Graph *pG,int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG,int u,int v) {
	pG->Edges[pG->m].u = u;
	pG->Edges[pG->m].v = v;
	pG->m++;
}

int main() {
	Graph G;
	int n;
	freopen("test7.txt","r",stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	int i,j,h;
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			int u;
			scanf("%d",&u);
			for(h=1; h<=u; h++) {
				add_edge(&G,i,j);
			}
		}
	}

	for(i=0; i<G.m; i++)
		printf("%d %d\n",G.Edges[i].u,G.Edges[i].v);
	return 0;
}
