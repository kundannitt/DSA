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

node *deleteend(node *head)
{
    node *temp=head;
    while(temp->next->next!=NULL) // it will give second last element from the list
    {
        temp=temp->next;
    }

    temp->next=NULL; //alloting last element as NULL
    delete temp->next; //(optional) deleting last element from memory 
    return head;
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

    head=deleteend(head); //removing one element from back
    printlist(head);
    return 0;
}