#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void initializeGraph(int vertices)
{
    int i, j;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int startVertex, int endVertex)
{
    adjMatrix[startVertex][endVertex] = 1;
    adjMatrix[endVertex][startVertex] = 1;
}

void displayVertex(int vertex)
{
    printf("%d ", vertex);
}

void dfs(int startVertex, int vertices)
{
    int i;

    displayVertex(startVertex);
    visited[startVertex] = 1;

    for (i = 0; i < vertices; i++)
    {
        if (adjMatrix[startVertex][i] == 1 && visited[i] == 0)
        {
            dfs(i, vertices);
        }
    }
}

void enqueue(int vertex)
{
    if (rear == MAX_VERTICES - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue()
{
    int deletedItem;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        deletedItem = queue[front];
        front++;
        return deletedItem;
    }
}

int isQueueEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void bfs(int startVertex, int vertices)
{
    int i, currentVertex;

    displayVertex(startVertex);
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isQueueEmpty())
    {
        currentVertex = dequeue();

        for (i = 0; i < vertices; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && visited[i] == 0)
            {
                displayVertex(i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int vertices, edges, i, s;
    int startVertex, endVertex;
    FILE *fp = fopen("a.txt", "r");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++)
    {
        fscanf(fp, "%d %d", &startVertex, &endVertex);
        addEdge(startVertex, endVertex);
    }
    printf("Enter start:");
    scanf("%d", &s);
    printf("DFS Traversal: ");
    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    dfs(s, vertices);

    printf("\n");
    printf("Enter start:");
    scanf("%d", &s);
    printf("BFS Traversal: ");
    for (i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    bfs(s, vertices);

    printf("\n");
}
