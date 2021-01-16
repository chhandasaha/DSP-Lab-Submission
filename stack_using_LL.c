//implement stack using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node*next;
}Node;

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
//traverse the stack
void traversal(stack *s) {
  Node *temp = s->head; //temporary pointer to point to the head

  while(temp != NULL) { 
  	//show the stack data 
    printf("%d\t", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

//check if stack is empty or not
int isEmpty(stack *s) {
  if(s->top == NULL)
    return 1;// stack is empty
  return 0;// stack is not empty
}
//push an element in the stack
void push(stack *s, Node *n) {
  if(isEmpty(s)) { //empty
    s->head = n;
    s->top = n;
  }
  else {
    s->top->next = n;
    s->top = n;
  }
}
//function to pop an element
int pop(stack *s) {
  if(isEmpty(s)) {
    printf("Stack Underflow, stack has nothing to pop \n");
   return -1;
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

//main program
int main() {
  stack *s = newStack();

  int a, b, c;
  Node *na, *nb, *nc;
  printf("Enter 1st node value: ");
  scanf("%d", &a);
  na = newNode(a);
  printf("Enter 2nd node value: ");
  scanf("%d", &b);
  nb = newNode(b);
  printf("Enter 3rd node value: ");
  scanf("%d", &c);
  nc = newNode(c);

//   pop(s);
  push(s, na);
  push(s, nb);
  push(s, nc);

  printf("show the stack values : ");
  traversal(s);
  pop(s);
  printf("After popping the top value : ");
  traversal(s);


  return 0;
}
