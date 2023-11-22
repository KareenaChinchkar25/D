#include<stdio.h>
#include <stdlib.h>
int deque[10];    
int front = -1, rear = -1;  

#define MAX 10
int front,rear;
void Insert_from_Front();
void Insert_from_Rear();
void Delete_from_Front();
void Delete_from_Rear();
void Display();
void main()
{
    int ch,x;
    while(1)
    {
        printf("\nEnter the Choice");
        printf("\n1.Insert from Front\n2.Insert from Rear\n3.Delete from Front\n4.Delete From Rear\n5.Display\n6.exit ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter The Val");
                   scanf("%d",&x);
                   Insert_from_Front( x);
                   break;
            case 2:Insert_from_Rear( x);
                   break; 
            case 3:Delete_from_Front();
                   break; 
            case 4:Delete_from_Rear();
                   break;  
            case 5:Display();
                   break;  
            case 6:exit(0);
                   break; 
            Default:printf("\nWrong Choice");                         

        }

    }
}
void Insert_from_Front(int x)
{
  if((front==0&&rear==MAX-1)||(front==rear+1))
  {
    printf("Queue is full");
  }
  else if(front==-1&&rear==-1)
  {
     front=0;
     rear=0;
     deque[front]=x;
  }
  else if(front==0)
  {
    front=MAX-1;
    deque[front]=x;
  }
  else
  {
    front=front-1;
    deque[front]=x;
  }
}
void Insert_from_Rear(int x)
{
  if((front==0&&rear==MAX-1)||(front==rear+1))
  {
    printf("Queue is full");
  }
  else if(front==-1&&rear==-1)
  {
     front=0;
     rear=0;
     deque[rear]=x;
  }
  else if(rear==MAX-1)
  {
   rear=0;
   deque[rear]=x;
  }
  else
  {
    rear++;
   deque [rear]=x;
  }
}
void Delete_from_Front()
{
  if(front==-1&&rear==-1)
  {
    printf("Queue is Empty");
  }
  else if(front=rear)
  {
    printf("%d is deleted",deque[front]);
    front=rear-1;
  }
  else if(rear==MAX-1)
  {
     printf("%d is deleted",deque[front]);
   front=0;
  }
  else
  {
    printf("%d is deleted",front);
    front++;
  }
}
void Delete_from_Rear()
{
  if(front==-1&&rear==-1)
  {
    printf("Queue is Empty");
  }
  else if(front=rear)
  {
    printf("%d is deleted",deque[rear]);
    front=rear-1;
  }
  else if(rear==MAX-1)
  {
     printf("%d is deleted",deque[rear]);
    rear--;
  }
  else
  {
    printf("%d is deleted",deque[rear]);
    rear=MAX-1;
  }
}
void Display()
{
    int i;
    i=front;
    if(front==-1&&rear==-1)
    {
        printf("Queue is Empty");
    }
    else
    {
        while(i!=rear)
        {
            printf("%d\t",deque[i]);
            i=i+1%MAX;
        }
        printf("\t%d",deque[rear]);
    }
}