#include <stdio.h>

#define MAX 100

int main() {
    int n, adj[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int start, i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting node (0 to %d): ", n-1);
    scanf("%d", &start);

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for(i = 0; i < n; i++) {
            if(adj[u][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}