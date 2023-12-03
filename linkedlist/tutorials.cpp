#include<bits/stdc++.h>
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

// void printlist(node *head) //iterative approach
// {
//     while(head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }
// }

void printlist(node *head) //recursive approach
{
    if (head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    printlist(head->next);
}

node *insertbegin(node *head, int n)
{
    node *temp=new node (n);
    temp->next=head;
    return temp;  // return temp because temp is our new head(or starting element).
}

node *insertend(node *head, int n) 
{
    node *temp=new node(n); //allocating in memoery
    if (head==NULL) // list is initially empty
    {
        head=temp;
        return temp;
    }
    node *temp2=head; // we get last last element.

    while(temp2->next!=NULL) // we know that last element->next =NULL
    {
        temp2=temp2->next;
    }
    temp2->next=temp; // allocating temp as last element 
    temp->next=NULL; // allocating last element next as NULL;
    return head; // return head as it is because head doesn't changed in the whole operation.
}

node *deletebegin(node *head) // for deleting first element in the list we just need to make second element as head.
{
    if (head==NULL) //empty list
    {
        return NULL;
    }
    if (head->next==NULL) //only one element 
    {
        return NULL;
    }
    head=head->next;
    return head;
}

node *deleteend(node *head)
{
    node *temp=head;
    while(temp->next->next!=NULL) // it will give second last element from the list
    {
        temp=temp->next;
    }

    temp->next=NULL; //alloting last element as NULL
    delete temp->next; //(optional) deleting last element from memory 
    return head;
}

node *insert(node *head, int pos, int val)
{
    node *temp=head;
    node *temp2=head->next;
    pos-=2;
    while(pos--)
    {
        temp=temp->next;
        temp2=temp2->next;
    }
    node *temp3=new node (val);
    temp->next=temp3;
    temp3->next=temp2;
    return head;

}

int main()
{
    node *head =new node (10);
    head->next=new node(20);
    head->next->next=new node(30);
//-----------------------------------------------------------------------//

    head=insertbegin(head,10);
    head=insertbegin(head,5);
//-----------------------------------------------------------------------//

    head=insertend(head,40);
    head=insertend(head,50);

//-----------------------------------------------------------------------//    

    head=deletebegin(head); //removing one element from the beginning

//-----------------------------------------------------------------------//

    head=deleteend(head); //removing one element from back

//-----------------------------------------------------------------------//    

    //head=insert(head,2,300);
    printlist(head);
    return 0;
}