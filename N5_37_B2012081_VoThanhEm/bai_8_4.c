
//MA TRAN KE

// do thi co huong (co the chua da cung va chua khuyen)

#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n,m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG,int n) {
	int i,j;
	pG->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			pG->A[i][j] = 0;
	pG->m = 0;
}

// do thi co huong (co the chua da cung va chua khuyen)
void add_edge(Graph *pG,int u,int v) {
	//vo huong =1; chua da cung la +=1;
	pG->A[u][v] +=1 ;
	pG->m++;
}



int main() {
	Graph G;
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int i,j,u,v;
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	
	printf("Ma tran ke:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
	return 0;
}
