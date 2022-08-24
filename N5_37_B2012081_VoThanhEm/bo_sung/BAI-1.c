//"Ma tr?n d?nh - cung" 
//dùng d? bi?u di?n các d? th? vô hu?ng, không ch?a khuyên.

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

