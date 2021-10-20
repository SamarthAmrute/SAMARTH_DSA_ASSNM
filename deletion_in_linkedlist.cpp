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
//delete a node in the beggning
struct Node *deletefirst(struct Node *n1)
{
    struct Node *ptr=n1;
    n1=n1->next;
    free(ptr);
    return n1;
}
//delete a node at given index in the list
struct Node *deleteatindex(struct Node *n1,int index)
{
    struct Node *p=n1;
    struct Node *q=n1->next;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return n1;
}
//delete a node at the end
struct Node *deleteatend(struct Node *n1)
{
    struct Node *p=n1;
    struct Node *q=p->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return n1;
}
//delete a node at the given value in linked list
struct Node *deleteatgivenvalue(struct Node *n1,int value)
{
    struct Node *p=n1;
    struct Node *q=n1->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
    p->next=q->next;
    free(q);
    }
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
     
     cout<<"linked list before deletion"<<endl;
     linklist(n1);
     cout<<"linked list after deletion at first"<<endl;
     n1=deletefirst(n1);//for deleting first element in the linked list
     linklist(n1);
     cout<<"linked list after deletion at index value"<<endl;
     n1=deleteatindex(n1,2);
     linklist(n1);
     cout<<"linked list after deletion at end"<<endl;
     n1=deleteatend(n1);
     linklist(n1);
     cout<<"linked list deletion at given value"<<endl;
     n1=deleteatgivenvalue(n1,30);
     linklist(n1);

     return 0;
}
