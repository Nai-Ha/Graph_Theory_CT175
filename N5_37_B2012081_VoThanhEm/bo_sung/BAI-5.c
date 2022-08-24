#define MAX_EDGE 100
typedef struct  {
	 int x, y;
} Edge;
typedef struct {
	int n, m;
	Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph* G, int n){
	G->n = n;
	G->m = 0;
}

//BAi 5_1
void add_edge(Graph *G,int x,int y){
	G->edges[G->m].x = x;
	G->edges[G->m].y = y;
	G->m++;
}

//BAi 5_2
//Danh s�ch cung
//N?u cung (x, y) kh�ng h?p l? (vd: x < 1, y > n, ...) th� b? qua kh�ng l�m g� c?.
void add_edge(Graph *G,int x,int y){
	if(x < 1 || y > G->n || x>G->n){
		return ;
	}
	G->edges[G->m].x = x;
	G->edges[G->m].y = y;
	G->m++;
}
