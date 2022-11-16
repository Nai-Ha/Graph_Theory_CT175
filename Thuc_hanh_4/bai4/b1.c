#include <stdio.h>
#define Max_N 100
typedef int ElementType;

int rank[Max_N];
int mark[Max_N];
typedef struct {
	int A[Max_N][Max_N];
	int n;
} Graph;

typedef struct {
	int data[Max_N];
	int size;
} List;

typedef struct {
	int data[Max_N];
	int front;
	int Rear;
} Queue;

// <!------ List -------!>
void make_null(List *pL) {
	pL->size = 0;
}

void push_back(List *pL,int x) {
	pL->data[pL->size] = x;
	pL->size++;
}

int element_at(List *pL,int p) {
	return pL->data[p-1];
}

void printList(List *pL) {
	int i;
	for(i=0; i<pL->size; i++)
		printf("%d ",pL->data[i]);
	printf("\n");
}
// <!------ List -------!>

// <!------ Queue -------!>
void make_null_queue(Queue *pQ) {
	pQ->front = 0;
	pQ->Rear = -1;
}

void enQueue(Queue *pQ,int u) {
	pQ->Rear++;
	pQ->data[pQ->Rear] = u;

}

void deQueue(Queue *pQ) {
	pQ->front++;
}

ElementType front(Queue *pQ) {
	return pQ->data[pQ->front];
}

int emptyQueue(Queue *pQ) {
	return pQ->front > pQ->Rear;
}
// <!------ Queue -------!>

// <!------ Graph -------!>
void init_graph(Graph *G,int n) {
	int i,j;
	G->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph *pG,int x,int y) {
	pG->A[x][y] = 1;
}

// void printGraph(Graph G) {
// 	int i,j;
// 	for(i=1; i<=G.n; i++) {
// 		for(j=1; j<=G.n; j++)
// 			printf("%d ",G.A[i][j]);
// 		printf("\n");
// 	}
// }

void copy_list(List *pL1,List *pL2){
	make_null(pL1);
	int i;
	for(i=1;i<=pL2->size;i++){
		int a = element_at(pL2,i);
		push_back(pL1,a);
	}
}

void ranking(Graph *pG){
	int d[Max_N];
	int u,x,i,v;
	// Tinh bac vao
	for(u=1;u<=pG->n;u++){
		d[u] = 0;
		for(x=1;x<=pG->n;x++){
			if(pG->A[x][u] != 0)
				d[u]++;
		}
	}
	
	for(u=1;u<=pG->n;u++){
		d[u] = 0;
		for(x=1;x<=pG->n;x++){
			if(pG->A[x][u] != 0)
				d[u]++;
		}
	
	}
	
	List L1,L2;
	make_null(&L1);
	for(u=1;u<=pG->n;u++){
		if(d[u] == 0)
			push_back(&L1,u);
	}
	
	int k = 0;
	while(L1.size > 0){
		make_null(&L2);
		for(i=1;i<=L1.size;i++){
			int a = element_at(&L1,i);
			rank[a] = k;
			for(v=1;v<=pG->n;v++){
				if(pG->A[a][v] != 0){
					d[v]--;
					if(d[v] == 0)
						push_back(&L2,v);
				}
			}
		}
		copy_list(&L1,&L2);
		k++;
	}

}

void printRank(Graph *pG){
	int i;
	for(i=1;i<=pG->n;i++)
		printf("r[%d] = %d\n",i,rank[i]);
}


int main() {
	Graph G;
	int n,m,u,v,i;
//	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
//	printGraph(G);
	ranking(&G);
	printRank(&G);
	return 0;
}
