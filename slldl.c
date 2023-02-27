
#include <stdio.h>
#include <stdlib.h>
void create();
void insertionbeg();
void insertionpos();
void deletefromend();
void insertionlast();
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *newnode, *temp, *prevnode;

void create()
{
    int choice;
    while (choice)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("do yo want to continue(0,1)");
        scanf("%d", &choice);
    }
}
void insertionbeg()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data u want to insert ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertionlast()
{
    struct node*ptr;
    ptr=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data u want to insert ");
    scanf("%d", &newnode->data);
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;


}

void insertionpos()
{
    temp = head;
    int count = 0;
    while (temp != NULL)
    {

        temp = temp->next;
        count++;
    }
    int pos;
    printf("Number of Nodes is : %d", count);
    printf("Enter the Pos");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("Invalid");
    }
    else if (pos == 1)
        
    {
        insertionbeg();
    }
    else
    {
        {
            temp = head;
            int i = 1;
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            while (i < pos-1)
            {
                temp = temp->next;
                i++;
            }
            printf("Enter the data");
            scanf("%d", &newnode->data);
            newnode->next = temp->next;

            temp->next = newnode;
        }
    }
}

void deletefromend()
{
    temp = head;
    while (temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
    }
    else
    {
        prevnode->next = NULL;
    }
    free(temp);
    
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

void main()

{
    create();
    display();
    printf("\n");
    insertionbeg();
    display();
    printf("\n");
    insertionpos();
    display();
    deletefromend();
    printf("\n");
    display();
    printf("\n");
    insertionlast();
    display();
}
