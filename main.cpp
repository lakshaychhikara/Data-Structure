#include<iostream>
#include<stdlib.h>

using namespace std;

class cqueue
{
   int q[5],front,rare;
   public:
      cqueue()
      {
	 front=-1;
	 rare=-1;
      }
      void push(int x)
      {
	 if(front ==-1 && rare == -1)
	 {
	   q[++rare]=x;
	   front=rare;
	   return;
	 }
	 else if(front == (rare+1)%5 )
	 {
	    cout <<" Circular Queue over flow";
	    return;
	 }
	 rare= (rare+1)%5;
	 q[rare]=x;
     }

     void pop()
     {
	if(front==-1 && rare==	-1)
	{
	  cout <<"under flow";
	  return;
	}
	else if( front== rare  )
	{
	  front=rare=-1;
	  return;
	}
	front= (front+1)%5;
     }




 void display()
    {
      int i;
      if( front <= rare)
      {
	for(i=front; i<=rare;i++)
	cout << q[i]<<" ";
      }
      else
      {
	 for(i=front;i<=4;i++)
	 {
	   cout <<q[i] << " ";
	 }
	 for(i=0;i<=rare;i++)
	 {
	    cout << q[i]<< " ";
	 }
      }
    }
};

int main()
{

int ch;
cqueue q1;
while( 1)
{
cout<<"\n1.INSERT   2.DELETE   3.DISPLAY    4.EXIT\nEnter ur choice";
cin >> ch;
switch(ch)
{
case 1: cout<<"enter element";
	cin >> ch;
	q1.push(ch); break;

case 2: q1.pop(); break;
case 3: q1.display(); break;
case 4: exit(0);
}
}
return 0;
}
