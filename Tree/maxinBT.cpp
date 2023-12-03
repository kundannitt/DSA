#include <bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node *left;
  node *right;
  node(int n){
    key = n;
    left = right = nullptr;
  }
};

int maxvalue(node* root){
  if(root==nullptr){
    return INT_MIN;
  }
  else
    return max(root->key,max(maxvalue(root->left),maxvalue(root->right)));
}

int main(){
  node *root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(40);
  root->left->right = new node(50);
  root->left->right->left = new node(70);
  root->left->right->right = new node(80);
  root->right->right = new node(60);
  cout<<"The max value of the binary tree is : "<<maxvalue(root);
  return 0; 
}