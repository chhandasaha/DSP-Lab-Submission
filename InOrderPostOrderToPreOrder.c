#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int postIndex = 0;
int search(int in[], int data, int n)
{
	int i;
	for(i = 0; i<n; i++)
	{
		if (in[i] == data)
			return i;
	}
	return i;
}
/**
typedef struct 
{ 
	int top; 
	unsigned capacity; //capacity of the stack
	int* array; 
} Stack; 
Stack *stack;

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
**/
int stack[200],n,i, top=-1;
void push(int value){  
    //int value;      
    if (top == n )   
    printf("\n Overflow: Stack is full.");   
    else   
    {  
    	for(i=0;i<n;i++){
        //printf("Enter the value : ");  
        //scanf("%d",&value);         
        top = top +1;   
        stack[top] = value;   
    	}
    }
}

void pop(){   
    if(top == -1)   
    printf("Underflow: Empty Stack.");  
    else  
    top = top -1;   
}
void fillPreOrder(int in[], int post[], int inStart, int inEnd, /*Stack* s,*/ int s, int n)
{
	if(inStart>inEnd)
		return;
	
	int val = post[postIndex];
	int inIndex = search(in, val, n);
	postIndex = postIndex -1;
	
	fillPreOrder(in, post, inIndex+1, inEnd, s, n);
	fillPreOrder(in, post, inStart, inIndex-1, s, n);
	
	push(val);
}
void printPreMain(int in[], int post[], int n)
{
	int len = n;
	postIndex = len-1;
	//Stack* s;
	int s = stack[200];
	fillPreOrder(in, post, 0, len-1, s, n);
	//while(sizeof(s) > 0)
	while(top > 0)
	{
		printf("%d", top);
			pop();
	}
}

int main() 
{ 
    int in[] = { 4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90 }; 
    int post[] = { 4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25 };
    //int len = strlen(in);
    int len = sizeof(in)/sizeof(in[0]);
    printPreMain(in, post, len);
}
