#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
#define OO 9999
typedef int ElementType;
int parent[Max_N];
typedef struct{
	int u,v,w;
}Edge;

typedef struct {
	int n,m;
	Edge Edges[MAX_SIZE];
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
void init_graph(Graph *pG,int n) {
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG,int x,int y,int w) {
	pG->Edges[pG->m].u = x;
	pG->Edges[pG->m].v = y;
	pG->Edges[pG->m].w = w;
	pG->m++;
}

void printGraph(Graph G) {
	int i,j;
	for(i=0; i<G.m; i++) 
		printf("%d %d %d\n",G.Edges[i].u,G.Edges[i].v,G.Edges[i].w);
	
}

int findRoot(int u){
	while(parent[u] != u)
		u = parent[u];
	return u;
}

void sortEdge(Graph *pG){
	int i,j;
	for(i=0;i<pG->m;i++)
		for(j=i+1;j<pG->m;j++)
			if(pG->Edges[i].w > pG->Edges[j].w){
				Edge temp = pG->Edges[i];
				pG->Edges[i] = pG->Edges[j];
				pG->Edges[j] = temp;
			}
}

int Kruskal(Graph *pG,Graph *pT){
	// Sap xep cung theo thu tu tang 
	sortEdge(pG);
	
	// Khoi tao cay khung khong chua cung nao,khoi tao BPLT
	init_graph(pT,pG->n);
	int u,e;
	for(u=1;u<=pG->n;u++)
		parent[u] = u;
	int sum_w = 0;
	
	// Duyet qua cac cung cua G
	for(e=0;e<pG->m;e++){
		int x = pG->Edges[e].u;
		int y = pG->Edges[e].v;
		int t = pG->Edges[e].w;
		int root_x = findRoot(x);
		int root_y = findRoot(y);
		
		if(root_x != root_y){
			// Them cung
			if(x < y)
				add_edge(pT,x,y,t);
			else 
				add_edge(pT,y,x,t);
			
			// Gop 2 BPLT root_x va root_y
			parent[root_y] = root_x;
			sum_w += t;
		}
 	}
 	return sum_w;
}

int totalWeight(Graph *pG){
	int i;
	int total = 0;
	for(i=0;i<pG->m;i++)
		total += pG->Edges[i].w;
	return total;
}

int main() {
	Graph G,T;
	int n,m,u,v,i,j,w;
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
//		printf("u v w: %d %d %d\n",u,v,w);
		add_edge(&G,u,v,w);
	}
	printGraph(G);
	
	int sum_w_tree_root = totalWeight(&G);
	int sum_w = Kruskal(&G,&T);
	printf("%d\n",sum_w_tree_root - sum_w);
//	for(i=0;i<T.m;i++)
//		printf("%d %d %d\n",T.Edges[i].u,T.Edges[i].v,T.Edges[i].w);
		
	return 0;
}
