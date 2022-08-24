
#include <stdio.h>
#define MAX_M 500

typedef struct {
    int u, v;
} Edge;

typedef struct {
    int n, m;     
    Edge edges[MAX_M];
} Graph;

//bai_Tap_1
//Ðinh nghia hàm void init_graph(Graph *pG, int n)

void init_graph(Graph *pG, int n){
    pG->n=n;
    pG->m=0;
}

//bai_Tap_2
//them cung u vao do thi pG tro den
void add_edge(Graph *pG, int u, int v){
	
	//dua cung (u, v) vao edges
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	//tang so cung len 1
	pG->m++;
}

//bai_Tap_3.1
void add_edge(Graph *pG, int u, int v) {
	//neu cung (u, v) khong hop le
	if(u<1 || u>pG->n || v<1 || v>pG->n) return;

	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;

	pG->m++;
}

//Bai_tap_3.2
// don do thi co huong
void add_edge(Graph *pG, int u, int v) {
// cung (u, v) deu hop le (1=u,v=n) da co trong do thi thi bo qua khong them vao nua
	int i;
	for(i=0; i<pG->n; i++)
		if(pG->edges[i].u == u && pG->edges[i].v == v)
			return;

	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;

	pG->m++;
}

//Bai_tap_3.3
//don do thi vo huong
void add_edge(Graph *pG, int u, int v) {
// cung (u, v) deu hop le (1=u,v=n) da co trong do thi thi bo qua khong them vao nua
	int i;
	for(i=0; i<pG->n; i++)
		if(pG->edges[i].u == v && pG->edges[i].v == u)
			return;

	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;

	pG->m++;
}

//Bai_Tap_4
// do thi vo huong
//kiem tra dinh u co ke voi dinh v khong. co cung (u, v) hoac (v, u)
int adjacent(Graph *pG,int u,int v) {
	int i;
	for(i=0; i<pG->m; i++) {
		if( (pG->edges[i].u == u && pG->edges[i].v == v) || (pG->edges[i].u == v && pG->edges[i].v == u) )
			return 1;
	}
	return 0;
}

// do thi vo huong
//kiem tra dinh u co ke voi dinh v khong. co cung (u, v)
int adjacent(Graph *pG,int u,int v) {
	int i;
	for(i=0; i<pG->m; i++) {
		if(pG->edges[i].u == u && pG->edges[i].v == v)
			return 1;
	}
	return 0;
}

//Chuong trình chính
int main() {
    Graph G;	//khai bao bien G dung de chua do thi
    init_graph(&G, 4);	//khoi tao do thi
    add_edge(&G, 1, 3);	//them cung (1, 3)
    //1. in so dinh , so cung ra man hinh
    printf("n = %d, m = %d\n", G.n, G.m);
    //2. In cac cung cua do thi ra man hinh
    int e;
    for(e=0; e<G.m; e++)
    	printf("%d %d\n",G.edges[e].u, G.edges[e].v);
    
    
//    init_graph(&G, 5);
//    printf("Do thi co %d dinh va %d cung.", G.n, G.m);
    return 0;
}
