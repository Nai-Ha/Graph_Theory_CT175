#include <stdio.h>

/* Khai b�o CTDL Graph*/
#define MAX_N 100
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int u = 1 ; u <= n; u++)
        for (int v = 1 ; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
    if (u != v)
        pG->A[v][u] += 1;
    
    pG->m++;
}

int adjacent(Graph *pG, int u, int v) {
    return pG->A[u][v] > 0;
}

/* Khai b�o CTDL Stack */

#define MAX_SIZE 100
typedef int ElementType;
typedef struct {
	ElementType data[MAX_SIZE];
	int top_idx;
} Stack;
/* H�m kh?i t?o ngan x?p r?ng */
void make_null_stack(Stack *pS) {
	pS->top_idx = -1;
}
/* H�m th�m ph?n t? u v�o d?nh ngan x?p */
void push(Stack *pS, ElementType u) {
	pS->top_idx++;
	pS->data[pS->top_idx] = u;
}
/* H�m xem ph?n t? tr�n d?nh ngan x?p */
ElementType top(Stack *pS) {
	return pS->data[pS->top_idx];
}
/* H�m xo� b? ph?n t? tr�n d?nh ngan x?p */
void pop(Stack *pS) {
	pS->top_idx--;
}
/* H�m ki?m tra ngan x?p r?ng */
int empty(Stack *pS) {
	return pS->top_idx == -1;
}


/* DFS: Duy?t d? th? theo chi?u s�u */
//Bi?n h? tr? d�ng d? luu tr?ng th�i c?a d?nh: d� duy?t/chua duy?t
int mark[MAX_N];
void DFS(Graph *pG, int s) {
	//1. Khai b�o ngan x?p S, kh?i t?o r?ng
	Stack S;
	make_null_stack(&S);
	//2. �ua s v�o S, b?t d?u duy?t t? d?nh s */
	push(&S, s);
	//3. V�ng l?p ch�nh d�ng d? duy?t
	while (!empty(&S)) {
		//3a. L?y ph?n t? tr�n d?nh S ra
		int u = top(&S); pop(&S);
		if (mark[u] != 0) 		//u d� duy?t r?i, b? qua
			continue;

		printf("%d\n", u);	//L�m g� d� tr�n u
		mark[u] = 1; 			//��nh d?u n� d� duy?t
		//3b. X�t c�c d?nh k? c?a u, dua v�o ngan x?p S
		for (int v = pG->n; v >= 1; v--)
			if (adjacent(pG, u, v))
				push(&S, v);
	}
}


int main() {
	//1. Khai b�o d? th? G
	Graph G;
	//2. �?c d? li?u v� d?ng d? th?
	int n, m, u, v, s;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (int e = 0; e < m; e++) {
	    scanf("%d%d", &u, &v);
	    add_edge(&G, u, v);
	}

	scanf("%d", &s);

	//3. Kh?i t?o m?ng mark[u] = 0, v?i m?i u = 1, 2, ..., n
	for (int u = 1; u <= G.n; u++)
		mark[u] = 0;
	//4. G?i h�m DFS duy?t theo chi?u s�u t? d?nh 1
	DFS(&G, s);

	return 0;
}


