//To insert the doubly linked list//
#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insertatlast();
void insertatfirst();
void insertatposit();
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

//to insert the node at last//
void insertatlast()
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
else{
    while(temp->next!=NULL){
    temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
    } 
}
//to insert a node at first//
void insertatfirst()
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
newnode->next=head;
head->prev=newnode;
head=newnode;

}
//Insert at any position in linked list//
void insertatposit()
{
   int pos,count=0,i=1;
    temp=head;
   printf("Enter the position");
   scanf("%d",&pos);
   while(temp!=NULL)
   {
    //printf("1");
    temp=temp->next;
    count++;
   } 
   if(pos>count)
   {
    printf("Invalid");
    return;
   }
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter the value you want to insert");
   scanf("%d",&newnode->data);
   temp=head;
   while(i<pos-1)
   {
    temp=temp->next;
    i++;
   }
   newnode->prev=temp;
   newnode->next=temp->next;
   temp->next=newnode;
   newnode->next->prev=newnode;
}


 
void display()
{
 struct node*temp;
 temp=head;
 while(temp!=0)
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
   insertatlast();
   display();
   insertatfirst();
   display();
   insertatposit();
   display();
   insertatlast();
   display();
   }
    


