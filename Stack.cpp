#include<iostream>

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 5

using namespace std;

int item, choice, i;
int arr_stack[MAX_SIZE];
int top = 0;
int exit_p = 1;

void push() {
    if (top == MAX_SIZE)
        cout << "\n## Stack is Full!";
    else {
        cout << "\nEnter The Value to be pushed : ";
        cin>>item;
        cout << "\n## Position : " << top << ", Pushed Value  :" << item;
        arr_stack[top++] = item;
    }
}

void pop() {
    if (top == 0)
        cout << "\n## Stack is Empty!";
    else {
        --top;
        cout << "\n## Position : " << top << ", Popped Value  :" << arr_stack[top];
    }
}

void display() {
    cout << "\n## Stack Size : " << top;
    for (i = (top - 1); i >= 0; i--)
        cout << "\n## Position : " << i << ", Value  :" << arr_stack[i];
}

int main() {
    do {
        cout << "\n\nStack Main Menu";

        cout << "\n1.Push \n2.Pop \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

    return 0;
}
