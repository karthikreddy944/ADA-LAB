#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // for time calculation

void dijkstra(int n, int cost[10][10], int s, int dist[10]);

int main()
{
    int i, j, n, s;
    int cost[10][10], dist[10];

    clock_t start, end;
    double cpu_time;

    printf("\nEnter no. of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    // Start time
    start = clock();

    dijkstra(n, cost, s, dist);

    // End time
    end = clock();

    printf("\nShortest path from source %d:\n", s);
    for(i = 1; i <= n; i++)
    {
        if(i != s)
        {
            printf("%d -> %d = %d\n", s, i, dist[i]);
        }
    }

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %.10f seconds\n", cpu_time);

    return 0;
}

void dijkstra(int n, int cost[10][10], int s, int dist[10])
{
    int i, v, count = 1, min;
    int visited[10];

    for(i = 1; i <= n; i++)
    {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    visited[s] = 1;
    dist[s] = 0;

    while(count <= n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            if(dist[i] < min && visited[i] == 0)
            {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1;
        count++;

        for(i = 1; i <= n; i++)
        {
            if(dist[i] > dist[v] + cost[v][i])
            {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }
}
