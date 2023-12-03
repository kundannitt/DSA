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

bool isloop(node *head){
  node *slow=head;
  node *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(fast==slow){ // if there is a loop then this condition will be definitely true after some iterations.
      return true;
    }
  }
  return false;
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
    cout<<isloop(head);
    // print(head);
    return 0;
}