#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define MAX 100

// Stack definition
typedef struct 
{ 
	int top; 
	unsigned capacity; //capacity can't be -ve
	int* array; 
} Stack; 

Stack *stack;

// initializing a stack
Stack* init( unsigned capacity ) 
{ 
	stack = (Stack*) malloc(sizeof(Stack*)); // memory allocation for stack

	if (!stack) //stack doesn't exist
		return NULL; 

	stack->top = -1; //initializing top
	stack->capacity = capacity; // capacity of the stack

	stack->array = (int*) calloc(stack->capacity, sizeof(int)); // memory allocation for stack array

	// return stack; 
} 
int isEmpty() // check if the stack is empty
{ 
	return stack->top == -1 ; 
} 
char peek() // check the top element of the stack
{ 
	return stack->array[stack->top]; 
} 
char pop() 
{ 
	//if stack not empty, pop top array elem
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 
void push( char operators) //push operator on the top of the stack array
{ 
	stack->array[++stack->top] = operators; 
} 


//  function to check if the given character is operand 
int isOperand(char ch) 
{ 
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch<= '9');
} 

//  function to return precedence of a given operator 
// Higher returned value means higher precedence (* & / & % has the higher precedence than + & -)
int prec(char ch) 
{ 
	switch (ch) 
	{ 
	case '+': 
	case '-': 
		return 1; 

	case '*': 
	case '/':
	case '%':
		return 2; 
	} 
	return -1; 
} 

//  function to converts given infix Expression to postfix Expression. 
int infixToPostfix(char* infixExp) 
{ 
	int i, k; 
	char *postfixExp; //new postfix variabe to store expression after postfix conversion operation
	postfixExp = (char*)calloc(strlen(infixExp), sizeof(char)); // memory allocation for postfixExp

	// Create a stack of capacity equal to infixExp size 
	init(strlen(infixExp)); 
	if(!stack) // See if stack was created successfully 
		return -1 ; 

	for (i = 0, k = -1; infixExp[i]; ++i) 
	{ 
		
		// If the scanned character is an operand, add it to output. 
		if (isOperand(infixExp[i])){ 
			postfixExp[++k] = infixExp[i];
			if (!isOperand(infixExp[i+1]) ) //if not operand, add it to output after a space
				postfixExp[++k] = ' ';
		}
		// If the scanned character is '(' push it to the stack. 
		else if (infixExp[i] == '(') 
			push(infixExp[i]); 
		
		// If the scanned character is ')' pop and output from the stack untill '(' is there 
		else if (infixExp[i] == ')') 
		{ 
			while (!isEmpty(stack) && peek(stack) != '(') 
				postfixExp[++k] = pop(stack); 
			if (!isEmpty(stack) && peek(stack) != '(') 
				return -1; // invalid prefixExpression			 
			else
				pop(stack); 
		} 
		else // an operator is encountered 
		{ 
			while (!isEmpty(stack) && prec(infixExp[i]) <= prec(peek(stack))) //if higher precedence op is on top, pop it
				postfixExp[++k] = pop(stack); 
			push(infixExp[i]); // push the op in the stack
		} 
	} 
	// pop all the operators from the stack 
	while (!isEmpty(stack)) 
		postfixExp[++k] = pop(stack ); 
	postfixExp[++k] = '\0'; //ending postfix expressing with NULL character
	
	//printf( "\nInfix Expression :%s\nPostfix Expression :%s", infixExp, postfixExp ); 
	printf("%s", postfixExp);
} 

// Driver code
int main() 
{ 	 
	//char infixExp[] = "a+b*c+(d*e+f)*10";
	char infixExp[MAX];
	//gets(infixExp);
	scanf("%s", infixExp);
	infixToPostfix(infixExp); 
	//printf("\nexpected exp is : a b c * + d e * f + 10 * +");
	return 0; 
} 
