#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPrime(int value)
{
	int i;
	if(value == 2 || value == 3){
		return true;}
	if(value == 1){
		return false;}
	for(i = 2; i<=value/2; i++)
	{
		if (value % i == 0)
			return false;
	}
	return true;
}


int countDigit(int N)
{
	int count = 0;
	while(N)
	{
		count = count+1;
		N = N/10;
	}
	return count;
}
int *cyclic(int N)
{
	int *arr;
	int num = N, c=0;
	int n = countDigit(N);
	
	arr = (int*)malloc(n*sizeof(int));
	while(true){
		
		//printf("\n%d", num);
		int rem = num %10;
		int div = num/10;
		num = (pow(10, n-1))*rem +div;
		
		arr[c++] = num;
		if(num == N)
			break;
	}
	return arr;
}
int main()
{
	int N, *arr,n, i;
	printf("Enter a number : ");
	scanf("%d", &N);
	if(N <=0){
		printf("-1");
		return -1;
	}
	arr = cyclic(N);
	n = countDigit(N);
	for(i=0; i<n; i++){
		if(isPrime(arr[i]) == false){
            printf("0");
            return 0;
        }
	}
    printf("1");
	return 0;
}
