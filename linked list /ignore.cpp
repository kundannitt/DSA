#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int n)
    {
        data=n;
        next=NULL;
    }
};

void printlist(node *head) //recursive approach
{
    if (head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    printlist(head->next);
}

int main()
{
    node *head;
    node *temp=head;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        temp=new node(x);
        temp=temp->next;
    }

    printlist(head);


}