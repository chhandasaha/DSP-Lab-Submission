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

int maxDepth( Node* node)
{
	if( node == NULL)
		return 0;
	else
	{
		int leftDepth = maxDepth(node->left);
		int rightDepth = maxDepth(node->right);
		
		if(leftDepth > rightDepth)
			return(leftDepth+1);
		else return (rightDepth+1);
	}
}

int main()
{
	int arr[MAX], N, i;
	
	scanf("%d", &N);
	scanf("%d", (arr)); 
	if (N <= 1){
		printf("%d", N);
		return 0;
	}
	root = insertNode(root, *(arr));
	for(i = 0; i<N-1; i++){
		scanf("%d", (arr+i));
		insertNode(root, *(arr+i));
	}
	printf("%d", maxDepth(root));
    return 0;
}
