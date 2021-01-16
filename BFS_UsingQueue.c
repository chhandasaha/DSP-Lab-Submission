//BFS Implementation in C:
//Name: Chhanda Saha, Roll: 20MCMB01
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

#define initial 0
#define visited 1  

// Number of nodes in the graph 
int n;
//Adjacency Matrix, if adj[i][j] = 1, they are connected, else not connected    
int adj[MAX][MAX];
// state[i] can be initial or visited
int state[MAX];   
 
int queue[MAX], front = -1,rear = -1;

//check if queue is empty or not
int isEmpty()
{
   if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}

//insert vertex in queue
void enQueue(int vertex)
{
   if(rear == MAX-1)
      printf("Queue Overflow\n");
   else
   {
      if(front == -1)
         front = 0;
      rear = rear+1;
      queue[rear] = vertex ;
   }
}

//delete vertex form queue
int deQueue()
{
   int delItem;
   if(front == -1 || front > rear)
   {
      printf("Queue Underflow\n");
      exit(1);
   }
   
   delItem = queue[front];
   front = front+1;
   return delItem;
}

//create a graph
void createGraph()
{
   int i, maxEdge, src, dest;
   printf("------------Implementation of BFS using Queue ----------");
   printf("\nEnter number of vertices in the graph: ");
   scanf("%d",&n);
   maxEdge = n*(n-1);         
 
   for(i=1; i<=maxEdge; i++)
   {
      printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
      scanf("%d %d",&src,&dest);
 
      if((src == -1) && (dest == -1))
         break;
 
      if(src>n || dest>n || src<0 || dest<0)
      {
        printf("Invalid edge!\n");
        i--;
      }
      else
      {
        adj[src][dest] = 1;
        adj[dest][src] = 1; // if the graph is biderectional push the reverse edges too.
      }
   }
} 

 
void BFS()
{
    int v;
   	for(v=0; v<n; v++)
      state[v] = initial;
   
   printf("Enter Start Vertex for BFS: \n");
   scanf("%d", &v);
   
   int i;
   enQueue(v);
   
   while(!isEmpty())
   {
       
    v = deQueue( );
    //is a vertex is already visited by neighbouring vertex then it should not be printed again
    if(state[v])         
        continue;
           
    printf("%d ",v);
    state[v] = visited;
	  
    //for(i=0; i<n; i++)
    for(i=0; i<=n; i++)
    {
        if(adj[v][i] == 1 && state[i] == initial)
        {
        	enQueue(i);
        }
      }
   }
   printf("\n");
}

//driver code
int main()
{
   createGraph();
   BFS();
   return 0;
}

