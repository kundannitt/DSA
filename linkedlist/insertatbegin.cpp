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

node *insertbegin(node *head, int n)
{
    node *temp=new node (n);
    temp->next=head;
    return temp;  // return temp because temp is our new head(or starting element).
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

    head=insertbegin(head,10);
    head=insertbegin(head,5);

    printlist(head);
    return 0;
}