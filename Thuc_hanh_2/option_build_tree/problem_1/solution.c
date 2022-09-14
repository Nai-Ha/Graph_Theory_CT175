#include <stdio.h>

#define MAX_NODE 100

typedef struct
{
    int label;
    int parent;
} QueueType;
typedef struct
{
    QueueType data[MAX_NODE];
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

void enqueue(QueueType x, Queue *pQ)
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

QueueType front(Queue q)
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

#define TRUE 1
#define FALSE 0

int parent[MAX_NODE];
int marked[MAX_NODE];

void init_array(int *arr, int initvalue)
{
    for (int i = 0; i < MAX_NODE; i++)
        *(arr + i) = initvalue;
}
void initial()
{
    init_array(parent, -1);
    init_array(marked, FALSE);
}

void BFS(Graph *pG, QueueType u)
{
    if (marked[u.label])
        return;

    Queue q;
    makenull(&q);
    enqueue(u, &q);

    while (!empty(q))
    {
        u = front(q);
        dequeue(&q);
        if (marked[u.label])
            continue;
        marked[u.label] = TRUE;
        parent[u.label] = u.parent;

        for (int i = 1; i <= pG->n; i++)
        {
            if (!pG->A[u.label][i])
                continue;
            QueueType v = {i, u.label};
            enqueue(v, &q);
        }
    }
}

int main()
{
    // Graph G = read_graph_from_file((char *)"./graph.txt");
    Graph G = read_graph_from_keyboard();

    initial();

    for (int i = 1; i <= G.n; i++)
    {
        QueueType u = {i, -1};
        BFS(&G, u);
    }

    for (int i = 1; i <= G.n; i++)
        printf("%d %d\n", i, parent[i]);

    return 0;
}