//d? th? vô hu?ng và in danh sách k? c?a các d?nh ra màn hình.
//Ma Tran Dinh Ke 


#include <stdio.h>
#define MAX_N 100
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct{
	ElementType data[MAX_N];
	int size;
}List;

typedef struct{
	int n;
	List adj[MAX_N];
}Graph;

void make_null(List *pL){
	pL->size = 0;
}

void push_back(List *pL,ElementType x){
	pL->data[pL->size] = x;
	pL->size++;
}

ElementType element_at(List *pL,int i){
	return pL->data[i-1];
}

int count_list(List *pL){
	return pL->size;
}

void printList(List *pL){
	int i;
	for(i=0;i<pL->size;i++)
		printf("%d ",pL->data[i]);
}

void init_graph(Graph *pG,int n){
	int u;
	pG->n = n;

	for(u=1;u<=n;u++)
		make_null(&pG->adj[u]);
}

void add_edge(Graph *pG,int u,int v){
	push_back(&pG->adj[u],v);
}

int main(){
	Graph G;
	int n;
	freopen("test8.txt","r",stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	int i,j,h;
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			int u;
			scanf("%d",&u);
			for(h=1; h<=u; h++) {
				add_edge(&G,i,j);
			}
		}
	}
	for(i=1;i<=n;i++){
		printList(&G.adj[i]);
		printf("0");
		printf("\n");
	}
	return 0;
}
