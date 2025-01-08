#include<stdio.h>
int n,i,j,start;
int front=-1,rear=-1;
int adj[20][20],visited[20],queue[20];

void bfs(int start);
void enqueue(int node);
int dequeue();

int main()
{
    printf("\nEnter the number of nodes: \n");
    scanf("%d",&n);

    //reading the graph for adjancency matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j,n;j++)
        {
            printf("\nEnter the vertex of A[%d][%d] : \n",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nEnter the starting vertex : ");
    scanf("%d", &start);
    if(start<0||start>n-1)
    {
        printf("\n Invalid Entry");
    }
    else
    {
        printf("DFS visited order\n");
        bfs(start);
    }
    return 0;
}
 void bfs(int start)
 {
    enqueue(start);
    visited[start]=1;
    printf("%d \t",start);
    while(front !=-1 && rear!=-1)
    {
        {
        int node = dequeue();
        for (int i = 0; i < n; i++)
        {
            if (adj[i][node] == 1 && visited[i] != 1)
            {
                visited[i] = 1;
                printf("%d\t", i);
                enqueue(i);
            }
        }
        }
    }
 }
 void enqueue(int node)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = node;
}
int dequeue()
{
    int node = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return node;
}

