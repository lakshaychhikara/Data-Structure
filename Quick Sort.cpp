

#include <iostream>
using namespace std;

int a[20];
class quicksort
{
public:
    int quick(int,int);
};
int quicksort::quick(int beg,int end)
{
    int loc=beg,temp=0;
    int left=beg,right=end;
    while(1)
    {
    while(a[right]>=a[loc]&&right>loc)
        right--;
    if(loc==right)
        return loc;
    temp=a[right];
    a[right]=a[loc];
    a[loc]=temp;
    loc=right;
    while(a[left]<=a[loc]&&left<loc)
        left++;
    if(loc==left)
        return loc;
    temp=a[left];
    a[left]=a[loc];
    a[loc]=temp;
    loc=left;
    }
}
int main()
{
    quicksort s;
    int n,top=-1;
    cout<<"enter the size";
    cin>>n;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    int lower[10],upper[10],beg=0,end=0;
    top++;
    lower[top]=0;
    upper[top]=n-1;
    while(top!=-1)
    {
        int loc;
        beg=lower[top];
        end=upper[top];
        top--;
        loc=s.quick(beg,end);
        if(beg<loc-1)
        {
            top++;
            lower[top]=beg;
            upper[top]=loc-1;
        }
        if(loc+1<end)
        {
            top++;
            lower[top]=loc+1;
            upper[top]=end;
        }
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    
}

