// Question-1 Write a program to implement CIRCULAR QUEUE that performs following operations using int array based on input from user. Exit only when user selects Exit option. 1)Insert 2)Delete 3)View First 4)View Last 5)DISPLAY

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    if(front == 0 && rear == MAX_SIZE -1)
    {
        return 1;
    }
    if(front == rear + 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if(front == -1)
    {
        return 1;
    }
    return 0;
}

void insert()
{
    int element;
    printf("Enter the element to be inserted: \n");
    scanf("%i", &element);

    if(isFull())
    {
        printf("Queue is full. \n");
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == MAX_SIZE - 1 && front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = element;
    printf("Inserted %i \n", element);
}

void removeElement()
{
    if(isEmpty())
    {
        printf("Queue is empty. \n");
        return;
    }
    printf("Removed %i \n", queue[front]);

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void viewFirst()
{
    if(isEmpty())
    {
        printf("Queue is empty. \n");
        return;
    }

    printf("First element: %i \n", queue[front]);
}

void viewLast()
{
    if(isEmpty())
    {
        printf("Queue is empty. \n");
        return;
    }
    printf("Last element: %i \n", queue[rear]);
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is empty. \n");
        return;
    }
    printf("Queue element: ");
    if(rear >= front)
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%i", queue[i]);
        }
    }
    else
    {
        for(int i = front; i < MAX_SIZE; i++)
        {
            printf("%i", queue[i]);
        }
        for(int i = 0; i < rear; i++)
        {
            printf("%i", queue[i]);
        }
    }
    printf("\n");
}

void f(int choice)
{
    switch (choice)
    {
    case 1:
        insert();
        break;

    case 2:
        removeElement();
        break;
    
    case 3:
        viewFirst();
        break;

    case 4: 
        viewLast();
        break;

    case 5:
        display();
        break;

    case 6:
        printf("Exiting... \n");
        break;
    
    default:
        printf("Invalid choice");
    }
}

int main()
{
    int choice, element;

    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. View First\n");
        printf("4. View Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter you choice: \n");
        scanf("%i", &choice);

        if(choice == 6)
        {
            break;
        }

        f(choice);
    }while(1);

    return 0;
}