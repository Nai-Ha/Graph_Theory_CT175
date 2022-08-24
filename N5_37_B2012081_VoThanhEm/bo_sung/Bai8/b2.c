#include <stdio.h>
#define MAX_N 100
#define MAX_M 500
typedef struct {
	int data[MAX_N];
	int size;
} List;

typedef struct {
	List adj[MAX_N];
	int n,m;
} Graph;

void make_null(List *pL) {
	pL->size = 0;
}

void push_back(List *pL,int x) {
	pL->data[pL->size] = x;
	pL->size++;
}

int element_at(List *pL,int p) {
	return pL->data[p-1] || 0;
}

int size(List *pL) {
	return pL->size;
}

int empty(List *pL) {
	return pL->size == 0;
}
void printList(List *pL) {
	int i;
	for(i=0; i<pL->size; i++)
		printf("%d ",pL->data[i]);
}

void init_graph(Graph *pG,int n,int m) {
	pG->n = n;
	pG->m = m;
}

// Co huong
void add_edge(Graph *pG,int x,int y) {
	push_back(&(pG->adj[x]),y);
	push_back(&(pG->adj[y]),x);
}

void inMTranDinhKe(Graph *pG) {
	int i;
	for(i=1; i<=pG->n; i++) {
		if(!empty(&(pG->adj[i]))) {
			printf("%d ",i);
			printList(&(pG->adj[i]));
			printf("\n");
		}

	}
}

int countNode(List L,int x){
	int i,count = 0;
	for(i=0;i<L.size;i++)
		if(L.data[i] == x)
			count++;
	return count;
}

void printMatranke(Graph *pG){
	int X[100][100];
	int u,v;
	for(u=1;u<=pG->n;u++){
		for(v=1;v<=pG->n;v++){
			X[u][v] = countNode(pG->adj[u],v);
		}
	}
	for(u=1;u<=pG->n;u++){
		for(v=1;v<=pG->n;v++)
			printf("%d ",X[u][v]);
		printf("\n");
	}
}

int main() {
	Graph G;
	freopen("test1.txt","r",stdin);
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	int e;
	for(e=1; e<=m; e++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	printf("%d\n",n);
	inMTranDinhKe(&G);
	printMatranke(&G);
	return 0;
}


