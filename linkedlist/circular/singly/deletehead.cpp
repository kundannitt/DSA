//the last node points to the head =>cyclic 
// if we delete the head directly then it will lose it cycle.
// so we first copy the val of head->next to head and then delete the 2nd node.
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

node *deletehead(node *head){
    if(head==nullptr){ //null list
        return nullptr;
    }
    if (head->next==nullptr){ //only one element
        delete head;
        return  nullptr;
    }

    head->data=head->next->data ; //copying the data of 2nd element to head.

    node *temp=head->next;
    head->next=head->next->next;
    delete temp;
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
    head=deletehead(head);
    print(head);
    return 0;
}

/*
input : 10 20 30 40 
output: 20 30 40 
*/

