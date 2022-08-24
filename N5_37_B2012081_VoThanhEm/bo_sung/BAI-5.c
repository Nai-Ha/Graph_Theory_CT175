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
//Danh sách cung
//N?u cung (x, y) không h?p l? (vd: x < 1, y > n, ...) thì b? qua không làm gì c?.
void add_edge(Graph *G,int x,int y){
	if(x < 1 || y > G->n || x>G->n){
		return ;
	}
	G->edges[G->m].x = x;
	G->edges[G->m].y = y;
	G->m++;
}
