#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define V 5
#define INF 9999999

int main() {
    int G[V][V];
    int selected[V];
    int no_edge = 0;
    clock_t start, end;
    double cpu_time;

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    start = clock();

    memset(selected, false, sizeof(selected));


    selected[0] = true;

    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j] != 0) {
                        if (G[i][j] < min) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, G[x][y]);

        selected[y] = true;
        no_edge++;
    }
    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %.10f seconds\n", cpu_time);

    return 0;
}
