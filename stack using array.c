// stack implementation as an array
#include<stdio.h>
#include<stdlib.h>

int stack[200],n,i, top=-1;

// stack push operation
void push(){  
    int value;      
    if (top == n )   
    printf("\n Overflow: Stack is full.");   
    else   
    {  
    	for(i=0;i<n;i++){
        printf("Enter the value : ");  
        scanf("%d",&value);         
        top = top +1;   
        stack[top] = value;   
    	}
    }
} 

//stack pop operation
void pop(){   
    if(top == -1)   
    printf("Underflow: Empty Stack.");  
    else  
    top = top -1;   
}
// stack value display
void display(){
	for (i=top;i>=0;i--)  
    {  
        printf("%d\n",stack[i]);  
    }  
    if(top == -1)   
    {  
        printf("Stack is empty");  
    }
}
int main(){
	printf("Enter number of elements in the stack : ");
	scanf("%d", &n);
	push();
	printf("Display the stack value : \n");
	display();
	printf("Pop the top value :");
	pop();
	printf("Display the stack value after pop operation :\n");
	display();
}

