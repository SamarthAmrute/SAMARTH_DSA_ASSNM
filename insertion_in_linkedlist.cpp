#include<iostream>
#include<stdlib.h>
using namespace std;


struct Node
{
    int data;
    struct Node *next;

};
void linklist(struct Node *ptr)
{
    while(ptr!=NULL){
    cout<<"elements:"<<ptr->data<<endl;
    ptr=ptr->next;
    }
}
//insert node at the beggining
struct Node * insert(struct Node *n1,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=n1;
    ptr->data=data;
    return ptr;
}
//insert node in between
struct Node *insertatindex(struct Node *n1,int data,int index)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=n1;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;

    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return n1;
}
//insert node at the end
struct Node * insertatend(struct Node *n1,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=n1;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return n1;
}

int main()
{
    struct Node *n1,*n2,*n3,*n4;
    n1=(struct Node*)malloc(sizeof(struct Node));
    n2=(struct Node*)malloc(sizeof(struct Node));
    n3=(struct Node*)malloc(sizeof(struct Node));
    n4=(struct Node*)malloc(sizeof(struct Node));
    
    n1->data=10;
    n1->next=n2;

    n2->data=20;
    n2->next=n3;

    n3->data=30;
    n3->next=n4;

    n4->data=40;
    n4->next=NULL;
     
     cout<<"linked list before insertion"<<endl;
     linklist(n1);
     cout<<"linked list after insertion at beggining"<<endl;
     n1=insert(n1,5);
     linklist(n1);
     cout<<"linked list after insertion in between"<<endl;
     n1=insertatindex(n1,15,2);
     linklist(n1);
     cout<<"linked list after insertion at the end"<<endl;
     n1=insertatend(n1,50);
     linklist(n1);
     return 0;
}
