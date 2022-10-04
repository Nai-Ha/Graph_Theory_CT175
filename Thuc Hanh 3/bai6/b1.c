#include <stdio.h>
#define Max_N 100
#define NO_EDGE -1
#define OO 9999


typedef struct {
	int u,v,w;
} Edge;


typedef struct {
	Edge Edges[Max_N];
	int n,m;
} Graph;

int pi[Max_N];
int p[Max_N];
int mark[Max_N];

void init_graph(Graph *G,int n) {
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *pG,int x,int y,int w) {
	pG->Edges[pG->m].u = x;
	pG->Edges[pG->m].v = y;
	pG->Edges[pG->m].w = w;
	pG->m++;
}

void printGraph(Graph G) {
	int i;
	for(i=0; i<G.m; i++) {
		printf("%d %d %d\n",G.Edges[i].u,G.Edges[i].v,G.Edges[i].w);
	}
}

void BellmanFord(Graph *pG,int s){
	int u,v,w,it,k;
	for(u=1;u<=pG->n;u++){
		pi[u] = OO;
	}
	pi[s] = 0;
	p[s] = -1;
	
	for(it=1;it<=pG->n;it++){
		for(k=0;k<pG->m;k++){
			u = pG->Edges[k].u;
			v = pG->Edges[k].v;
			w = pG->Edges[k].w;
			if(pi[u] == OO)
				continue ;
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w ;
				p[v] = u;
			}
		}
	}

}

int main() {
	Graph G;
	int n,m,u,v,e,i;
  	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&e);
		add_edge(&G,u,v,e);
	}
	int start,end;
	scanf("%d%d",&start,&end);
// 	printGraph(G);	
 	BellmanFord(&G,start);
 	if(pi[end] == OO)
 		printf("-1");
 	else
 		printf("%d",pi[end]);
	return 0;
}


