//create preorder array from inorder and postorder array,
#include<stdio.h>
int stack[200],i, top=-1;
//push elem in stack top
void push(int value, int n){        
    if (top == n )   //n is capacity of the stack
    printf("\n Overflow: Stack is full.");   
    else   
    {           
        top = top +1;   
        stack[top] = value;  
    }
}
//pop elem from stack top
void pop(){   
    if(top == -1)   
    printf("Underflow: Empty Stack.");  
    else  
    top = top -1;   
}
//serach the last elem of postOrder in the inOrder array
int search(int in[], int data, int n) //here n = number of elems in inorder array
{
	int i;
	for(i = 0; i<n; i++)
	{
		if (in[i] == data)
			return i;
	}
	return i;
}
int postIndex= 0;
void createPreOrder(int in[], int post[], int inStart, int inEnd, int n )
{
	if(inStart>inEnd)
		return;
	
	//root value is the last element in the postorder array		
	int rootVal = post[postIndex];
	//search the index where the root value is present in the inorder array
	int rootIndex = search(in, rootVal, n);
	postIndex = postIndex -1;
	
	//right subtree will be created from rootIndex+1 th elem to end elem of inorder array
	createPreOrder(in, post, rootIndex+1, inEnd, n);
	//left subtree will be created from starting index to rootIndex-1 th elem  of inorder array
	createPreOrder(in, post, inStart, rootIndex-1, n);
	
	//printf("%d ", rootVal);
	push(rootVal, n);
}
int printPreOrder(int in[], int post[], int n)
{
	//length of the array
	int len = n;
	//post index is last index of the post order array
	postIndex = len-1;
	createPreOrder(in, post, 0, len-1, n);
	while( top>= 0)
	{
		printf("%d ", stack[top]);
			pop();
	}
}
int main()
{
	int i;
	int noOfElem ; 
	//printf("Enter number of element in the array ");
    scanf("%d", &noOfElem);
	int in[200];
	int post[200];
	for(i=0; i<noOfElem; i++)
	{
		//printf("Enter elements in the inOrder array ");
		scanf("%d", &in[i]);
	}
	for(i =0; i < noOfElem; i++)
	{
		//printf("Enter elements in the postOrder array")
		scanf("%d", &post[i]);	
	}
	//scanf("%d", post[]);
	//int in[] = {4, 2, 5, 1, 6, 3, 7};
	//int post[] = {4, 5, 2, 6, 7, 3, 1};	
    printPreOrder(in, post, noOfElem);
    
}
