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


node *insert(node *head, int pos, int val)
{
    node *temp=head;
    node *temp2=head->next;
    pos-=2;
    while(pos--)
    {
        temp=temp->next;
        temp2=temp2->next;
    }
    node *temp3=new node (val);
    temp->next=temp3;
    temp3->next=temp2;
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

    head=insert(head,2,300);
    printlist(head);
    return 0;
}