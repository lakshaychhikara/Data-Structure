#include <iostream>

#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node* next;
};

int flag;

struct node* insertatfront(struct node* thead,int x);
struct node* insertatend(struct node* thead,int x);
struct node* insertatposition(struct node* thead,int pos,int x);
struct node* deleteatfront(struct node* thead,int *pans);
struct node* deleteatend(struct node* thead,int *pans);
struct node* deleteatposition(struct node* thead,int pos,int *pans);
void printlist(struct node* thead);
int length(struct node* thead);

int main()
{
 struct node* head=NULL;
 int breakcondition=1;
 printf("Empty Linked list is created..");
 int ch,x,p;
 printf("\nChoice : \n1) Insert at Front.\n2) Insert at End.\n3) Insert at Position\n4) Delete at Front\n5) Delete at End.\n6) Delete at Position\n7) Print the list.\n8) Stop..");
 while(1)
{
 printf("\nEnter your choice..");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:{
          printf("\nEnter any element you want to insert...");
          scanf("%d",&x);
          head=insertatfront(head,x);
          printlist(head);
          break;
         }
  case 2:{
          printf("\nEnter any element you want to insert...");
          scanf("%d",&x);
          head=insertatend(head,x);
          printlist(head);
          break;
         }
  case 3:{
          printf("\nEnter any element you want to insert and its position..");
          scanf("%d%d",&x,&p);
          head=insertatposition(head,p,x);
          printlist(head);
          break;
          }
  case 4:{
          int ans;
          flag=0;
          head=deleteatfront(head,&ans);
          if(flag==0)
          printf("\nThe element which is deleted is ..%d",ans);
          printlist(head);
          break;
         }
  case 5:{
          int ans;
          flag=0;
          head=deleteatend(head,&ans);
          if(flag==0)
          printf("\nThe element which is deleted is ..%d",ans);
          printlist(head);
          break;
         }
  case 6:{
          int ans;
          flag=0;
          printf("\nEnter the position..");
          scanf("%d",&p);
          head=deleteatposition(head,p,&ans);
          if(flag==0)
          printf("\nThe element which is deleted is ..%d",ans);
          printlist(head);
          break;
          }
  case 7:{
          printlist(head);
          break;
         }
  case 8:{
          breakcondition=0;
          break;
         }
  default : printf("\nPlease Enter a valid choice..");

 }
 if(breakcondition==0)
   break;
}
}


struct node* insertatfront(struct node* thead,int x)
{
 struct node* newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data=x;
 if(thead==NULL){
    newnode->next=newnode;
    return newnode;
 }
 newnode->next=thead;
 struct node* trav=thead;
 while(trav->next!=thead)
    trav=trav->next;
 trav->next=newnode;
 return newnode;
}
struct node* insertatend(struct node* thead,int x)
{
 struct node* newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data=x;
 if(thead==NULL)
 {
  newnode->next=newnode;
  return newnode;
 }
 struct node* trav=thead;
 while(trav->next!=thead)
   trav=trav->next;
 trav->next=newnode;
 newnode->next=thead;
 return thead;
}

struct node* insertatposition(struct node* thead,int pos,int x)
{
    int len=length(thead);
    if(pos<=0||pos>len+1){
        printf("\nThe position is invalid..");
        return thead;
    }
    if(pos==1){
        thead=insertatfront(thead,x);
        return thead;
    }
    else if(pos==len+1){
        thead=insertatend(thead,x);
        return thead;
    }
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=x;
    struct node* trav;
    int i;
    trav=thead;
    for(i=1;i<=pos-2;i++){
        trav=trav->next;
    }
    newnode->next=trav->next;
    trav->next=newnode;
    return thead;
}

struct node* deleteatfront(struct node* thead,int *pans)
{
 if(thead==NULL)
 {
  flag=1;
  return thead;
 }
 else if(thead->next==thead){
    *pans=thead->data;
    free(thead);
    return NULL;
 }
 struct node* trav=thead;
 *pans=trav->data;
 while(trav->next!=thead)
    trav=trav->next;
 trav->next=thead->next;
 trav=trav->next;
 free(thead);
 return trav;
}

struct node* deleteatend(struct node* thead,int *pans)
{
 if(thead==NULL)
 {
  flag=1;
  return thead;
 }
 if(thead->next==thead)
 {
  *pans=thead->data;
  free(thead);
  return NULL;
 }
 struct node* trav=thead;
 while(trav->next->next!=thead)
  trav=trav->next;
 struct node* temp=trav->next;
 *pans=temp->data;
 free(temp);
 trav->next=thead;
 return thead;
}

struct node* deleteatposition(struct node* thead,int pos,int *pans)
{
    int len=length(thead);
    if(pos<=0||pos>len){
        printf("\nThe position is invalid..");
        flag=1;
        return thead;
    }
    if(pos==1){
        thead=deleteatfront(thead,pans);
        return thead;
    }
    else if(pos==len){
        thead=deleteatend(thead,pans);
        return thead;
    }
    struct node* front,* current;
    front=current=thead;
    int i;
    if(thead==NULL){
        printf("\nThe List is already Empty..");
        flag=1;
        return thead;
    }
    for(i=1;i<=pos-1;i++){
        front=current;
        current=current->next;
    }
    *pans=current->data;
    front->next=current->next;
    free(current);
    return thead;
}

void printlist(struct node* thead)
{
 if(thead==NULL)
  {
   printf("\nThe list is Empty..");
   return;
  }
 printf("\nThe list is..");
 struct node* trav=thead;
 printf("%d ",trav->data);
 trav=trav->next;
 while(trav!=thead)
  {
   printf("%d ",trav->data);
   trav=trav->next;
  }
}

int length(struct node* thead)
{
    int c=0;
    if(thead==NULL){
        return c;
    }
    c=1;
    struct node* trav=thead->next;
    while(trav!=thead){
        c++;
        trav=trav->next;
    }
    return c;
}
