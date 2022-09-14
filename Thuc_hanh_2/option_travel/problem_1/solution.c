#include <stdio.h>

#define MAX_NODE 100

typedef struct
{
    int data[MAX_NODE];
    int rear;
} Queue;

void makenull(Queue *pQ)
{
    pQ->rear = -1;
}

int empty(Queue q)
{
    return q.rear == -1;
}

void enqueue(int x, Queue *pQ)
{
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

void dequeue(Queue *pQ)
{
    for (int i = 0; i < pQ->rear; i++)
        pQ->data[i] = pQ->data[i + 1];
    pQ->rear--;
}

int front(Queue q)
{
    return q.data[0];
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

int marked[MAX_NODE];

void initial()
{
    for (int i = 0; i < MAX_NODE; i++)
        marked[i] = 0;
}

void BFS(Graph *pG, int u)
{
    Queue q;
    makenull(&q);
    enqueue(u, &q);

    while (!empty(q))
    {
        u = front(q);
        dequeue(&q);
        if (marked[u])
            continue;
        marked[u] = 1;
        printf("%d\n", u);

        for (int i = 1; i <= pG->n; i++)
        {
            if (!pG->A[u][i])
                continue;
            enqueue(i, &q);
        }
    }
}

int main()
{
    Graph G = read_graph_from_file((char *)"./graph.txt");
    // Graph G = read_graph_from_keyboard();
    initial();
    for (int i = 1; i <= G.n; i++)
        if (!marked[i])
            BFS(&G, i);

    return 0;
}
