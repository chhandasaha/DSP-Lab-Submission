#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define MAX 100

// Stack definition
typedef struct Node
{ 
	char data; 
	struct Node* next;
} Node; 

typedef struct linkedList{
	struct Node* head;
	struct Node* top;
}stack;

//make a new node
Node* newNode(int data){
	Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->data = data;
	node1->next = NULL;
	
	return node1;
}

//make a new stack
stack* newStack() {
  stack *s = malloc(sizeof(stack));
  s->head = NULL;
  s->top = NULL;

  return s;
}

int isEmpty(stack *s) {
  if(s->top == NULL)
    return 1;// stack is empty
  return 0;// stack is not empty
} 
char peek(stack* s) // check the top element of the stack
{ 
	return s->top->data; 
} 
char pop(stack *s) {
  if(isEmpty(s)) {
   return;
  }
  else {
    int x = s->top->data;
    if(s->top == s->head) {// only one node in the stack
      free(s->top);
      s->top = NULL;
      s->head = NULL;
    }
    else {
      Node *temp = s->head;
      while(temp->next != s->top) // iterating to the last element
        temp = temp->next;
      temp->next = NULL;
      free(s->top);
      s->top = temp;
    }
    return x;
  }
} 
//push an element in the stack
void push(stack *s, char c)
{
	Node *n = newNode(c);
  	if(isEmpty(s)) { //empty
    	s->head = n;
    	s->top = n;
  }
  	else {
    	s->top->next = n;
    	s->top = n;
  }
} 

//  function to check if the given character is operand 
int isOperand(char ch) 
{ 
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == ' ') || (ch >= '0' && ch<= '9');
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
	stack *s = newStack();
	char *postfixExp; //new postfix variabe to store expression after postfix conversion operation
	postfixExp = ( char*)calloc(strlen(infixExp), sizeof(char)); // memory allocation for postfixExp
 
	if(!s) // See if stack was created successfully 
		return -1; 

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
			push(s, infixExp[i]);
		
		// If the scanned character is ')' pop and output from the stack untill '(' is there 
		else if (infixExp[i] == ')') 
		{ 
			while (!isEmpty(s) && peek(s) != '(') 
				postfixExp[++k] = pop(s); 
			if (!isEmpty(s) && peek(s) != '(') 
				return -1; // invalid prefixExpression			 
			else
				pop(s); 
		} 
		else // an operator is encountered 
		{ 
			while (!isEmpty(s) && prec(infixExp[i]) <= prec(peek(s))) //if higher precedence op is on top, pop it
				postfixExp[++k] = pop(s); 
			push(s,infixExp[i]); // push the op in the stack
		} 
	} 
	// pop all the operators from the stack 
	while (!isEmpty(s)) 
		postfixExp[++k] = pop(s ); 
	postfixExp[++k] = '\0'; //ending postfix expressing with NULL character
	 
	printf("%s", postfixExp);
} 

// Driver code
int main() 
{ 	 
	//char infixExp[] = "a+b*c+(d*e+f)*10";
	char infixExp[MAX];
	scanf("%[^\n]c", infixExp);
	infixToPostfix(infixExp); 
	return 0; 
} 
