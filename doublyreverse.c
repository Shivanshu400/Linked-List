//to reverse the doubly linked list//
#include<stdio.h>
#include<stdlib.h>
void create();
void display();

void reverse();


struct node
{
    int data;
    struct node*next;
    struct node*prev;
};


struct node*head,*newnode,*temp;
void create()
{
    head=NULL;
    int choice;
    while(choice)
    {
    
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data you want to insert");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    { 
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;

    }
    printf("You want to the countinue press(0-1)");
    scanf("%d",&choice);
    }
}
void reverse()
{
    struct node*currentnode,*prevnode,*nextnode;
    nextnode=currentnode=head;
    prevnode=NULL;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        currentnode->prev=nextnode;
        prevnode=currentnode;
        currentnode=nextnode;
        //head=prevnode;
    }
    head=prevnode;
    free(nextnode);
    free(currentnode);
    //printf("%d",nextnonde->data);
}
 void display()
{
 struct node*temp;
 temp=head;
 while(temp!=NULL)
 {
    if(temp->next==NULL)
    printf("%d",temp->data);
    else
    printf("%d ->",temp->data);
    temp=temp->next;
 }
}

 

 
 void main()
   {
   create();
   display();
   printf("\n");
   reverse();
   display();
   
   }
   
   
   
    


