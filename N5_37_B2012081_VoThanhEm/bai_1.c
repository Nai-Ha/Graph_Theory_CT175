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

// lam them
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

//Chuong trình chính
int main() {
    Graph G;	//khai bao bien G dung de chua do thi
    init_graph(&G, 5);	//khoi tao do thi
    printf("Do thi co %d dinh va %d cung.", G.n, G.m);
    return 0;
}
