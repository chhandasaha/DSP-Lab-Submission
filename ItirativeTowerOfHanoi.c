//Program for Iterative Tower of Hanoi 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <limits.h>

// Stack definition
typedef struct 
{ 
	int top; 
	unsigned capacity; //capacity of the stack
	int* array; 
} Stack; 

Stack *stack;
Stack *src;
Stack *aux;
Stack *dest;


// initializing a stack
Stack* init( unsigned capacity ) 
{ 
	stack = (Stack*) malloc(sizeof(Stack*)); // memory allocation for stack

	//if (!stack) //stack doesn't exist
		//return NULL; 

	stack->top = -1; //initializing top
	stack->capacity = capacity; // capacity of the stack

	stack->array = (int*) calloc(stack->capacity, sizeof(int)); // memory allocation for stack array
	 return stack; 
} 

int isEmpty(Stack *stack) // check if the stack is empty
{ 
	return (stack->top == -1); 
} 
int isFull(Stack *stack) // check if the stack is full
{
	return (stack->top == stack->capacity-1);
}
//function to push disk on the top of the stack array
void push( Stack *stack, int item) 
{ 	
	if (isFull(stack)) // if stack is full can't push any disk
		return;
	stack->array[++stack->top] = item; // increase top by 1
}
//function to pop top disk from the stack,
int pop( Stack *stack) 
{ 
	//if stack not empty, pop top array elem
	if (isEmpty(stack)) 
		return INT_MIN; 
	return stack->array [stack->top--];
}
// function to display movement of the disk
void moveDisk(char source_Rod, char destination_Rod, int disk ){
	printf("\nMove the disk %d from rod %c to rod  % c\n", disk, source_Rod, destination_Rod);
}
//function of Disk movement b/w 2 rods
void moveDiskBetween2Rods(Stack *src, Stack *dest, char s, char d)
{
	int Rod1TopDisk = pop(src);
	int Rod2TopDisk = pop(dest);
	
	//when rod 1 is empty
	if(Rod1TopDisk == INT_MIN)
	{
		push(src, Rod2TopDisk);
		moveDisk(d,s, Rod2TopDisk);
	}
	//when rod 2 is empty
	else if(Rod2TopDisk == INT_MIN)
	{
		push(dest, Rod1TopDisk);
		moveDisk(s,d, Rod1TopDisk);
	}
	//when top disk of Rod1 > top disk of Rod2
	else if (Rod1TopDisk > Rod2TopDisk)
	{
		push(src, Rod1TopDisk);
		push(src, Rod2TopDisk);
		moveDisk(d, s, Rod2TopDisk);
	}
	//when top disk of Rod1 < top disk of Rod2
	else
	{
		push(dest, Rod2TopDisk);
		push(dest, Rod1TopDisk);
		moveDisk(s, d, Rod1TopDisk);
	}
}
//function to implement  TOH puzzle
void TOHIterative(int numOfDisk, Stack *src, Stack *aux, Stack *dest )
{
	int i, total_no_of_moves;
	char s = 'S', d ='D', a ='A';
	
	// if no of disk is even, then interchange destination rod to auxilari rod
	if(numOfDisk %2 == 0)
	{
		char temp = d;
		d = a;
		a = temp;
	}
	total_no_of_moves = pow(2, numOfDisk)-1; //total move required = pow(2,n)-1, n = no of disk
	
	//larger disk will be pushed first
	for (i = numOfDisk; i>=1; i--)
		push(src,i);
	for (i = 1; i<=total_no_of_moves; i++)
	{
		if (i%3 == 1) //top disk movement will be between source and destination rod, in both direction
		moveDiskBetween2Rods(src, dest, s, d);
		else if(i % 3 == 2) //top disk movement will be between source and auxiliary rod, in both direction
		moveDiskBetween2Rods(src, aux, s, a);
		else if(i % 3 == 0) //( top disk movement will be between destination and auxiliary rod, in both direction) 
		moveDiskBetween2Rods(aux, dest, a, d);
	}
}
//driver program
int main()
{
	printf("-----Tower of Hanoi---");
	//input number of disk
	unsigned numOfDisk = 2;
	
	Stack *src, *dest, *aux;
	// Create three stacks of size 'numOfDisk' to hold the disks
	src = init(numOfDisk);
	aux = init(numOfDisk);
	dest = init(numOfDisk);
	
	TOHIterative(numOfDisk, src, aux, dest);
	return 0;
	
}
