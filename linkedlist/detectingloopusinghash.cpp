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
  unordered_set<node*>st;
  node *temp=head;
  while(temp){
    if(st.find(temp)!=st.end()){
      return true;
    }
    st.insert(temp);
    temp=temp->next;
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