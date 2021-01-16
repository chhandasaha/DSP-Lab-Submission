//implement queue using linked list
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

typedef struct Node
{
   int data;
   struct Node *next;
} Queue;

Queue *front = NULL,*rear = NULL;

void enQueue(int value)
{
    Queue *newNode;
    newNode = (Queue*)malloc(sizeof(Queue));
    newNode -> data = value;
    newNode -> next = NULL;

    if(front == NULL)
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
}

int deQueue()
{
    if(front == NULL)
        printf("Queue underflow\n");
    else
    {
        Queue *temp = front;
        front = front -> next;
		return temp->data;
        free(temp);
    }
}

void traverse()
{
    if(front == NULL)
        printf("\n Queue Empty!!!\n");
    else
    {
        Queue *temp = front;
        while(temp->next != NULL)
        {
            printf("%d --> ",temp->data);
            temp = temp -> next;
        }
        printf("%d \n",temp->data);
   }
}

int main()
{
    int choice, value;
    printf("Chose any option from below to implement Queue :");
    printf("\n1-> enqueue \n2-> dequeue \n3-> Display Queue \n4-> Exit");
    while(true)
    {
        printf("\nEnter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
         case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                enQueue(value);
                break;
         case 2:
                printf("de-queued element %d", deQueue());
                break;
         case 3:
                traverse();
                break;
         case 4:
                return 0;
         default:
                printf("\nInvalid option\n");
        };
    }
   return 0;
}
