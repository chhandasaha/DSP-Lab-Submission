//count connected component in an undirected graph
//Name: Chhanda Saha, Roll: 20MCMB01 

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct node
{
	int data;
	struct node* link; 
}Node;

Node* adjList[MAX];
//func to add egde
void addEdge(int src,int dest)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = dest;
	newNode->link = NULL;
	
	if(NULL == adjList[src] )
		adjList[src] = newNode;
	else 
	{
		Node *temp = adjList[src];
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = newNode;
	}
}
//func to print the graph
void printGraph(int V)
{ 
	int i;
	for(i = 1; i<= V; i++)
	{
		Node *temp = adjList[i];
		printf(" adjList[%d]-> ",i);
		while(temp != NULL)
		{
			printf(" %d-> ", temp->data);
			temp = temp->link;
		}
		printf(" NULL \n");
	}
}
//function for dfs
void DFS(int vertex, int visited[])
{
	//mark the current node as visited
	visited[vertex] = 1;
	Node *temp = adjList[vertex];
	//check all vertices adjacent to the current vertex
	while(temp != NULL)
	{
		if(visited[temp->data] == 0)
			DFS(temp->data, visited);
		temp=temp->link;
    }
}

//function to print connected components in the graph 
void connectedComponents(int V)
{ 
	int i, visited[V], count = 0;
	for(i = 1; i <= V; i++)
		visited[i] = 0;
	
	for(i = 1; i <= V; i++)
	{
		if(visited[i] == 0)
		{
			DFS(i, visited);
			count = count + 1;
		}
	}
    printf("\n Number of connected components : %d",count);
}

//driver code
int main()
{
	int i,V,E;
	FILE *fp;
	fp = fopen("input.txt", "r");
    if( NULL == fp)
    {
	    printf("\nError: Input file not found ");
   	    exit(1);
    }
    fscanf(fp," %d%d", &V, &E);
	
	for( i = 0; i < V; i++)
	    adjList[i] = NULL;
	
	for(i = 0; i < E; i++)
	{
		int src,dest;
		fscanf(fp, " %d%d", &src, &dest);
		addEdge(src, dest);
		addEdge(dest, src); // as undirected graph, edge will be there from src to dest and dest to src
	}
	printf(" Adjacency list representation of the given undirected graph : \n");
	printGraph(V);
	connectedComponents(V);
	return 0;
}
