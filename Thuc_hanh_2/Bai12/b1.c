#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
#define NO_COLOR 0
#define BLUE 1
#define RED 2

int color[Max_N];
int conflict;
int mark[Max_N];

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
		if(adjacent(pG,i,x))
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
List breath_first_search(Graph *pG,int u){
	Queue Q;
	int j;
	List nbors;
	List bfs;
	
	make_null(&bfs);
	make_null(&nbors);
	make_null_queue(&Q);
	enQueue(&Q,u);
	
	while(!emptyQueue(&Q)){
		int x = front(&Q);
		deQueue(&Q);
		if(mark[x] == 1) continue;
		push_back(&bfs,x);
		mark[x] = 1;
		nbors = neighbors(pG,x);
		for(j=1;j<=nbors.size;j++){
			int node = element_at(&nbors,j);
			if(mark[node] == 0)
				enQueue(&Q,node);
		}
	}
	return bfs;
}

void colorize(Graph *pG,int u,int c){
	color[u] = c;
	int v;
	for(v=1;v<=pG->n;v++){
		if(adjacent(pG,u,v)){
			if(color[v] == NO_COLOR)
				colorize(pG,v,3-c);
			else if(color[v] == color[u])
				conflict = 1;
		}
	}
}

void inNhomNguoi(Graph *pG,int e){
	int j,flag = 0;
	if(conflict == 0){
		for(j=1;j<=pG->n;j++){
			if(color[e] == color[j])
				if(mark[j] == 0){ // Doan code nay dung de kiem tra thang nao in roi thi khong in nua
					printf("%d ",j);
					mark[j] = 1;
					flag = 1; // dung bien tam de in xuong dong 1 lan khi duyet qua thoi neu khong co thi moi lan duyen qua thi no in xuong dong
				}
			}
	}
	if(flag) printf("\n");
}

int main() {
	Graph G;
	int n,m,e,u,v;
  	freopen("test.txt","r",stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 1; e <= m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G, u, v);
	}
	
	for(e=1;e<=G.n;e++){
		color[e] = NO_COLOR;
		mark[e] = 0;
	}
	
	conflict = 0;
	int j;
	for(e=1;e<=G.n;e++){
		if(color[e] == NO_COLOR){
			colorize(&G,e,BLUE);
		}
		if(conflict == 0){
			inNhomNguoi(&G,e);
		}
	}
	if(conflict == 1) printf("IMPOSSIBLE");

	
	return 0;
}
