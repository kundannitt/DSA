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

int MaxWidth(node* root){
  if(root == nullptr){
    return 0;
  }
  int ans = INT_MIN;
  queue<node*> q;
  q.push(root);
  while(q.empty()==false){
    ans = max(ans,(int)q.size());
    for(int i=0;i<ans;i++){
      node* curr = q.front();
      q.pop();
      if(curr->left){
        q.push(curr->left);
      }
      if(curr->right){
        q.push(curr->right);
      }
    }
  }
  return ans;
}

int main(){
  node* root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(40);
  root->left->right = new node(50);
  root->right->left = new node(60);
  // root->right->right = new node(70);
  cout<<"The maximum width of the Binary Tree is "<<MaxWidth(root);
  return 0; 
}
