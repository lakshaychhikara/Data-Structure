#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int a[20],b[20],c[40];
int m,n,p,val,i,j,key,pos,temp;

void create();
void display();
void insert();
void del();
void search();
void merge();
void sort();
int main()
{
        int choice;
        do{
                cout<<("\n\n--------Menu-----------\n");
                cout<<("1.Create\n");
                cout<<("2.Display\n");
                cout<<("3.Insert\n");
                cout<<("4.Delete\n");
                cout<<("5.Search\n");
                cout<<("6.Exit\n");
                cout<<("-----------------------");
                cout<<("\nEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert();
                                        break;
                        case 4:
                                        del();
                                        break;
                        case 5:
                                        search();
                                        break;
                        case 6:
                                        exit(0);
                                        break;
                        default:
                                        printf("\nInvalid choice:\n");
                                        break;
                }
        }while(choice!=8);
return 0;
}
void create()
{
        printf("\nEnter the size of the array elements:\t");
        scanf("%d",&n);
        printf("\nEnter the elements for the array:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
}
void display()
{
        int i;
        printf("\nThe array elements are:\n");
        for(i=0;i<n;i++){
                 printf("%d\t",a[i]);
         }
 }
void insert()
{
    printf("\nEnter the position for the new element:\t");
    scanf("%d",&pos);
    printf("\nEnter the element to be inserted :\t");
    scanf("%d",&val);
    for(i=n-1;i>=pos;i--)
        {
                a[i+1]=a[i];
        }
        a[pos]=val;
        n=n+1;
}


void del()
{
        printf("\nEnter the position of the element to be deleted:\t");
        scanf("%d",&pos);
        val=a[pos];
        for(i=pos;i<n-1;i++)
        {
                a[i]=a[i+1];
        }
        n=n-1;
        printf("\nThe deleted element is =%d",val);
}
void search()
{
        printf("\nEnter the element to be searched:\t");
        scanf("%d",&key);
        for(i=0;i<n;i++)
        {
                if(a[i]==key)
                {
                        printf("\nThe element is present at position %d",i);
                        break;
                }
        }
        if(i==n)
        {
                printf("\nThe search is unsuccessful");
        }
}
