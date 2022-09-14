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

typedef struct {
	ElementType data[MAX_SIZE];
	int top_idx;
} Stack;

// Stack
void make_null_stack(Stack *pS) {
	pS->top_idx = -1;
}

void push(Stack *pS,ElementType u) {
	(pS->top_idx)++;
	pS->data[pS->top_idx] = u;
}

ElementType top(Stack *pS) {
	return pS->data[pS->top_idx];
}

void pop(Stack *pS) {
	pS->top_idx--;
}

int empty(Stack *pS) {
	return pS->top_idx == -1;
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

void sortListDESC(List *pL){
	int i,j;
	for(i=0;i<pL->size;i++){
		for(j=i+1;j<pL->size;j++){
			if(pL->data[i] < pL->data[j]){
				int temp = pL->data[j];
				pL->data[j] = pL->data[i];
				pL->data[i] = temp; 
			}
			
		}
	}
}

List deapth_first_search(Graph *pG,int x,int parent[]) {
	Stack S;
	List listDFS;
	make_null(&listDFS);
	make_null_stack(&S);
	int i;
	push(&S,x);
	while(!empty(&S)) {
		int u = top(&S);
		pop(&S);
		if(mark[u] == 1)
			continue;
//		printf("Duyet: %d\n",u);
		push_back(&listDFS,u);
		mark[u] = 1;
		List lstNeighbors = neighbors(pG,u);
		sortListDESC(&lstNeighbors);
		for(i=1; i<=lstNeighbors.size; i++) {
			int v = element_at(&lstNeighbors,i);
			if(mark[v] == 0) {
				push(&S,v);
				parent[v] = u;
			}
		}
	}
	return listDFS;
}
int main() {
	Graph G;
	int n,m,u,v,i,j;
	freopen("b1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	printGraph(G);
	
	int parent[Max_Vertices];	
	printf(">>>>Duyet Theo Chieu Sau <<<<<\n");

	for(i=1; i<=G.n; i++){
		parent[i] = -1;
		mark[i] = 0;
	}
		
	for(i=1; i<=G.n; i++) {
		if(mark[i] == 0) {
			List dfs = deapth_first_search(&G,i,parent);
			for(j=1; j<=dfs.size; j++) {
				int k = element_at(&dfs,j);
//				printf("Duyet: %d\n",k);
				mark[k] = 1;
			}
		}
	}
	
	printf(">>>>Parent cua tung dinh <<<<<\n");
	for(i=1;i<=G.n;i++){
		printf("%d %d\n",i,parent[i]);
	}
	return 0;
}


