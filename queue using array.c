//implement stack using array 
#include<stdio.h>
#define n 200
int main()
{
    int queue[n],choice=1,front=0,rear=0,i,j=1,x=n; // x is max elem in the queue
    // choose option which operation you want to perform
	printf("Chose any option from below to implement Queue :");
    printf("\n1-> Insertion \n2-> Deletion \n3-> Display \n4-> Exit");
    while(choice)
    {
        printf("\nEnter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(rear==x)// no space Queue
                printf("\n Queue is Full");
            else
            {
                printf("\nEnter data for enqueue : ",j++);
                scanf("%d",&queue[rear++]);//put the value at the end of the queue
            }
            break;
        case 2:
            if(front==rear)// no element in the queue
            {
                printf("\nQueue Underflow ");
            }
            else
            {
                printf("\nElement deleted from the queue is %d",queue[front++]);//delete the element from the front
                x++;
            }
            break;
        case 3:
            printf("\nQueue Elements are :\n ");
            if(front==rear)
                printf("\nQueue is Empty");
            else
            {
                for(i=front; i<rear; i++)
                {
                    printf(" %d",queue[i]);
                    printf(" \n");
                }
                break;
            case 4:
				return 0;
            default:
                printf("Wrong Choice: please check the given options");
            }
        }
    }
    return 0;
}
