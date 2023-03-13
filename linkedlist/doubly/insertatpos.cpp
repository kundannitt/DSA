#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
    node(int n){
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

node *insertatpos(node *head,int pos, int val){
    pos=pos-2;
    // we need a pointer to the previous element of the pos and next element of the pos.
    node *temp1=head;
    node *temp2=head->next->next;
    while(pos--){
        temp1=temp1->next;
        temp2=temp2->next;
    }

    node *temp=new node(val);
    temp1->next=temp;
    temp->prev=temp1;
    temp->next=temp2;
    temp2->prev=temp;
    
    return head;

}

int main(){
    node  *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    node *temp3=new node(40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;

    temp1->prev=head;
    temp2->prev=temp1;
    temp3->prev=temp2;

    head=insertatpos(head,2,500);
    print(head);

    return 0;
}