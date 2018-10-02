//
//  main.cpp
//  bubble
//
//  Created by Karan Garg on 23/07/18.
//  Copyright © 2018 Karan Garg. All rights reserved.
//

#include <iostream>
using namespace std;
class bubble
{
public:
    int a[100];
    void input(int);
    void sort(int);
    void print(int);
};
void bubble::input(int n)
{
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
}
void bubble::sort(int n)
{
    int i,j,temp=0;
    for (i=0;i<(n-1);i++)
        for(j=0;j<(n-1-i);j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}
void bubble::print(int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main()
{
    bubble obj;
    int n;
    cout<<"enter no of inputs";
    cin>>n;
    obj.input(n);
    obj.sort(n);
    obj.print(n);
}
