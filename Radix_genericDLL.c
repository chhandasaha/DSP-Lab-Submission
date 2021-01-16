#include<stdio.h>
#include<stdlib.h>

//structure for doubly linked list
typedef struct Node
{
	int key;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head1 = NULL;
Node* head2 = NULL;
Node* tail1 =NULL;
Node* tail2 =NULL;

int maxData = 0;
int size;

// function to allocate memory for int and return void pointer.
void *allocateInt(int num)
{
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = num;
    return ((void*)ptr);
}

//function to swap head and tail of the list
void swapList()
{
	Node* temp;
	//swap heaad
	temp = head1;
	head1 = head2;
	head2 = temp;
	
	//swap tail
	temp = tail1;
	tail1 = tail2;
	tail2 = temp;
}

//insert node in the list
void insert(int data)
{
	//list 1
	Node* newNode1 = (Node*)malloc(sizeof(Node));
	newNode1->key = allocateInt(data);
	newNode1->prev = NULL;
	newNode1->next = NULL;
	
	//list 2
	Node* newNode2 = (Node*)malloc(sizeof(Node));
	newNode2->key = NULL;
	newNode2->prev = NULL;
	newNode2->next = NULL;
	
	if(newNode1 == NULL)
	{
		printf("\nERROR");
		exit(0);
	}
	if(head1 == NULL) // if list is blank, make list
	{
		//list 1
		head1 = newNode1;
		tail1 = newNode1;
		
		//list 2
		head2 = newNode2;
		tail2 = newNode2;
	}
	else
	{
		tail1->next = newNode1;
		newNode1->prev = tail1;
		tail1 = tail1->next;
		
		tail2->next = newNode2;
		newNode2->prev = tail2;
		tail2 = tail2->next;
	}
}

//function to print invalid input
void invalid()
{
	printf("INVALID INPUT");
	exit(0);
}

//insert value at given index
void indexInsert(Node* head, void* data, int index)
{
	int i;
	// if index is greater than size then invalid
	if(index > size)
		invalid();
	
	//for valid index
	for(i = 0; i < index; i++)
		head = head->next;
	head->key = data;	
}

//function to print the list
void printList()
{
	if(head1 == NULL)
		return;
	Node* temp = head1;
	
	while(temp)
	{
		int *x = (int*)temp->key;
		printf("%d ", *x);
		//printf("%d ", *(int*)temp->key);
        temp = temp->next;
	}
}

//function to count frequency based on the place value
void countFreq(int* count, int place)
{
	Node* temp = head1;
	while(temp)
	{
		int *x = (int*)temp->key;
		count[(*x/place) % 10]++;
		//count[((*(int*)temp->key) / place) % 10]++;
        temp = temp->next;
	}
}

//sorting based on place value
void createOutputList(int* count, int place)
{
	int index = size - 1;
    Node *temp = tail1;
    
    while(temp)
    {
    	int updatedIndex = ((*(int*)temp->key) / place) % 10;
        count[updatedIndex] = count[updatedIndex] - 1;
        indexInsert(head2, temp->key, count[updatedIndex]);

        temp = temp->prev;
        index = index-1;
	}
}

//counting sort
int countSort( int place)
{
	int i;
    // Array for holding the frequency of each digit.
    int* count = (int*)calloc(10, sizeof(int));
    // Counting the frequency of each digit.
    countFreq(count, place);

    // for cumulative frequency
    for (i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    createOutputList(count, place);
    swapList();
}

// radix sort.
void radixSort()
{
	int place;
    for (place = 1; (maxData / place) > 0; place = (place * 10))
        countSort(place);
}

//driver code
int main()
{
	int input, i;
	scanf("%d", &size);
	
	if(size > 0)
	{
		for(i = 0; i < size; i++)
		{
			scanf("%d", &input);
			//positive integer input
			if(input >= 0)
			{
				insert(input);
				
				if (maxData < input)
                    maxData = input;
			}
			else
				invalid();
		}
	}
	else
		invalid();
		
	radixSort();
	printList();
	
	printf("\n");
	return 0;
}

	



