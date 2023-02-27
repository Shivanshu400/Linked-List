//TO PRINT THE REVERSE LINKED LIST OF  SINGLY//
#include<stdio.h>
#include<stdlib.h>
void reversed();
void create();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*newnode,*temp,*currentnode,*nextnode;


void create()
{
     int choice;
    while(choice){
        struct node* newnode=(struct node* )malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode -> next=NULL;
       
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            temp=newnode;
            
        }
        printf("do yo want to continue(0,1)");
        scanf("%d",&choice);
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL)
            printf("%d",temp->data);
        else
            printf("%d -> ",temp->data);
        temp=temp->next;
        
    }
}
void main()
{
    create();
    display();
    reversed();
    display();
}  
void reversed()
{
    temp=NULL;
    currentnode=nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=temp;
        temp=currentnode;
        currentnode=nextnode;
    }
    head=temp;
    free(nextnode);
}

