#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int n)
    {
        data=n;
        next=NULL;
    }
};

node *insertend(node *head, int n) 
{
    node *temp=new node(n); //allocating in memoery
    if (head==NULL) // list is initially empty
    {
        head=temp;
        return temp;
    }
    node *temp2=head; // we get last last element.

    while(temp2->next!=NULL) // we know that last element->next =NULL
    {
        temp2=temp2->next;
    }
    temp2->next=temp; // allocating temp as last element 
    temp->next=NULL; // allocating last element next as NULL;
    return head; // return head as it is because head doesn't changed in the whole operation.
}

void printlist(node *head) //recursive approach
{
    if (head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    printlist(head->next);
}

int main()
{
    node *head =new node (10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=new node(50);

    head=insertend(head,40);
    head=insertend(head,50);


    printlist(head);
    return 0;
}