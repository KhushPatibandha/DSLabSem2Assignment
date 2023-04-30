// Question-1 Write a program for stack that performs following operations using int array based on input from user. Quit only when user selects Exit option. 1) PUSH, 2) POP, 3) CHANGE, 4) DISPLAY

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct  stack ST;
ST s;

// Function to add an element to stack
void push()
{
    int num;
    if(s.top == (MAXSIZE - 1))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        printf("Enter element to be pushed: \n");
        scanf("%i", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}

// Function to delete an elemnt from stack
int pop()
{
    int num;
    if(s.top == -1)
    {
        printf("Stack is Empty\n");
        return s.top;
    }
    else
    {
        num = s.stk[s.top];
        printf("Poped element is: %i\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return num;
}

// Function to display the status of stack
void display()
{
    int i;
    if(s.top == -1)
    {
        printf("Stack is empty \n");
        return;
    }
    else
    {
        printf("Status of element in stack: \n");
        for(i = s.top; i >= 0; i--)
        {
            printf("%i \n", s.stk[i]);
        }
    }
}

int main(void)
{
    int ch;
    s.top = -1;

    printf("Stack Operations \n");
    printf("--------------------\n");
    printf("1. PUSH \n");
    printf("2. POP \n");
    printf("3. DISPLAY \n");
    printf("4. EXIT \n");

    while(1)
    {
        printf("Choose operation: ");
        scanf("%i", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;
        
        default:
            printf("Invalid operation \n");
        }
    }
    return 0;
}


// Question-2 Write a fully functional program for a stack to perform all operations based on input from users I.e., Push operation for a string data like “India”, “Nepal” and display stack. Perform POP,DISPLAY,PEEP operation based on inputs from user.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
struct Stack
{
    char data[MAX_SIZE][50];
    int top;
}stack;

int is_empty(struct Stack* stack)
{
    return (stack->top == -1);
}

int is_full(struct Stack* stack)
{
    return (stack->top == MAX_SIZE-1);
}

void push(struct Stack* stack, char data[])
{
    if(is_full(stack))
    {
        printf("Stack overflow \n");
        return;
    }
    stack->top++;
    strcpy(stack->data[stack->top], data);
}

void pop(struct Stack* stack)
{
    if(is_empty(stack))
    {
        printf("Stack underflow \n");
        return;
    }
    printf("Popped element: %s\n", stack->data[stack->top]);
    stack->top--;
}

void display(struct Stack* stack)
{
    if(is_empty(stack))
    {
        printf("Stack is empty \n");
        return;
    }
    printf("Stack elements: \n");
    for(int i = stack->top; i >= 0; i--)
    {
        printf("%s \n", stack->data[i]);
    }
}

void peep(struct Stack* stack)
{
    if(is_empty(stack))
    {
        printf("Stack is empty \n");
        return;
    }
    printf("Top element %s \n", stack->data[stack->top]);
}

void f(int choice)
{
    switch (choice)
    {
        case 1: 
            printf("Enter the data to push: ");
            char data[100];
            scanf("%s", data);
            push(&stack, data);
            break;
        
        case 2:
            pop(&stack);
            break;

        case 3:
            display(&stack);
            break;

        case 4:
            peep(&stack);
            break;

        case 5:
            printf("Exiting... \n");
            exit(0);

        default:
            printf("Invalid choice \n");
    }
}

int main(void)
{
    stack.top = -1;
    int choice;
    do
    {
        printf("\n Stack Operations \n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Display \n");
        printf("4. Peep \n");
        printf("5. Exit \n");
        printf("Enter your choice: ");
        scanf("%i", &choice);

        f(choice);
    }while(1);

    return 0;
}