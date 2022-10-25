#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
typedef int ElementType;
int mark[Max_N];
int r[Max_N];
typedef struct {
	int A[Max_Vertices][Max_Vertices];
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
		printf("%d\n",pL->data[i]);
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

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

void copy_list(List *pL1,List *pL2){
	make_null(pL1);
	int i;
	for(i=1;i<=pL2->size;i++){
		int a = element_at(pL2,i);
		push_back(pL1,a);
	}
}

void rank(Graph *pG){
	int d[Max_N];
	
	int v,x,u,i;
	// Tinh bac vao cua cac dinh
	for(u=1;u<=pG->n;u++){
		d[u] = 0;
		for(x=1;x<=pG->n;x++)
			if(pG->A[x][u] != 0)
				d[u]++;
	}
	
	List S1,S2;
	
	// Tim goc dua vao S1
	make_null(&S1);
	for(u=1;u<=pG->n;u++)
		if(d[u] == 0)
			push_back(&S1,u);
	
	int k = 0; // Rank start 0
	while(S1.size > 0){
		make_null(&S2);
		for(i=1;i<=S1.size;i++){
			int nodeRoot = element_at(&S1,i);
			r[nodeRoot] = k;
			
			// Remove nodeRoot, decreasing level enter of adjacent vertex
			for(v=1;v<=pG->n;v++){
				if(pG->A[nodeRoot][v] != 0){
					d[v]--;
					if(d[v] == 0)
						push_back(&S2,v);
				}
			}
		}
		copy_list(&S1,&S2);
		k++;
	}
	
	
}


int main() {
	Graph G;
 	freopen("test.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int u,v,e;
	for(e=1;e<=m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(e=1;e<=n;e++)
		r[e] = 0;
	rank(&G);
	for(e=1;e<=n;e++)
		printf("r(%d): %d\n",e,r[e]);
	
//	printGraph(G);
	return 0;
}
