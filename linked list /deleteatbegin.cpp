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

node *deletebegin(node *head) // for deleting first element in the list we just need to make second element as head.
{
    if (head==NULL) //empty list
    {
        return NULL;
    }
    if (head->next==NULL) //only one element 
    {
        return NULL;
    }
    head=head->next;
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

    head=deletebegin(head); //removing one element from the beginning
    printlist(head);
    return 0;
}