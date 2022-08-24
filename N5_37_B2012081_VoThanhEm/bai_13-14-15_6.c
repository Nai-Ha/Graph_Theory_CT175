//Run 2
//#include <stdio.h>
//#define MAX_N 100
//
//typedef struct {
//	int n,m;
//	int A[MAX_N][MAX_N];
//} Graph;
//
//void init_graph(Graph *pG,int n) {
//	int i,j;
//	pG->n = n;
//	for(i=1; i<=n; i++)
//		for(j=1; j<=n; j++)
//			pG->A[i][j] = 0;
//	pG->m = 0;
//}
//
//void add_edge(Graph *pG,int u,int v) {
//	pG->A[u][v]++;
//}
//
//
//int main() {
//	Graph G;
//	int n;
////	freopen("test10.txt","r",stdin);
//	scanf("%d",&n);
//	init_graph(&G,n);
//	int i,j,u;
//	for(i=1; i<=n; i++) {
//		while(1) {
//			scanf("%d",&u);
//			if(u==0)
//				break;
//			add_edge(&G,i,u);
//		}
//
//	}
//
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			printf("%d ",G.A[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//Run 3
//#include <stdio.h>
//#define MAX_N 100
//
//typedef struct {
//	int n,m;
//	int A[MAX_N][MAX_N];
//} Graph;
//
//void init_graph(Graph *pG,int n) {
//	int i,j;
//	pG->n = n;
//	for(i=1; i<=n; i++)
//		for(j=1; j<=n; j++)
//			pG->A[i][j] = 0;
//	pG->m = 0;
//}
//
//void add_edge(Graph *pG,int u,int v) {
//	pG->A[u][v]++;
//}
//
//
//int main() {
//	Graph G;
//	int n;
////	freopen("test10.txt","r",stdin);
//	scanf("%d",&n);
//	init_graph(&G,n);
//	int i,j,u;
//	for(i=1; i<=n; i++) {
//		while(1) {
//			scanf("%d",&u);
//			if(u==0)
//				break;
//			add_edge(&G,i,u);
//		}
//
//	}
//
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			printf("%d ",G.A[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//Run 4
//#include <stdio.h>
//#define MAX_N 100
//
//typedef struct {
//	int n,m;
//	int A[MAX_N][MAX_N];
//} Graph;
//
//void init_graph(Graph *pG,int n) {
//	int i,j;
//	pG->n = n;
//	for(i=1; i<=n; i++)
//		for(j=1; j<=n; j++)
//			pG->A[i][j] = 0;
//	pG->m = 0;
//}
//
//void add_edge(Graph *pG,int u,int v) {
//	pG->A[u][v]++;
//}
//
//
//int main() {
//	Graph G;
//	int n;
////	freopen("test10.txt","r",stdin);
//	scanf("%d",&n);
//	init_graph(&G,n);
//	int i,j,u;
//	for(i=1; i<=n; i++) {
//		while(1) {
//			scanf("%d",&u);
//			if(u==0)
//				break;
//			add_edge(&G,i,u);
//		}
//
//	}
//
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			printf("%d ",G.A[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n,m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG,int n) {
	int i,j;
	pG->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			pG->A[i][j] = 0;
	pG->m = 0;
}

void add_edge(Graph *pG,int u,int v) {
	pG->A[u][v]++;
}


int main() {
	Graph G;
	int n;
	freopen("test10.txt","r",stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	int i,j,u;
	for(i=1; i<=n; i++) {
		while(1) {
			scanf("%d",&u);
			if(u==0)
				break;
			add_edge(&G,i,u);
		}

	}

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",G.A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
