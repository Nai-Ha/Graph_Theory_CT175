//"Ma tr?n d?nh - cung" 
//d�ng d? bi?u di?n c�c d? th? v� hu?ng, kh�ng ch?a khuy�n.

#include <stdio.h>
#define Max_M 500
#defind Max_N 500

typedef struct {
    int A[100][500];
    int n, m;
} Graph;

void add_edge(Graph *pG,int e,int x,int y){
	pG->A[x][e] = 1;
	pG->A[y][e] = 1;
}

