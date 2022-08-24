#include <stdio.h>
#define MAX_N 100
typedef struct {
	int n,m;
	int A[MAX_N][MAX_N];
} Graph;


void add_edge(Graph *pG,int u,int v) {
	pG->A[u][v] = 1;
	pG->A[v][u] = 1;
	pG->m++;
}
void init_graph(Graph *pG,int n) {
	pG->n = n;
	pG->m = 0;
}


void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

void inKeChung(Graph G,int x,int y){
	int i,flag = 0;
	for(i=1;i<=G.n;i++){
		if(G.A[x][i] == 1 && G.A[y][i] == 1){
		    	printf("%d ",i);
		    	flag =1;
		}
		
	} 
	if(flag == 0) printf("KHONG CHUNG DOI THU");
}

int main(){
	Graph G;
	int n;
 	freopen("HeSinhThaiRung.txt","r",stdin);
	scanf("%d",&n);	
	int i,j,temp;
	init_graph(&G,n);
	for(i=1; i<=n; i++) {
		for(j=1;j<=n;j++){
			scanf("%d",&temp);
			if(temp == 1)
				add_edge(&G,i,j);
		}		
	}

	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",n);
	printGraph(G);
	printf("%d %d\n",x,y);
	inKeChung(G,x,y);
	return 0;
}
