#include<stdio.h>
#include<stdlib.h>
//linked list node
typedef struct Node{
	int data;
	struct Node* next;
}Node;

//create circular linked list
Node* createNode( int nodeData)
{
	Node* temp ;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = nodeData;
	temp->next = temp; //circular lined list
}
//func to find safe position
void safePosition(int n, int k)
{
	int i;
	// circular linked list of size n
	Node* head = createNode(1);
	Node* prev = head; 
	for(i = 2; i<= n; i++)
	{
		prev->next = createNode(i);
		prev = prev->next;
	}
	prev->next = head; // connect last node to head
	
	Node* ptr1 = head, *ptr2 = head; // only one node is available
	while(ptr1->next != ptr1)
	{
		//find k-th node
		int count = 1;
		while(count != k)
		{
			ptr2 = ptr1;
			ptr1 = ptr1->next;
			count = count + 1;
		}
		//remove k-th node
		ptr2->next = ptr1->next;
		free(ptr1);
		ptr1 = ptr2->next;
	}
	printf("\nThe safe position is : %d", ptr1->data);
}
int main()
{
	int n, k;
	printf("Enter number of people :");
	scanf("%d", &n);
	printf("Steps to be skipped : ");
	scanf("%d", &k);
	safePosition(n,k);
	return 0;
}
