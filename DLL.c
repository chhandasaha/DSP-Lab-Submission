#include<stdio.h>

typedef struct Node
{
	int key;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head = NULL;
Node* current = NULL;
Node* head2 = NULL;
/*
Node* newNode(int newData)
{
	Node* N;
	N = (Node*)malloc(sizeof(Node));
	N->key = newData;
	N->next = NULL;
	N->prev = NULL;
	return N;
}*/
/*
typedef struct dll
{
	Node *head, *tail;
}dll;

dll* L1 = NULL;
dll* L2 =NULL;
void init()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	dll* L = (dll*)malloc(sizeof(dll));
	L->head = newNode;
	L->tail = newNode;
	
	L->head->next = L->tail;
	L->tail->prev = L->head;
}

void insert(int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	L1->head->key = newData;
	L1->head->prev = NULL;
	L1->head->next = L1->tail;
	
	if(L1->tail != NULL)
		L1->tail->prev = newNode;
	L1->tail = newNode;
}

void printList(dll* L)
{
	dll* list;
	printf("\n Traversal in forward direction :\n");
	while( L != NULL)
	{
		printf("%d->", L->head->key);
		list = L;
		L = L->head->next;
	}
	
}
*/
//function to push node at the begining
void pushAtBeg(Node** headRef, int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = newData;
	newNode->prev = NULL;
	newNode->next = (*headRef);
	
	if((*headRef) != NULL)
		(*headRef)->prev = newNode;
		
	(*headRef) = newNode;		
}

//function to push after a given node
void pushAfterNode(Node* prevNode, int newData)
{
	if(prevNode == NULL)
		printf("previous node can't be null");
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = newData;
	newNode->prev = prevNode;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	
}
//function to push a node at the end of the list
void pushAtEnd(Node** headRef, int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* last = *headRef;
	newNode->key = newData;
	newNode->next = NULL;
	
	if(*headRef == NULL)
	{
		newNode->prev = NULL;
		*headRef = newNode;
		return;
	}
	while(last->next != NULL)
		last = last->next;
		
	last->next = newNode;
	newNode->prev = last;
	
	return;
}

void printList(Node* node)
{
	Node* last;
	printf("\n Traversal in forward direction :\n");
	while( node != NULL)
	{
		printf("%d->", node->key);
		last = node;
		node = node->next;
	}
}

//function to search a node
void search(int data)
{
	int pos =0;
	if(head == NULL)
		return;
	
	current = head;	
	while(current != NULL)
	{
		pos = pos +1;
		if(current->key == data)
		{
			printf("%d at position %d", data, pos);
			return;
		}
		if (current->next != NULL)
			current = current->next;
		else
			break;		
	}
	printf("%d doesn't exist", data);
} 
 void upDate(Node* n, int updatedData)
 {
	n->key = updatedData;
 	n->next =NULL;
 	
 }

//driver code
int main()
{

	pushAtBeg(&head, 3);
	pushAtBeg(&head, 5);
	pushAfterNode(head->next, 6);
	pushAtEnd(&head, 1);
	search(5);
	printList(head);
	
	
	pushAtBeg(&head2, 20);
	pushAtBeg(&head2, 10);
	pushAfterNode(head2->next, 30);
	pushAtEnd(&head2, 40);
	printList(head2);

	return 0;
	
}
