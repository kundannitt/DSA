//the last node points to the head =>cyclic 
// In this we fill first insert the key at 2nd node and then swap the values of head and 2nd node .. and then make head->next as head.
// since it is cyclic the previous head will be considered as last node.
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

node *deletepos(node *head,int pos){
  pos=pos-2;
  node *temp=head;
  while(pos--){
    temp=temp->next; // gives pointer to the prev node of the node we have to delete.
  }
  temp->next=temp->next->next;
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
    head=deletepos(head,3); 
    print(head);
    return 0;
}