
#include <iostream>
using namespace std;
class binary
{
public:
    int a[100];
    void input(int);
    void search(int,int);
};
void binary::input(int n)
{
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
}
void binary::search(int n,int m)
{
    int L=0,U=n-1,c=0,mid=0;
    while(L<=U)
    {
        mid=(L+U)/2;
        if(a[mid]==m)
        {
            c++;
            break;
        }
        if(a[mid]>m)
        {
            U=mid-1;
        }
        else if(a[mid]<m)
        {
            L=mid+1;
        }
    }
    if(c==1)
        cout<<"value present";
    else
        cout<<"value not presemt";
}
int main()
{
    binary obj;
    int n,m;
    cout<<"Enter no of inputs: ";
    cin>>n;
    obj.input(n);
    cout<<"Enter the value to be searched: ";
    cin>>m;
    obj.search(n,m);
    
}


