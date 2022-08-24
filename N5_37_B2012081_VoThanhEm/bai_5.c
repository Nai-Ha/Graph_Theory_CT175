
/// Bai_Tap_5.1
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
//	if(u<1 || u>pG->n || v<1 || v>pG->n) return;

	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;

	pG->m++;
}

// ham tinh bac cua dinh
int degree(Graph *pG, int u){
	int i,deg = 0;
	for(i=0;i<pG->m;i++){
		if(pG->edges[i].u == u)
			deg++;
		if(pG->edges[i].v == u)
			deg++;
	}
	return deg;
}

////
int main() {
    Graph G;
    int n = 4, u;

    //Khoi tao do thi
    init_graph(&G, n);
    //Thêm cung vào do thi
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 1, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 1, 4);

    //In bac cua các dinh
    
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;
}
