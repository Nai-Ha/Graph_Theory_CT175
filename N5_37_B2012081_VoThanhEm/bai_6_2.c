// Bai_6.2

#include <stdio.h>
#define MAX_M 500

typedef struct {
	int u,v;
} Edge;

typedef struct {
	int n, m;
	Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v) {
	if(u<1 || u>pG->n || v<1 || v>pG->n) return;

	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;

	pG->m++;
}

int degree(Graph *pG, int u) {
	int i,deg = 0;
	for(i=0; i<pG->m; i++) {
		if(pG->edges[i].u == u)
			deg++;
		if(pG->edges[i].v == u)
			deg++;
	}
	return deg;
}

//do thi co huong
int adjacent(Graph *pG,int u,int v) {
	int i;
	for(i=0; i<pG->m; i++) {
		if((pG->edges[i].u == u
		        && pG->edges[i].v == v))
			return 1;
	}
	return 0;
}

void neighbours(Graph *pG,int x) {
	int i;
	for(i=1; i<=pG->n; i++)
		if(adjacent(pG,x,i))
			printf("%d ",i);

}
int main() {
	Graph G;
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int u,v,i;
	for(i=0; i<m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}

// 	for(i=1; i<=n; i++) {
// 		printf("deg(%d) = %d\n",i,degree(&G,i));
// 	}
	for(i=1; i<=n; i++) {
		printf("neighbours(%d) = ",i);
		neighbours(&G,i);
		printf("\n");
	}

	return 0;
}
