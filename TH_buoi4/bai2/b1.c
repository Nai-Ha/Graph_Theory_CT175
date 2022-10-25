#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
typedef int ElementType;
int mark[Max_N];
int d[Max_N];
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

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

int adjacent(Graph *pG,int x,int y) {
	return pG->A[x][y] > 0;
}
List neighbors(Graph *pG,int x) {
	List L;
	make_null(&L);
	int i;
	for(i=1; i<=pG->n; i++) {
		if(adjacent(pG,x,i))
			push_back(&L,i);
	}
	return L;
}

void dfs(Graph *pG,int u,List *pL){
	int v;
	mark[u] = 1;
	printf("u: %d\n",u);
	List dinhKe = neighbors(pG,u);
	for(v=1;v<=dinhKe.size;v++){
		int a = element_at(&dinhKe,v);
		if(mark[a] == 0){
			dfs(pG,a,pL);
		}
	}
	push_back(pL,u);
}



int main() {
	Graph G;
	int n,m,u,v,i;
	List sort;
	make_null(&sort);
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	printGraph(G);
	for(i=1; i<=n; i++) {
		mark[i] = 0;
	}
	
	int x;
	for(i=1; i<=G.n; i++) {
		d[u] = 0;
		for(x=1; x<=G.n; x++)
			if(G.A[x][i] != 0)
				d[i]++;
	}
	
	for(i=1; i<=G.n; i++) {
		if(mark[i] == 0){
			dfs(&G,i,&sort);
		}		
	}		
	
	for(i=sort.size; i>=1; i--) {
		printf("%d ",element_at(&sort,i));
	}	
	return 0;
}
