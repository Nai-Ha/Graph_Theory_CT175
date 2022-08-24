
// don do thi vo huong MA TRAN KE
#include <stdio.h>
#define MAX_N 100

typedef struct{
	int u,v;
} Edge;

typedef struct{
	int n,m;
	int A[MAX_N][MAX_N];
}Graph;


void init_graph(Graph *pG,int n){
	int i,j;
	pG->n = n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			pG->A[i][j] = 0;
	pG->m = 0;
}

void add_edge(Graph *pG,int u,int v){
	pG->A[u][v] = 1;
	pG->A[v][u] = 1;
	pG->m++;
}

//Hàm main()
int main() {
    Graph G;
    int n, m, e;
    freopen ("test1.txt","r",stdin);
    //Ð?c s? d?nh, s? cung và kh?i t?o d? th? n d?nh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
	int u,v;
    //Ð?c m cung và thêm vào d? th?
    for ( e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    //In ma tr?n k? c?a d? th?
    for ( u = 1; u <= G.n; u++) {
        for ( v = 1; v <= G.n; v++)
            printf("%d ", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
