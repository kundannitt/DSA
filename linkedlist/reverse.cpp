#include <bits/stdc++.h>
using namespace std;
struct node{
  int val;
  node *next;
  node(int n){
      val=n;
      next=nullptr;
  }
};

void print(node* head){
  while(head){
    cout<<head->val<<" ";
    head=head->next;
  }
}

node* reverse(node *head){
  node *curr=head;
  node *prev=nullptr;

  while(curr){
    node *next=curr->next; // store the next value of curr. 20->30->40->50
    curr->next=prev; // eg 10->20->30->40->50 to prev<-10 , 20->30->40->50
    prev=curr; //move previous ahead
    curr=next;// move curr ahead
  }
  return prev;
}

int main(){
  node *head=new node(10);
  node *temp1=new node(20);
  node *temp2=new node(30);
  node *temp3=new node(40);
  node *temp4=new node(50);
  head->next=temp1;
  temp1->next=temp2;
  temp2->next=temp3;
  temp3->next=temp4;
  head=reverse(head);
  print(head);
  return 0;

}