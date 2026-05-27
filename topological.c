#include <stdio.h>

#define MAX 100

int main()
{
    int n, e;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = -1;
    int topo[MAX];
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        indegree[v]++;
    }

    // Insert all vertices with indegree 0 into queue
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }

    // Topological Sorting
    while (front <= rear)
    {
        int u = queue[front++];
        topo[count++] = u;

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1)
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    queue[++rear] = v;
                }
            }
        }
    }

    // Check for cycle
    if (count != n)
    {
        printf("Graph contains a cycle.\n");
        printf("Topological sorting not possible.\n");
    }
    else
    {
        printf("Topological Order:\n");

        for (int i = 0; i < count; i++)
        {
            printf("%d ", topo[i]);
        }

        printf("\n");
    }

    return 0;
}
