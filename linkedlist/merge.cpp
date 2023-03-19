#include <bits/stdc++.h>
using namespace std;
struct node{
  int val;
  node *next;
  node(int n){
    val=n;
    next=NULL;
  }
};

void print(node *req){
  while(req){
    cout<<req->val<<" ";
    req=req->next;
  }
}

node* merge(node *head1, node *head2){

  node *at1=head1;
  node *at2=head2;
  
  node *ans=new node(1);
  node *end=ans;
  
  // temp1
  while(at1 && at2) {
    if ((at1->val)<=(at2->val)) {
      end->next=at1;
      end=end->next;

      at1=at1->next;
    } else {
      end->next=at2;
      end=end->next;

      at2=at2->next;
    }
  }

  if (at1) {
    end->next = at1;
  }

  if(at2) {
    end->next = at2;
  }
  
  return ans->next;
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
  
  node *n=new node(5);
  node *n1=new node(15);
  node *n2=new node(25);
  node *n3=new node(35);
  node *n4=new node(45);
  n->next=n1;
  n1->next=n2;
  n2->next=n3;
  n3->next=n4;
  node *mer=merge(head,n);
  print (mer);
  return 0;
}
