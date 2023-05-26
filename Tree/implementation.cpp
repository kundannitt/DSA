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

void inorder(node* root){
  if(root!=nullptr){
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
  }
}

void preorder(node* root){
  if(root!=nullptr){
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(node* root){
  if(root!=nullptr){
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
  }
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
  inorder(root);
  cout<<endl;
  preorder(root);
  cout<<endl;
  postorder(root);
  return 0; 
}