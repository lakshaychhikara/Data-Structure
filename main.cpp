//
//  main.cpp
//  bubble
//
//  Created by Karan Garg on 23/07/18.
//  Copyright © 2018 Karan Garg. All rights reserved.
//

#include <iostream>
using namespace std;
class selection
{
public:
    int a[100];
    void input(int);
    void sort(int);
    void print(int);
};
void selection::input(int n)
{
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
}
void selection::sort(int n)
{
    int i,j,temp=0;
    for (i=0;i<(n-1);i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
}
void selection::print(int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main()
{
    selection  obj;
    int n;
    cout<<"enter no of inputs";
    cin>>n;
    obj.input(n);
    obj.sort(n);
    obj.print(n);
}

