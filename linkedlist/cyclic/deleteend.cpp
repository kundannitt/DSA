//go to the 2nd last element and put next as head.
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

node *deleteend(node *head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node *temp=head->next;
    node *temp2=head;
    while(temp->next->next!=head){ // since circular.
        temp=temp->next;
        temp2=temp2->next;
    }
    temp->next=head;

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
    head=deleteend(head);
    print(head);
    return 0;
}

/*
input : 10 20 30 40 
output: 20 30 40 
*/