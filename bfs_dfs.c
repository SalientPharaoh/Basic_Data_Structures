#include <stdio.h>
#include <stdlib.h>
#define ms 100
typedef struct graph *graphp;
typedef struct graph
{
    int data;
    graphp next;
};
int visited[ms];
graphp list[ms];
void create(int u, int v)
{
    graphp temp;
    temp = (graphp)malloc(sizeof(*temp));
    temp->data = v;
    temp->next = list[u];
    list[u] = temp;
    graphp temp1;
    temp1 = (graphp)malloc(sizeof(*temp1));
    temp1->data = u;
    temp1->next = list[v];
    list[v] = temp1;
}
void DFS(int v)
{
    printf("%d\n", v);
    visited[v] = 1;
    graphp temp = list[v];
    while (temp)
    {
        int u = temp->data;
        if (!visited[u])
        {
            DFS(u);
        }
        temp = temp->next;
    }
}
void BFS(int v)
{
    int q[ms], front = 0, rear = 0;
    printf("%d\n", v);
    visited[v] = 1;
    q[rear++] = v;
    while (front != rear)
    {
        int currentv = q[front++];
        graphp temp = list[currentv];
        while (temp)
        {
            int u = temp->data;
            if (!visited[u])
            {
                printf("%d\n", u);
                visited[u] = 1;
                q[rear++] = u;
            }
            temp = temp->next;
        }
    }
}
int main()
{
    int n, e, u, v, start, choice;

    printf("1: Construct graph\n2: DFS\n3: BFS\n4: Exit\n");
    while (1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of vertices:\n");
            scanf("%d", &n);
            printf("Enter the number of edges:\n");
            scanf("%d", &e);
            printf("Enter the edges:\n");
            for (int i = 0; i < e; i++)
            {
                scanf("%d%d", &u, &v);
                create(u, v);
            }
            break;
        case 2:
            printf("Enter starting vertex:\n");
            scanf("%d", &start);
            printf("The DFS is:\n");
            DFS(start);
            for (int i = 0; i < ms; i++)
            {
                visited[i] = 0;
            }
            break;
        case 3:
            printf("Enter starting vertex:\n");
            scanf("%d", &start);
            printf("The BFS is:\n");
            BFS(start);
            for (int i = 0; i < ms; i++)
            {
                visited[i] = 0;
            }
            break;
        case 4:
            exit(0);
        }
    }
    return -1;
}
