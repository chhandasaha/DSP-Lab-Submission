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
//function to allocate a new node with the given data and NULL to left and right pointer
Node* newNode(int data)
{
	Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->key = data;
	node1->left = NULL;
	node1->right = NULL;
	
	return node1;
}
//insertion of a node in the tree
Node* insertNode(Node* node, int data) 
{
	//if root is null then newNode will be the root  
    if (node == NULL) 
        return newNode(data); 
  
  	//if data is less than the node's key, insert it in left sub tree, else in right subtree
    if (data < node->key) 
        node->left = insertNode(node->left, data); 
    else if (data > node->key) 
        node->right = insertNode(node->right, data); 
  
    return node; 
}
//function to find the maximum depth (num of node in the longes path from root to deepest leaf node)of the tree
int maxDepth( Node* node)
{
	if( node == NULL)
		return 0;
	else
	{
		// compute the depth of each sub tree
		int leftDepth = maxDepth(node->left);
		int rightDepth = maxDepth(node->right);
		
		//larger depth+1 will be the height
		if(leftDepth > rightDepth)
			return(leftDepth+1);
		else return (rightDepth+1);
	}
}

int main()
{
	int arr[MAX], N, i;
	//enter number of element in the tree
	scanf("%d", &N);
	// give the array input
	scanf("%d", (arr)); 
	//if number of element is less than or equal to 1, print that
	if (N <= 1){
		printf("%d", N);
		return 0;
	}
	// insert node at the o-th position of the array, and return the root
	root = insertNode(root, *(arr));
	for(i = 0; i<N-1; i++){
		//scan the ith element and insert it in the tree.
		scanf("%d", (arr+i));
		insertNode(root, *(arr+i));
	}
	//print the height of the tree
	printf("%d", maxDepth(root));
    return 0;
}
