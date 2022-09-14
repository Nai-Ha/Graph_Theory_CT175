#include <stdio.h>
#define Max_Vertices 20
#define Max_N 100
typedef int ElementType;
int mark[Max_N];
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

void printList(List *pL){
	int i;
	for(i=0;i<pL->size;i++)
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

int adjacent(Graph *pG,int x,int y) {
	return pG->A[x][y] > 0;
}

int degree(Graph *pG,int x) {
	int deg = 0,i;
	for(i=1; i<=pG->n; i++)
		if(adjacent(pG,x,i))
			deg++;
	return deg;
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


void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

// <!------ Graph -------!>

void breath_first_search(Graph *pG,int u){
	Queue Q;
	int arr[Max_N];
	int i,j;
	List nbors;
	
	make_null(&nbors);
	make_null_queue(&Q);
	enQueue(&Q,u);
	for(i=1;i<=pG->n;i++)
		arr[i] = 0;
	
	while(!emptyQueue(&Q)){
		int x = front(&Q);
		deQueue(&Q);
		if(arr[x] == 1) continue;
		printf("%d\n",x);
		arr[x] = 1;
		nbors = neighbors(pG,x);
		for(j=1;j<=nbors.size;j++){
			int node = element_at(&nbors,j);
			if(arr[node] == 0)
				enQueue(&Q,node);
		}
	}
}

int main() {
	/////////////////////////////////////////////
	// Bai nay luu y ham neighbors, adjacent(pG,x,i) // Vi la do thi co huong
	/*
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
*/
	////////////////////////////////////////////
	freopen("b2.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u,v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G, u, v);
	}
	
	printGraph(G);

	breath_first_search(&G,1);
	return 0;
}
