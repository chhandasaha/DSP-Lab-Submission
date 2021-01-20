//c program for binary search tree traversal
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//binary tree node 
typedef struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
}Node;

Node* root;

//memory allocation for new node
Node* newNode(int data)
{
	Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->key = data;
	node1->left = NULL;
	node1->right = NULL;
	
	return node1;
}

//insert a node in the tree
Node* insertNode(Node* node, int data)
{
	//if root is null then newNode will be the root 
	if (node == NULL)
		return newNode(data);
		
	//if data is less than the node's key, insert it in left sub tree, else in right subtree	
	if(data < node->key)
		node->left = insertNode(node->left, data);
	else if(data> node->key)
		node->right = insertNode(node->right, data);
		
	return node;
}

//print the nodes in pre order manner
void printPreOrder(Node* node)
{
	if (node == NULL)
		return;
	
	printf("%d ", node->key);
	printPreOrder(node->left);
	printPreOrder(node->right);
}

//print the nodes in in order manner
void printInOrder(Node* node)
{
	if (node == NULL)
		return;
	
	printInOrder(node->left);
	printf("%d ", node->key);
	printInOrder(node->right);
}

//print the nodes in post order manner
void printPostOrder(Node* node)
{
	if (node == NULL)
		return;
	
	printPostOrder(node->left);
	printPostOrder(node->right);
	printf("%d ", node->key);
}

//driver code
int main()
{
	int i, arr[MAX], N;
	//enter number of element in the tree
	scanf("%d", &N);
	// give the array input
	scanf("%d", arr);
	//if number of element is less than or equal to 1, print that
	if (N <= 1)
	{
		printf("%d", N);
		return 0;
	}
	// insert node at the o-th position of the array, and return the root
	root = insertNode(root, *(arr));
	for(i = 0; i<N-1; i++)
	{
		//scan the ith element and insert it in the tree.
		scanf("%d", (arr+i));
		insertNode(root, *(arr+i));
	}
	//print in preorder
	printPreOrder(root);
	printf("\n");
	//print in inorder
	printInOrder(root);
	printf("\n");
	//print in postOrder
	printPostOrder(root);
	
	return 0;
}
