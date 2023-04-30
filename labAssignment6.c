// Question-1 Write programs in c to implement following operations on the Singly Linked List. a)Insert a node at the beginning of the linked list. b)Insert a node at the end of the linked list. c)Insert a node such that linked list is in ascending order. d)Delete a first node of the linked list. e)Delete a node at the end of the linked list. f)Delete a node after specific position.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insertAtBeginning()
{
    int new_data;
    printf("Enter the data to be inserted at the beginning: \n");
    scanf("%i", &new_data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd()
{
    int new_data;
    printf("Enter the data to be inserted at the end: \n");
    scanf("%i", &new_data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last = head;
    new_node->data = new_data;
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
        last->next = new_node;
    }
}

void insertInAscendingOrder()
{
    int new_data;
    printf("Enter the data to be inserted in ascending order: \n");
    scanf("%i", &new_data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    struct node *current = head;
    struct node *prev = NULL;
    while(current != NULL && current->data < new_data)
    {
        prev = current;
        current = current->next;
    }
    if(prev == NULL)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        new_node->next = prev->next;;
        prev->next = new_node;
    }
}

void deleteFirstNode()
{
    if(head == NULL)
    {
        return;
    }
    struct node *temp = head;
    head = temp->next;
    free(temp);
}

void deleteLastNode()
{
    if(head == NULL)
    {
        return;
    }
    struct node *last = head;
    struct node * prev = NULL;
    while(last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    if(prev == NULL)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    free(last);
}

void deleteNodeAfterPosition()
{
    int pos, i = 1;
    printf("Enter the position after which node id to be deleted: \n");
    scanf("%i", &pos);
    if(head == NULL)
    {
        return;
    }
    struct node *current = head;
    struct node *prev = NULL;
    while(i < prev && current != NULL)
    {
        prev = current;
        current = current->next;
        i++;
    }
    if(current == NULL || current->next == NULL)
    {
        return;
    }
    struct node *temp = current-> next;
    current->next = temp->next;
    free(temp);
}

void display()
{
    struct node *temp = head;
    printf("Linked List: \n");
    while(temp != NULL)
    {
        printf("%i \n", temp->data);
        temp = temp->next;
    }
}

void f(int choice)
{
    switch(choice)
    {
        case 1:
            insertAtBeginning();
            break;

        case 2:
            insertAtEnd();
            break;

        case 3:
            insertInAscendingOrder();
            break;

        case 4:
            deleteFirstNode();
            break;

        case 5:
            deleteLastNode();
            break;

        case 6:
            deleteNodeAfterPosition();
            break;

        case 7:
            display();
            break;

        default:
            break;
    }
}

int main(void)
{
    int choice;
    while(1)
    {
        printf("OPTION \n");
        printf("1. Insert at Beginning \n");
        printf("2. Insert at End \n");
        printf("3. Insert in Ascending Order \n");
        printf("4. Delete First Node \n");
        printf("5. Delete Last Node \n");
        printf("6. Delete Node After Position \n");
        printf("7. Display Linked List \n");
        printf("8. Exit \n");
        printf("Enter Option: ");
        scanf("%i", &choice);

        if(choice == 8)
        {
            printf("Exiting... \n");
            break;
        }
        f(choice);
    }
    return 0;
}