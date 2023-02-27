#include<stdio.h>
#include<stdlib.h>
void implement();
void display();
void insertatbeg();
void insertatlast();
void insertatpos();
void deletebeg();
void deletelast();
void deletepos();
void reverse();
struct node
{
    int data;
    struct node*next;
};
struct node*head,*tail,*newnode,*temp;

void implement()
{
    //head=NULL;
     int choice;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter your data");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=tail=newnode;
            tail->next=head;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    
        printf("Enter your choice");
        scanf("%d",&choice);
    }
}
//TO INSERT THE NOTE AT LAST
void inseratlast()
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    tail->next=newnode;
    printf("Enter the value of data you want to insert at last");
    scanf("%d",&newnode->data);
    tail=newnode;
    tail->next=head;
}
//TO INSERT THE NODE AT BEGNNING
void insertatbeg()
{
    head=tail->next;
struct node*newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data you want to store at first");
scanf("%d",&newnode->data);
newnode->next=head;
tail->next=newnode;
head=newnode;
}
//TO INSERT THE NODE AT ANY POSITION//

void insertatpos()
{
    struct node* temp1;
    int i=1,pos,choice;
    temp1=head;
   while(choice)
   {
    printf("Enter the position you want to store the node");
    scanf("%d",&pos);
    {
       
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data you want to insert at given position");
        scanf("%d",&newnode->data);
        
        if(pos==1)
        {
            head=tail->next;
            newnode->next=head;
            tail->next=newnode;
            head=newnode;
        }
        else 
        {
        while(i<pos-1)
        {
           temp1=temp1->next;
           i++;

        }
        newnode->next=temp1->next;
        temp1->next=newnode;
        }
        printf("Enter the   choice");
       scanf("%d",&choice);
    }
   }
     
}
//TO DELETE THE NODE FROM THE BEGGINING//
void deletebeg()
{
    struct node*temp1;
    temp1=head;
    head=head->next;
    tail->next=head;
    free(temp1);
}

//TO DELETE THE NODE FROM THE LAST//
void deletelast()
{
struct node*temp1;
temp1=head;
while(temp1->next!=tail)
{
    temp1=temp1->next;
}
temp1->next=head;
free(tail);
}
//TO DELETE THE NODE AT ANY POSITION//
void deletepos()
{
    struct node*temp1,*save;
    int i=1,pos;
    temp1=tail->next;
    save=temp1->next;
    printf("Enter the position to delete the data");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp1=temp1->next;
        save=temp1->next;
    }
    temp1->next=save->next;
    free(save);
    
}

//TO REVERSE THE SINGLY LINKED LIST //
void reverse()
{
    struct node*nextnode,*currentnode,*p;
    currentnode=tail->next;
    nextnode=currentnode->next;
    while(currentnode!=tail)
    {
     p=currentnode;
     currentnode=nextnode;
     nextnode=currentnode->next;
     currentnode->next=p;
       
    }
    head=currentnode;
  nextnode->next=tail;
  //head=p->next;
}
// }
 
void display()
{
    tail=head;
    while(tail->next!=head)
    {
        if(tail->next==head)
        printf("%d",tail->data);
        else{
        printf("%d->",tail->data);}
        tail=tail->next;
    }
    printf("%d",tail->data);
    //printf("%d",tail->next->data);
}
void main()
{
    implement();
    display();

    printf("\n");
    deletebeg();
    display();
    
    printf("\n");

    deletepos();
    display();
    
    printf("\n");

    deletelast();
    display();

    printf("\n");
    
    reverse();
    display();
    printf("\n");

    insertatpos();
    display();
    printf("\n");

    insertatbeg();
    display();
    printf("\n");

    inseratlast();
    display();

    
}