#include <stdio.h>

#define INF 999

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter cost matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int distance[n], visited[n];

    for(int i = 0; i < n; i++)
    {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    visited[source] = 1;
    distance[source] = 0;

    for(int count = 1; count < n - 1; count++)
    {
        int min = INF, next = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && distance[i] < min)
            {
                min = distance[i];
                next = i;
            }
        }

        visited[next] = 1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] &&
               min + cost[next][i] < distance[i])
            {
                distance[i] =
                    min + cost[next][i];
            }
        }
    }

    printf("Shortest distances:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n",
               source, i, distance[i]);
    }

    return 0;
}
