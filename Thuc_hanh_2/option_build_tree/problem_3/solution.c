#include <stdio.h>

#define MAX_NODE 100

typedef int ELEMENT_TYPE;

typedef struct
{
    ELEMENT_TYPE data[MAX_NODE];
    int top;
} Stack;

void makenull(Stack *pS)
{
    pS->top = -1;
}

int empty(Stack s)
{
    return s.top == -1;
}

void push(ELEMENT_TYPE x, Stack *pS)
{
    pS->top++;
    pS->data[pS->top] = x;
}

ELEMENT_TYPE pop(Stack *pS)
{
    pS->top--;
    return pS->data[pS->top + 1];
}

typedef struct
{
    int n, m;
    int A[MAX_NODE][MAX_NODE];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pG->A[i][j] = 0;
}

void add_edge(Graph *pG, int u, int v)
{
    pG->A[u][v]++;
    pG->A[v][u]++;
    pG->m++;
}

Graph read_graph_from_keyboard()
{
    int n, m;
    scanf("%d%d", &n, &m);

    Graph G;
    init_graph(&G, n);

    for (; m != 0; m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    return G;
}

Graph read_graph_from_file(char *filepath)
{
    FILE *f = freopen(filepath, "r", stdin);
    Graph G = read_graph_from_keyboard();
    fclose(f);
    return G;
}

#define TRUE 1
#define FALSE 0

int marked[MAX_NODE];
int parent[MAX_NODE];

void initarray(int *arr, int initialvalue)
{
    for (int i = 0; i < MAX_NODE; i++)
        *(arr + i) = initialvalue;
}
void initial()
{
    initarray(marked, FALSE);
    initarray(parent, 0);
}

void DFS(Graph *pG, int u, int p)
{
    if (marked[u])
        return;

    marked[u] = TRUE;
    parent[u] = p;

    for (int i = 1; i <= pG->n; i++)
        if (pG->A[u][i])
            DFS(pG, i, u);
}

int main()
{
    // Graph G = read_graph_from_file((char *)"./graph.txt");
    Graph G = read_graph_from_keyboard();

    initial();
    for (int i = 1; i <= G.n; i++)
        DFS(&G, i, 0);

    for (int i = 1; i <= G.n; i++)
        printf("%d %d\n", i, parent[i]);

    return 0;
}