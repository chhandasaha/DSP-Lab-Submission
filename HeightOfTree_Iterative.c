#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//node creation
typedef struct Node{
	int key;
	struct Node* left;
	struct Node* right;
}Node;

Node* root;

//function to create a new linked list node
Node* newNode(int data)
{
	Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->key = data;
	node1->left = NULL;
	node1->right = NULL;
	
	return node1;
}

Node* insertNode(Node* node, int data) 
{ 
    if (node == NULL) 
        return newNode(data); 
  
    if (data < node->key) 
        node->left = insertNode(node->left, data); 
    else if (data > node->key) 
        node->right = insertNode(node->right, data); 
  
    return node; 
}
typedef struct Queue{
	
};
Node* createQueue()
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->front = NULL;
	q->rare = NULL;
	return q;
}

int maxDepth( Node* node)
{
	if( node == NULL)
		return 0;
	else
	{
		
	}
	
}
