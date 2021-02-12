//implement DFS using stack
//Name: Chhanda Saha, Roll: 20MCMB01
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
 
#define initial 1
#define visited 2
 
// Number of nodes in the graph 
int n;   
//Adjacency Matrix, if adj[i][j] = 1, they are connected, else not connected
int adj[MAX][MAX];
// initial state or visited state 
int state[MAX];
 
int stack[MAX];
int top = -1;
//check if stack is empty
int isEmpty( )
{
  if(top == -1)
    return 1;
  else
    return 0;
}
 
// push func
void push(int vertex)
{
        if(top == (MAX-1))
        {
            printf("\nStack Overflow\n");
            return;
        }
        top=top+1;
        stack[top] = vertex;
}

//pop function 
int pop()
{
    int vertex;
    if(isEmpty())
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    else
    {
        vertex = stack[top];
        top=top-1;
        return vertex;
    }
}
//func to create graph
void createGraph()
{
    int i, maxEdges, src, dest;
    printf("------------Implementation of DFS using stack ----------");
 	printf("\nEnter number of vertices in the graph : ");
    scanf("%d",&n);
    maxEdges=n*(n-1);
 
    for (i=1; i<=maxEdges; i++)
    {
        printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
        scanf("%d %d",&src,&dest);
 
        if( (src == -1) && (dest == -1) )
            break;
 
        
        if( src > n || dest > n || src<0 || dest<0)
        {
            printf("\nInvalid edge!\n");
            i--;
        }
        else
        {
            adj[src][dest] = 1;
        }
    }
}

//DFS func
void DFS(int v)
{
    int i;
    push(v);
    while(!isEmpty())
    {
        v = pop();
        if(state[v]==initial)
        {
            printf("%d ",v);
            state[v]=visited;
        }
        for(i=n; i>=0; i--)
        {
            if(adj[v][i]==1 && state[i]==initial)
            push(i);
        }
    }
}

//depth first traversal 
void DFTraversal()
{
    int vertex;
    for(vertex = 0; vertex <= n; vertex++)
        state[vertex]=initial;
 
    printf("\nEnter starting vertex for Depth First Search : ");
    scanf("%d",&vertex);
    DFS(vertex);
    printf("\n");
}

//driver code
main()
{
    createGraph();
    DFTraversal();
}
 

 
