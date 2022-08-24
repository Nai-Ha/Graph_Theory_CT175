//  d? th? có hu?ng (có th? ch?a da cung và khuyên) 
//và in các d?nh k? c?a các d?nh ra màn hình.

//Bi?u di?n d? th? b?ng phuong pháp "Ma tr?n k?".

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

void add_edge(Graph *pG,int u,int v) {
	pG->A[u][v]++;
	pG->m++;
}

int adjacent(Graph *pG,int u,int v){
	return pG->A[u][v] > 0;
}

void neighbours(Graph *pG,int x){
	int i,j;
	for(i=1;i<=pG->n;i++){
		if(adjacent(pG,x,i))
			printf("%d ",i);
	}
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

	for(i=1;i<=n;i++){
		printf("neighbours(%d) = ",i);
		neighbours(&G,i);
		printf("\n");
	}
	return 0;
}
