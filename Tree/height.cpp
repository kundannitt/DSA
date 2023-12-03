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

int height(node* root){
  if(root==nullptr){
    return 0;
  }
  else
    return max(height(root->left),height(root->right))+1;
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
  cout<<"The height of the binary tree is : "<<height(root);
  return 0; 
}