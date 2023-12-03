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

int size(node* root){
  if(root==nullptr){
    return 0;
  }
  else
    return 1 + size(root->left) + size(root->right);
}

int main(){
  // node *root = new node(10);
  // root->left = new node(20);
  // root->right = new node(30);
  // root->left->left = new node(40);
  // root->left->right = new node(50);
  // root->left->right->left = new node(70);
  // root->left->right->right = new node(80);
  // root->right->right = new node(60);
  node* root = new node(2);
  root->left = new node(2);
  root->right = new node(2);
  cout<<"The size of the binary tree is : "<<size(root);
  return 0; 
}