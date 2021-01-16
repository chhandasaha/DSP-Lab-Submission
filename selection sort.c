//Selection sort
#include<stdio.h>
#include<stdbool.h>
int main()
{
	int i, j, temp =0; 
	int count, arr[20];
	printf("input : ");
	scanf("%d", &count);
	//printf("Enter %d elements : ", count);
	//printf("\n", count);
	for(i = 0; i<count; i++)
		scanf("%d", &arr[i]);
	
	//sort array in ascending order 	
	for(i=0; i<count; i++)
	{	for(j = i+1; j< count; j++){
		if (arr[i] > arr[j]){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	}
	//display new sorted array
	printf("\noutput =");
	for(i=0;i<count;i++)
	{
		printf(" %d ", arr[i]);
	}
	return 0;
	}	
	
