#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int n)
    {
        data=n;
        next=nullptr;
    }
};

void print(node *head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

bool search(node *head, int t)
{
    while(head!=nullptr)
    {
        if (head->data==t)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}

int main()
{
    node *head=nullptr;
    node *temp;

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        if (head==nullptr)
        {
            head=new node(x);
            temp=head;
        }
        else{
            temp->next=new node(x);
            temp=temp->next;
        }
    }
    int t;
    cin>>t;
    cout<<search(head,t)<<endl;
    print(head);
    return 0;
}