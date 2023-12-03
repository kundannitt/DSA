//the last node points to the head.
#include <bits/stdc++.h>
using namespace std;
struct node{
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
    node *temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);

}


int main(){
    node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    node *temp3=new node(40);

    head->prev=temp3;

    head->next=temp1;
    temp1->prev=head;

    temp1->next=temp2;
    temp2->prev=temp1;

    temp2->next=temp3;
    temp3->prev=temp2;

    temp3->next=head;
  
    print(head);
    return 0;
}