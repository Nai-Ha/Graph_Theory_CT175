#include <stdio.h>
#define MAXN 100
#define NO_EDGE 0
#define oo 99999
typedef int ElementType;
typedef struct{
	int C[MAXN][MAXN];
	int F[MAXN][MAXN];
	int n;
}Graph;

typedef struct{
	int dir;
	int p;
	int sigma;
}Label;

typedef struct {
	int data[MAXN];
	int front;
	int Rear;
} Queue;


Label labels[MAXN];

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
void init_graph(Graph *G,int n) {
	int i,j;
	G->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->C[i][j] = 0;
}

void printGraph(Graph G) {
	int i,j;
	for(i=1; i<=G.n; i++) {
		for(j=1; j<=G.n; j++)
			printf("%d ",G.C[i][j]);
		printf("\n");
	}
}

void init_flow(Graph *pG){
	int u,v;
	for(u=1;u<=pG->n;u++)
		for(v=1;v<=pG->n;v++)
			pG->F[u][v] = 0;
}

void initLabel(Graph *pG,int s){
	int u;
	for(u=1;u<=pG->n;u++)
		labels[u].dir = 0;
	
	labels[s].dir = 1;
	labels[s].p = s;
	labels[s].sigma = oo;
	
}

int min(int a,int b){
	if(a > b) return b;
	return a;
}

int checkExistFlow(Graph *pG,Queue *pQ,int t){
	int found = 0;
	int u,v,x;
	while(!emptyQueue(pQ)){
		u = front(pQ);
		deQueue(pQ);
		
		for(v=1;v<=pG->n;v++){
			if(pG->C[u][v] != NO_EDGE
				&& labels[v].dir == 0
				&& pG->F[u][v] < pG->C[u][v]
			){
				labels[v].dir = 1;
				labels[v].p = u;
				labels[v].sigma = 
					min(labels[u].sigma,
					pG->C[u][v] - pG->F[u][v]);			
				enQueue(pQ,v);			
			}
		}
		
		for(x=1;v<=pG->n;x++){
			if(pG->C[x][u] != NO_EDGE
				&& labels[x].dir == 0
				&& pG->F[x][u] > 0
			){
				labels[x].dir = -1;
				labels[x].p = u;
				labels[x].sigma = 
					min(labels[u].sigma,
					pG->F[x][u]);			
				enQueue(pQ,x);			
			}
		}
		
		if(labels[t].dir != 0){
			found = 1;
			break;
		}
	}
	
	return found;
}

int FordFullkerson(Graph *pG,int s,int t){
	Queue Q;
	int max_flow = 0;
	int u,v;
	
	init_flow(pG);
	do{
		// Buoc 1
		initLabel(pG,s);
		make_null_queue(&Q);
		enQueue(&Q,s);
		
		// Buoc 2
		int found = checkExistFlow(pG,&Q,t);
		
		// Buoc 3
		if(found == 1){
			int sigma = labels[t].sigma; // Luong luong tang them
			
			// Cap nhat luong cua cac cung tren duong tang luong
			int u = t;
			while(u!= s){
				int  p = labels[u].p;
				if(labels[u].dir > 0) // tang luong
					pG->F[p][u] += sigma;
				else
					pG->F[u][p] -= sigma;
				u = p;
			}
			max_flow += sigma;
		}else
			break;		
	}while(1);
	return max_flow;
}

int main() {
	Graph G;
	int n,m,u,v,w,i;
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		G.C[u][v] = w;
	}
	int max_flow = FordFullkerson(&G,1,n);
	
	printf("Max flow: %d\n",max_flow);
	printf("S: ");
	for(i=1; i<=G.n; i++) {
		if(labels[i].dir != 0)
			printf("%d ",i);
	}
	printf("\nT: ");
	for(i=1; i<=G.n; i++) {
		if(labels[i].dir == 0)
			printf("%d ",i);
	}

	return 0;
}
