////"Ma tr?n d?nh - d?nh" dùng d? bi?u di?n các don d? th? vô hu?ng.
//
//typedef struct {
//    int A[100][100];
//    int n;
//} Graph;
//Vi?t hàm int deg(Graph* G, int x) 
//d? tính b?c c?a d?nh u theo m?u (prototype):

int deg(Graph* G, int x){
	int e,v = 0;
	for(e=1;e<=G->n;e++){
		if(G->A[x][e] > 0)
			v++;
	}
	return v;
}
