//C program to ADD, DELETE, DISPLAY AND SEARCH elements in Singly Linked List and display the list in reverse order
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{ // linked list node
	int data;
	struct Node* next;
}Node;
//node creation func
Node* createNode( int nodeData)
{
	Node* n;
	n = (Node*)malloc(sizeof(Node)); // allocate node
	n->data = nodeData; //put in the data
	n->next = NULL; 
	return n;
}
//insert node at front of the list
void insertBeg(Node** headRef, int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = (*headRef); // next of new node is head
	(*headRef) = newNode; // move the head to point to the new node
}
//insert node after given node of the list
void insertAfter(Node* prevNode, int newData)
{
	if(prevNode == NULL)
	{
		printf("\nGiven previous node can't be null ");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));// allocate node
	newNode->data = newData; //put in the data
	newNode->next = prevNode->next; //make next of nre node as next of prev node
	prevNode->next = newNode; //move the next of prev node as the new node
}
//insert node at the end of the list
void insertEnd(Node** headRef, int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* last = *headRef;
	newNode->data = newData;
	newNode->next = NULL; // next of the last node is NUll
	
	if(*headRef == NULL) // if the linked list is empty then the new node is head
	{
		*headRef = newNode; 
		return;
	}
	while(last->next != NULL) // traverse till the last node
		last = last->next;
	last->next = newNode; //next of last node is new node
	return;	
}
//delete node
void dltNode(Node** headRef, int pos)
{	
	int i;
	if (*headRef == NULL)// lined list is empty
		return;
	Node* temp = *headRef; // store the head
	if(pos == 0) // head need to be deleted
	{
		*headRef = temp->next;
		free(temp);
		return;
	}
	for(i = 0; temp != NULL && i<pos-1; i++) // find prev node of the node to be deleted
		temp = temp->next;
	if(temp == NULL || temp->next == NULL) //given position is not present in the line
		return;
	Node* next = temp->next->next;
	free(temp->next); // free memory
	temp->next = next;
}
//Search an element e is present in the list
void search(Node* head, int e)
{
	Node* current = head; //initializing current
	while(current != NULL)
	{
		if (current->data == e){
			printf("\nThe element is present ");
			return;
		}
		current = current->next;
	}
	printf("\nThe element is not present in the list ");
}
//print the list
void printList(Node* node)
{
	while(node != NULL)
	{
		printf("%d -> ", node->data);
		node = node->next;
	}
}
//print in reverse order
void printReverse(Node* head)
{
	if (head == NULL)
		return;
	printReverse(head->next);//print the list after head node
	printf("%d -> ", head->data);
}
int main()
{
	//int n, nodeData;
	Node *head = NULL; 
	/** for my  testing purpose
	insertEnd(&head, 7);
	insertBeg(&head, 2);
	insertBeg(&head, 1);
	insertAfter(head->next, 6);
	
	printf("\nCreated lined list is ");
	printList(head);
	dltNode(&head,2);
	printf("\nLinked list after deletion at 3 :");
	printList(head);
	//search(head, 1);
	search(head, 6);
	//return 0;
	**/
	
	int choice, ib, ia, ie, dn, se;
	printf("Choose any option from below to implement Linked List :");
    printf("\n1-> Insert node at the beginning \n2-> Insert node at the given position \n3->Insert node at the end of the list"
			 "\n4-> Delete the node at given position \n5-> Search an element \n6-> Display the list \n7-> Display the list in reverse order \n8-> Exit");
    while(true)
	{
		printf("\nEnter the choice: ");
        scanf("%d",&choice);
	
		switch(choice)
		{
			case 1: 
					printf("\nInsert node at the beginning : ");
                	scanf("%d", &ib);
                	insertBeg(&head, ib);
                	break;
			case 2:
					printf("\nInsert node after given previous node : ");
                	scanf("%d", &ia);
                	insertAfter(head->next, ia);
                	break;
			case 3: 
					printf("\nInsert node at the end of the list: ");
	                scanf("%d", &ie);
	                insertEnd(&head, ie);
	                break;      
	        case 4: 
					printf("\nDelete the node at given position : ");
	                scanf("%d", &dn);
	                dltNode(&head, dn);
	                break;
	        case 5: 
					printf("\nSearch if an element is present or not : ");
	                scanf("%d", &se);
	                search(head, se);
	                break;
	        case 6: 
					printf("\nDisplay the list :");
	                printList(head);
	                break;
			case 7: 
					printf("\nDisplay the list in reverse order:");
	                printReverse(head);
	                break;  
			case 8:
					return 0;       
			default:
					printf("choose something else ");
					break;
			
		}
	}
	return 0;
}
