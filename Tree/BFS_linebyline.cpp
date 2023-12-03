#include <bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node* left;
  node* right;
  node(int n){
    key = n;
    left = right =nullptr;
  }
};

void printlevelorderline(node* root){
  if(root == nullptr){
    return;
  }

  queue<node*> q;
  q.push(root);
  while(q.empty()==false){
    int size = q.size(); // after completing every level break the line.
    
    for(int i=0;i<size;i++){
      node* curr = q.front();
      q.pop();
      cout<<curr->key<<" ";
      if(curr->left){
        q.push(curr->left);
      }
      if(curr->right){
        q.push(curr->right);
      }
    }
    cout<<endl;
  }
}

int main(){
  node* root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(40);
  root->left->right = new node(50);
  root->right->left = new node(60);
  root->right->right = new node(70);
  printlevelorderline(root);
  return 0; 
}

//time = theta(n);
// space = at any time at most one level of tree is in queue.