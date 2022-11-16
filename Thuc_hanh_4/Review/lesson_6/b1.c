#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 20
#define MAX_SIZE 100
#define Max_N 100
#define OO 9999
typedef int ElementType;

int rank[Max_N];
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

void copy_list(List *pL1,List *pL2){
	make_null(pL1);
	int i;
	for(i=1;i<=pL2->size;i++){
		int a = element_at(pL2,i);
		push_back(pL1,a);
	}
}

void printRank(Graph *pG){
	int i;
	for(i=1;i<=pG->n;i++)
		printf("%d ",rank[i]);
	
}

void topo_sort(Graph *pG,List *pL) {
	int temp[Max_N];
	int u,x,v;
	Queue Q;
	for(u=1; u<=pG->n; u++) {
		temp[u] = 0;
		for(x=1; x<=pG->n; x++)
			if(pG->A[x][u] != 0)
				temp[u]++;
	}
	make_null_queue(&Q);
	for(u=1; u<=pG->n; u++)
		if(temp[u] == 0)
			enQueue(&Q,u);

	make_null(pL);
	while(!emptyQueue(&Q)) {
		int a = front(&Q);
		deQueue(&Q);
		push_back(pL,a);
		for(v=1; v<=pG->n; v++) {
			if(pG->A[a][v] != 0) {
				temp[v]--;
				if(temp[v] == 0)
					enQueue(&Q,v);
			}
		}
	}
}

int max(int a,int b){
	if(a > b)
	 return a;
	return b;
}

int min(int a,int b){
	if(a < b)
	 return a;
	return b;
}


int main() {
	Graph G;
	int n,m,u,v,i,j,x;
	
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	
	init_graph(&G,n+2);
	int alpha = n+1,beta = n+2;
	d[alpha] = 0; 
	
	for(u=1;u<=n;u++){
		scanf("%d",&d[u]);
		do{
			scanf("%d",&x);
			if(x>0)
				add_edge(&G,x,u);
		}while(x > 0);
	}
	
	// Them cung noi alpha voi dinh co bac vao  = 0
	for(u=1;u<=n;u++){
		int deg_neg = 0;
		for(x=1;x<=n;x++){
			if(G.A[x][u] > 0)
				deg_neg++;
			if(deg_neg == 0)
				add_edge(&G,alpha,u);
		}
	}
	
	// Them cung noi beta voi dinh co bac ra = 0
	for(u=1;u<=n;u++){
		int deg_pos = 0;
		for(x=1;x<=n;x++){
			if(G.A[u][x] > 0)
				deg_pos++;
			if(deg_pos == 0)
				add_edge(&G,u,beta);
		}
	}
	
	// Xep thu tu cac dinh theo topo
	List L;
	topo_sort(&G,&L);

	// Tinh t[u]
	int t[Max_N];
	t[alpha] = 0;
	
	for(j=2;j<=L.size;j++){
		int h = element_at(&L,j);	
		t[h] = -OO;
		for(x=1;x<=G.n;x++)
			if(G.A[x][h] > 0)
				t[h] = max(t[h],t[x] + d[x]);
	}
	
	// Tinh T[u]
	int T[Max_N];
	T[beta] = t[beta];
	for(j=L.size-1;j>=1;j--){
		int l = element_at(&L,j);
		T[l] = OO;
		for(x=1;x<=G.n;x++)
			if(G.A[l][x] > 0)
				T[l] = min(T[l],T[x] - d[l]);
	}
	
	// In kq
	for(i=1;i<=G.n;i++)
		printf("%d %d\n",t[i],T[i]);
	return 0;
}
