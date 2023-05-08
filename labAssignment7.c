// Question-1 Write programs in C to implement following operations on the Doubly Linked List. a) Insert a node at the front of the linked list. b) Insert a node at the end of the linked list. c) Insert a node such that linked list is in ascending order. (I.e. if existing data, 2,3,5,6. And new data is "4" then it must be inserted after node with data "3".) d) Delete a first node of the linked list. e) Delete a node after specific position. (Ie. Node before 5th position or "6" data value.) f) Delete a node after specific position.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL)
    {
        head->prev = new_node;
    }
    head = new_node;
}

void insertEnd(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL) 
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void insertSorted(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head == NULL || head->data >= new_data)
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < new_data)
    {
        temp = temp->next;
    }
    new_node->prev = temp;
    new_node->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void deleteFront()
{
    if (head == NULL)
    {
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}

void deleteLast(int pos)
{
    if (head == NULL)
    {
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    if (next != NULL)
    {
        next->prev = temp;
    }
}

void deleteNode(int key)
{
    if (head == NULL)
    {
        return;
    }
    struct Node* temp = head;
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void displayList()
{
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void f(int choice, int data)
{
    switch (choice)
    {
        case 1:
            insertFront(data);
            break;

        case 2:
            insertEnd(data);
            break;

        case 3:
            insertSorted(data);
            break;

        case 4:
            deleteFront();
            break;

        case 5:
            deleteLast(data);
            break;

        case 6:
            deleteNode(data);
            break;
        
        case 7:
            displayList();
            break;
        
        default:
            break;
    }
}

int main()
{
    int choice, data;
    while(1) 
    {
        data = 0;
        printf("\n\n\tOPTIONS\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Sorted Order\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node After Position\n");
        printf("7. Display Linked List\n");
        printf("8. Exit\n");
        printf("\n\nEnter Option: ");
        scanf("%d",&choice);
        if(choice == 8)
        {
            printf("\n\tEXITING....");
            break;
        }
        else if(choice == 1 ||choice == 2 ||choice == 3 ||choice == 5 ||choice == 6)
        {
            printf("\n\nEnter Data: ");
            scanf("%d",&data);
        }
        f(choice, data);
    }

    return 0;
}