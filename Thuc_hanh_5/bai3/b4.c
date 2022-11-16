#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
#define OO 9999
#define NO_EDGE 0
typedef int ElementType;
int p[Max_N];
int pi[Max_N];
int mark[Max_N];
typedef struct {
	int n,m;
	int A[Max_Vertices][Max_Vertices];
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
			G->A[i][j] = NO_EDGE;
}

void add_edge(Graph *pG,int x,int y,int w) {
	pG->A[x][y] = w;
	pG->A[y][x] = w;
}

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
}

int Prim(Graph *pG,Graph *pT,int s){
	int i,u,v,x;
	
	// Khoi tao
	for(u=1;u<=pG->n;u++){
		pi[u] = OO;
		p[u] = -1;
		mark[u] = 0;
	}
	
	pi[s] = 0;
	
	for(i=1;i<pG->n;i++){
		// Tim u gan voi s nhat
		int min_dist = OO;
		for(x=1;x<=pG->n;x++)
			if(mark[x] == 0 && pi[x] < min_dist){
				min_dist = pi[x];
				u = x;
			}
		
		// Danh dau da duyet
		mark[u] = 1;
		for(v=1;v<=pG->n;v++){
			if(pG->A[u][v] != NO_EDGE 
			&& pi[v] > pG->A[u][v] && mark[v] == 0){
				pi[v] = pG->A[u][v];
				p[v] = u;	
			}
		}
	}
	
	// Dung cay
	init_graph(pT,pG->n);
	int sum_w = 0;
	for(u=1;u<=pG->n;u++){
		if(p[u] != -1){
			int w = pG->A[p[u]][u];
//			printf("w: %d\n",w);
			add_edge(pT,p[u],u,w);
			sum_w += w;
		}
	}
	return sum_w;
}

int main() {
	Graph G,T;
	int n,m,u,v,i,w;
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		int a,b;
		scanf("%d%d",&a,&b);
		w = a*b;
		add_edge(&G,u,v,w);
	}
	printGraph(G);	
	int min_sum_w = Prim(&G,&T,1);	
	printf("%d\n",min_sum_w);
		
	return 0;
}
