//the last node points to the head =>cyclic 
// In this we fill first insert the key at 2nd node and then swap the values of head and 2nd node.
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int n)
    {
        data=n;
        next=nullptr;
    }
};

void print(node *head){
    node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
}

node *insertbegin(node *head,int val){
    node *key=new node(val);

    key->next=head->next;
    head->next=key;

    int t=head->data;
    head->data=head->next->data;
    head->next->data=t;
    return head;

}

int main(){
    node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    node *temp3=new node(40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=head; // defines the cyclic linked list. 
    head=insertbegin(head,5);
    print(head);
    return 0;
}