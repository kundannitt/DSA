#include <bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next;
  node(int n){
      data=n;
      next=nullptr;
  }
};

void print(node *head){
  while(head){
    cout<<head->data<<" ";
    head=head->next;
  }
}

node *reversepair(node *head){
  node *curr=head;
  node *next=head->next;
  while(next){
    int t=curr->data;
    curr->data=next->data;
    next->data=t;
    curr=curr->next->next;
    next=next->next->next;
  }
  return head;
}

int main(){
  node *head =new node (10);
  head->next=new node(20);
  head->next->next=new node(30);
  head->next->next->next=new node(40);
  head->next->next->next->next=new node(50);
  head=reversepair(head); 
  print(head); 
  return 0;
}