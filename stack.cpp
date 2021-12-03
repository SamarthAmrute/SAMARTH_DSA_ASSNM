//PROGRAM TO IMPLEMENT STACK USING ARRAY (with PUSH & POP operations)
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
        cout << "STACK UNDERFLOW";
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
    push(1);
    push(2);
    push(3);
    push(4);

    cout << "Using the push function \nSTACK IS - \n";
    display();

    cout << "\nUsing the pop function\nFirst deleted element - " << pop();
    cout << "\nSecond deleted element - " << pop();
    
    cout << "\n\nSTACK after deletion of the elements \n";
    display();
}
