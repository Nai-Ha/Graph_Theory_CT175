#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
typedef int ElementType;
int mark[Max_N];
typedef struct {
	int A[Max_Vertices][Max_Vertices];
	int n;
} Graph;

typedef struct {
	int data[Max_Length];
	int size;
} List;

typedef struct{
	int data[Max_N];
	int front;
	int Rear;
}Queue;

// Queue
void make_null_queue(Queue *pQ){
	pQ->front = 0;
	pQ->Rear = -1;
}

void enQueue(Queue *pQ,int u){
	pQ->Rear++;
	pQ->data[pQ->Rear] = u; 
}

void deQueue(Queue *pQ){
	pQ->front++;
}

ElementType front(Queue *pQ){
	return pQ->data[pQ->front];
}

int emptyQueue(Queue *pQ){
	return pQ->front > pQ->Rear;
}

// Graph
void init_graph(Graph *G,int n) {
	int i,j;
	G->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph *pG,int x,int y) {
	pG->A[x][y] = 1;
//	pG->A[y][x] = 1;
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

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

// List
void make_null(List *pL) {
	pL->size = 0;
}

void push_back(List *pL,int x) {
	pL->data[pL->size] = x;
	pL->size++;
}

int element_at(List *pL,int i) {
	return pL->data[i-1];
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

void printList(List *pL){
	int i;
	printf("list: ");
	for(i=0;i<pL->size;i++)
		printf("%d ",pL->data[i]);
	printf("\n");
}

List breath_first_search(Graph *pG,int u,int parent[]){
	Queue Q;
	int i;
	int arr[Max_N];
	List lstBFS;
	make_null(&lstBFS);
	make_null_queue(&Q);
	enQueue(&Q,u);
	while(!emptyQueue(&Q)){
		int v = front(&Q);
		deQueue(&Q);
		if(mark[v] == 1) continue;
//		printf("Duyet: %d\n",v);
		mark[v] = 1;
		push_back(&lstBFS,v);
		List lstNeighbors = neighbors(pG,v);
		for(i=1;i<=lstNeighbors.size;i++){
			int a = element_at(&lstNeighbors,i);
			if(mark[a] == 0){
				enQueue(&Q,a);
				if(parent[a] == -1)
					parent[a] = v;
			}
		}
	}
	return lstBFS;
}

int main() {
	Graph G;
	int n,m,u,v,i,j;
	freopen("b1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	int parent[MAX_SIZE];
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	printGraph(G);
	
//	printf(">>>>> Duyet do thi theo chieu rong <<<<<<\n");
	for(i=1;i<=G.n;i++){
		parent[i] = -1;
		mark[i] = 0;
	}
		
	for(i=1;i<=G.n;i++){
		if(mark[i] == 0){
			List lst_bfs = breath_first_search(&G,i,parent);
//			printList(&lst_bfs);
			for(j=1;j<=lst_bfs.size;j++){
				int h = element_at(&lst_bfs,j);
				if(mark[i] == 0)
//					printf("Duyet: %d\n",h);
				mark[h] = 1;
			}
		}
	}
		
//	printf(">>>>> Dung Cay <<<<<<\n");
	for(i=1;i<=G.n;i++){
		printf("%d %d\n",i,parent[i]);
	}
	
	

	return 0;
}


