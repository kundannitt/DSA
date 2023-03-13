#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
    node(int n)
    {
        data=n;
        next=nullptr;
        prev=nullptr;
    }
};

void print(node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

node *insertbegin(node *head, int val){
    node *key=new node(val);
    key->next=head;
    head->prev=key;
    return key;
}

int main()
{
    node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    node *temp3=new node(40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;

    temp1->prev=head;
    temp2->prev=temp1;
    temp3->prev=temp2;

    head=insertbegin(head,5);
    print(head);

return 0;
}