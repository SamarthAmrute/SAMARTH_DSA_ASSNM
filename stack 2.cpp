//INSERTION AND DELETION FROM THE STACK AS PER THE USER
#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
#define SIZE 4

int stack[SIZE];
int top = -1;

//TO DISPLAY STACK ELEMENTS
void display()
{
    if(top == -1)                               //if the stack is EMPTY
    {
        cout << "STACK is EMPTY!!!";
        return;
    }
    for(int i = top; i >= 0; i--)
    cout << stack[i] <<"\n";
}

//TO INSERT AN ELEMENT IN THE STACK
void push(int data)   
{
    if (top == SIZE - 1){
        cout << "OVERFLOW!!";                   //if the stack is FULL
        return;
    }
    top++;
    stack[top] = data;
}

//TO REMOVE THE LAST ELEMENT FROM THE STACK
int pop()
{
    int data;
    if (top == -1){
        cout << "UNDERFLOW!!";                  //if the stack is EMPTY
        exit(1);
    }
    data = stack[top];
    top--;
    return data;
}

int main()
{
    int ch, value;
    char c;
    do{
        cout << "STACK OPERATIONS MENU -\n";
        cout << "\n 1)Insert an element in the stack";
        cout << "\n 2)Remove an element from the stack";
        cout << "\n\nEnter your choice" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter the value of the element to be inserted" << endl;
            cin >> value;
            push(value);
            cout << "\nUsing the push function \nSTACK IS - \n";
            display();
            break;

        case 2:
            cout << "\nRemoving the top-most element..." << endl;
            cout << pop() << " is the deleted element ";
            break;
        
        default:
            cout << "\nEnter a valid choice";
            break;
        }
        cout << "\n\nWant to perform more actions? Press y/Y for YES else n/N : \n";
        cin >> c;
        if ((c == 'n') || (c == 'N'))
        cout << "\nSTACK after performing INSERTIONS and DELETIONS \n";
        display();
    } while ((c == 'y') || (c == 'Y')); 
}
