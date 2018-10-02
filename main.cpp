//
//  main.cpp
//  insertion_sort
//
//  Created by Karan Garg on 02/10/18.
//  Copyright © 2018 Karan Garg. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n,i,j,temp;
    cout<<"enter the size of array";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    
}
