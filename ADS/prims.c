#include <stdio.h>
#include <limits.h>
int main()
{

    int n;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    int adj[n][n], vist[n], min = INT_MAX, u, v, cost = 0;

    printf("Enter the Cost Adjacency Matrix (Enter 0 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        vist[i] = 0;
        for (int j = 0; j < n; j++)
        {
            printf("Weight[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);

            if (adj[i][j] == 0)
                adj[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] < min)
            {
                min = adj[i][j];
                u = i;
                v = j;
            }
        }
    }

    cost += min;
    vist[u] = 1;
    vist[v] = 1;

    printf("SPANNING TREE: EDGES ARE\n");
    printf("{%d, %d} = %d\n", u, v, min);
    
    int e = 1;
    while (e < n - 1)
    {
        min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (vist[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][j] < min && vist[j] == 0)
                    {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (min == INT_MAX)
        {
            printf("Graph is disconnected. No MST possible.\n");
            return 0;
        }
        cost += min;
        vist[v] = 1;
        printf("{%d, %d} = %d\n", u, v, min);
        e++;
    }
    printf("Total Cost = %d\n", cost);
    return 0;
}
