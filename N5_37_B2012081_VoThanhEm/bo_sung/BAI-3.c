////"Ma tr?n d?nh - d?nh" d�ng d? bi?u di?n c�c don d? th? v� hu?ng.
//
//typedef struct {
//    int A[100][100];
//    int n;
//} Graph;
//Vi?t h�m int deg(Graph* G, int x) 
//d? t�nh b?c c?a d?nh u theo m?u (prototype):

int deg(Graph* G, int x){
	int e,v = 0;
	for(e=1;e<=G->n;e++){
		if(G->A[x][e] > 0)
			v++;
	}
	return v;
}
