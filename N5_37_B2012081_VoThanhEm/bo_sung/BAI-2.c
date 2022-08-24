//"Ma tr?n d?nh - cung" 
//dùng d? bi?u di?n các d? th? vô hu?ng, không ch?a khuyên.

#include <stdio.h>
#define Max_M 500
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
int size;
} List;
typedef struct {
    int A[100][500];
    int n, m;
} Graph;

/* Tao danh sach rong */
void make_null(List* L) {
L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
L->data[L->size] = x;
L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
return L->size;
}

void init_graph(Graph *pG,int n,int m){
	int u,e;
	pG->n = n;
	pG->m = m;
	for(u=1;u<=n;u++)
		for(e=1;e<=m;e++)
			pG->A[u][e] = 0;
}

void add_edge(Graph *pG,int e,int x,int y){
	pG->A[x][e] = 1;
	pG->A[y][e] = 1;
}

int checkElList(List L,int x){
	int i;
	for(i=0;i<L.size;i++)
		if(x == L.data[i]) return 1;
	return 0;
}

List neighbors(Graph *pG,int x){
	int e,u;
	List lst_neighbors;
	make_null(&lst_neighbors);
	for(e=1;e<=pG->m;e++){
		if(pG->A[x][e] > 0){
			for(u=1;u<=pG->n;u++)
				if(pG->A[u][e] > 0 
				&& pG->A[u][e] != u 
				&& !checkElList(lst_neighbors,u))
					push_back(&lst_neighbors,u);		
		}
	}
	return lst_neighbors;
}

void printGraph(Graph *pG) {
	int u,e;
	for(u=1; u<=pG->n; u++) {
		for(e=1; e<=pG->m; e++)
			printf("%d ",pG->A[u][e]);
		printf("\n");
	}
}

int main(){
	Graph G;
	freopen("BAI2.txt","r",stdin);
	int n,m,u,v,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);

	for(e=1; e<=m; e++) {
		scanf("%d%d",&u,&v);
		add_edge(&G,e,u,v);
	}
	int i;
	List L = neighbors(&G,1);
	for(i=0;i<L.size;i++)
		printf("%d\n",L.data[i]);
//	printGraph(&G);
	return 0;
}


