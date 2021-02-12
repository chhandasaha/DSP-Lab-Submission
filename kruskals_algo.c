//Name: Chhanda Saha, Roll: 20MCMB01
#include<stdio.h>
 
#define MAX 30

// edge structure
typedef struct edge
{
	int u,v,w;
}edge;
 
// array of edges, structure
typedef struct edgelist
{
	edge data[MAX];
	int n;
}edgeList;

// adj matrix 
int G[MAX][MAX],n;
edgeList elist; // graph in edgelist representation
edgeList spanlist; // list of edges making the MST
 
 
int find(int belongs[], int vertexId)
{
	return(belongs[vertexId]);
}

//func for union operation 
void unionOp(int belongs[],int c1,int c2)
{
	int i;
	// set union operation across the belongs array
	for(i = 0; i < n; i++)
		if(belongs[i] == c2)
			belongs[i] = c1;
}

// func to sort the edges
void sortEdges()
{
	int i,j;
	edge temp;
	// re-modeled selection sort
	for(i = 1; i < elist.n; i++)
		for(j = 0; j < elist.n-1; j++)
			if(elist.data[j].w > elist.data[j+1].w)
			{
				temp = elist.data[j];
				elist.data[j] = elist.data[j+1];
				elist.data[j+1] = temp;
			}
}

//function for printing the solution  
void printSolution()
{
	int i, cost = 0;
	printf("\nThe edges of mst tree : ");
	for(i = 0;i < spanlist.n; i++)
	{
		printf("\n edge (%d - %d) = %d\n", spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w  );
		cost = cost + spanlist.data[i].w;
	}
	printf("\nCost of the mst = %d", cost);
}
//func for kruskal's algo 
void kruskal()
{
	int belongs[MAX], i, j, cno1, cno2;
	
	// sort edges wrt weight
	sortEdges();
	
	// init the belongs array
	for(i = 0 ; i < n; i++)
		belongs[i] = i;
	
	// init spanlist
	spanlist.n = 0;
	
	for(i = 0; i <elist.n; i++)
	{
		cno1 = find(belongs, elist.data[i].u);
		cno2 = find(belongs, elist.data[i].v);
		
		// if edge between u and v can be added, 
		if(cno1 != cno2)
		{
			// then adge the edge
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n++; // = spanlist.n+1;
			unionOp(belongs, cno1, cno2); // and perform union on (cno1, cno2)
		}
	}
}
//driver code 
void main()
{
	printf("------------Kruskal's algorithm----------------");
	int i,j,totalCost;
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	
	elist.n = 0;
	
	printf("\nEnter the adjacency matrix:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < i; j++){
			printf("weight of vertex (%d, %d):", i, j);
			scanf("%d", &G[i][j]);
			if (G[i][j] != 0){
			// adding edge to edge list
			elist.data[elist.n].u = i;
			elist.data[elist.n].v = j;
			elist.data[elist.n].w = G[i][j];
			elist.n++;
			}
		}
	}
	kruskal();
	printSolution();
}
