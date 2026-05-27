#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weights of items:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter profits of items:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    // Initialize table
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // Build DP table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(weight[i - 1] <= j)
            {
                dp[i][j] = max(
                    profit[i - 1] + dp[i - 1][j - weight[i - 1]],
                    dp[i - 1][j]
                );
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("Maximum Profit = %d\n", dp[n][W]);

    return 0;
}
