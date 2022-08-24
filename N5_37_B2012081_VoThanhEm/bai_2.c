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
