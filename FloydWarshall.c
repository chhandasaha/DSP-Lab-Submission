//Floyd Warshall algorithm
//Name: Chhanda Saha, Roll: 20MCMB01
#include<stdio.h>
//number of vertices
#define numOfVer 6
#define INF 99999
FILE *f;

void printMatrix(int matrix[][numOfVer]);

//func for floyd warshall algo
void floydWarshall (int graph[][numOfVer])
{
	int matrix[numOfVer][numOfVer], i, j, k;
	for(i = 0; i < numOfVer; i++)
		for(j = 0; j < numOfVer; j++)
			matrix[i][j] = graph[i][j];
			
	//adding vertices individually 
	for(k = 0; k < numOfVer; k++){
		for(i = 0; i < numOfVer; i++){
			for (j = 0; j < numOfVer; j++){
				if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          			matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
		fprintf(f,"------------------------------");
		fprintf(f,"\nk=%d \n", k);
		//printf("\nk=%d i=%d\n", k, i);
		printMatrix(matrix);
		fprintf(f,"\n------------------------------\n");
	}
	printMatrix(matrix);
	
}
//function to print the matrix
void printMatrix(int matrix[][numOfVer]) {
	int i,j;
	//printf("*******************Floyd Warshall Algorithm*************************");
	//printf ("\nMatrix that shows the shortest distances between every pair of vertices :\n"); 
	for (i = 0; i < numOfVer; i++) {
		for (j = 0; j < numOfVer; j++) {
	    	if (matrix[i][j] == INF)
	    		fprintf( f, "%4s", "INF");
	    		//printf("%4s", "INF");
	    	
	      	else
	      		fprintf( f, "%4d", matrix[i][j]);
	        	//printf("%4d", matrix[i][j]);
	    }
	    fprintf(f,"\n");
  	}
}
//driver code
int main() {
	f = fopen("floyd-warshall-output-file.txt", "w");
	//adj matrix of the given graph
  int graph[numOfVer][numOfVer] = {
  			{0, 5, 6, INF, INF, INF},
             {5, 0, 8, 3, 4, INF},
             {6, 8, 0, INF, 6, INF},
             {INF, 3, INF, 0, 3, 7},
			 { INF, 4, 6, 3, 0, 7},
			 {INF, INF, INF, 7, 7, 0}};
  floydWarshall(graph);
}
