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

void leftview(node* root){
  if(root==nullptr){
    return;
  }
  cout<<root->key<<" ";
  if(root->left){
    leftview(root->left);
  }else{
    leftview(root->right);
  }
}

// int main(){
//   node *root = new node(10);
//   root->left = new node(20);
//   root->right = new node(30);
//   root->left->left = new node(40);
//   root->left->right = new node(50);
//   root->left->right->left = new node(70);
//   root->left->right->right = new node(80);
//   root->right->right = new node(60);
//   leftview(root);
//   return 0; 
// }

int main(){
  node* root = new node(30);
  root->right = new node(50);
  root->right->left = new node(60);
  root->right->left->right = new node(10);
  leftview(root);
  return 0;
}