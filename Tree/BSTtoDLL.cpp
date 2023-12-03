#include <bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node* left;
  node* right;
  node(int n){
    key = n;
    left = right = nullptr;
  }
};

node* prev = nullptr;

node* BSTtoDLL(node* root){
  if(root==nullptr){
    return root;
  }
  node* head = BSTtoDLL(root->left); // because left part of the BST is going to be the head;
  if(prev == nullptr){
    head = root;
  }else{
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  BSTtoDLL(root->right);
  return head;
}

int main(){
  node* root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(40);
  root->left->right = new node(50);
  root->right->left = new node(60);
  root->right->right = new node(70);
  BSTtoDLL(root);
  return 0;
}