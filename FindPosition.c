//C program to find first and last occurrence of an element in an sorted array
#include<stdio.h>
#include<stdbool.h>
int main()
{
	int i, j, temp =0; 
	int value=10;
	int first = -1, last = -1;
	int arr[ ]= {25, 10, 6, 30, 5, 10, 95, 48, 10, 13};
	int length = sizeof(arr)/sizeof(arr[0]);
	
	//display original unsorted array
	printf("Element of original array : ");
	for (i = 0; i< length; i++){
		printf(" %d ", arr[i]);
	}
	//sort array in ascending order 	
	for(i=0; i<length; i++)
	{	for(j = i+1; j< length; j++){
		if (arr[i] > arr[j]){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	}
	//display new sorted array
	printf("\nElements of the sorted array :");
	for(i=0;i<length;i++)
	{
		printf(" %d ", arr[i]);
	}
	//finding the position of the element
	for(i=0;i<length;i++){
		if (value != arr[i])
			continue;
		if(first == -1)
			first = i;
		last = i;
	}
	if(first != -1){
		printf("\nStarting Occurrence :  %d", first);
		printf("\nEnding Occurrence : %d", last);
	}
	else{
		printf("\n Not Found.. ");
	}
	}	
	
