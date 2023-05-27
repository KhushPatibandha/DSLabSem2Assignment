// Question-1 Write a program which create binary search tree 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Node* root = NULL;

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if(data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void printTree(struct Node* root) 
{
    if (root != NULL) 
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void f(int choice, int data)
{
    switch (choice)
    {
        case 1:
        root = insertNode(root, data);
        break;
        
        case 2:
        printf("\n\nBinary Search Tree: ");
        printTree(root);
        break;
        
        default:
        printf("\nNOT A VALID OPTION!!");
        break;
    }
}

int main(void)
{
    while (1)
    {
        printf("\n\nOPTIONS: ");
        printf("\n1. Insert Node");
        printf("\n2. Print Tree");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        
        int choice;
        
        scanf("%d",&choice);
        
        if(choice == 3)
        {
            printf("\n\nEXITING!!");
            break;
        }
        
        int data = 0;
        
        if(choice == 1)
        {
            printf("Enter data to be inserted: ");
            scanf("%d",&data);
        }
        f(choice,data);
    }

    return 0;
}