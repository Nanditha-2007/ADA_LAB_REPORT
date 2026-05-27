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

    int visited[n];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    int edges = 0;
    int mincost = 0;

    while(edges < n - 1)
    {
        int min = INF;
        int a = -1, b = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", a, b, min);

        mincost += min;
        visited[b] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}
