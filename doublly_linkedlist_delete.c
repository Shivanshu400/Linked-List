 #include <stdio.h>
#include <stdlib.h>
void create();
void display();
void deleteatpos();
void deletend();
void deletebeg();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *temp;
void create()
{
    head = NULL;
    int choice;
    while (choice)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data you want to insert");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("You want to the countinue press(0-1)");
        scanf("%d", &choice);
    }
}
// TO DELETE THE NODE FROM POSITION
void deleteatpos()
{
    struct node *prevnode, *temp;
    prevnode = NULL;
    temp = head;
    int i = 1, pos, count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Enter the pos");
    scanf("%d", &pos);
    while (pos > count)
    {
        printf("The given position is invalid\n");
        printf("Please enter the position again");
        scanf("%d", &pos);
    }
    temp = head;
    if (pos == 1)
    {
        deletebeg();
    }
    else if (pos == count)
    {
        deletend();
    }
    else
    {
        while (i < pos)
        {
            prevnode = temp;
            temp = temp->next;
            i++;
        }
        prevnode->next = temp->next;
        temp->next->prev = prevnode;
        free(temp);
    }
}

void deletend()
{
    struct node *tail, *temp;
    temp = head;
    while (temp != NULL)
    {
        tail = temp;
        temp = temp->next;
    }
    tail->prev->next = NULL;
    tail->prev = NULL;
    free(tail);
}

// TO DELETE THE NODE FROM THE BEGGNING//

void deletebeg()
{
    if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}
// TO DISPLAY THE NODE ON SCREEN
void display()
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ->", temp->data);
        temp = temp->next;
    }
}

void main()
{
    create();
    display();
    deleteatpos();
    display();
    printf("\n");
    deletebeg();
    display();
    printf("\n");
    deletend();
    display();
}
