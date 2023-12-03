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

int isBalanced(node* root){
  if(root == nullptr){
    return false;
  }
  int lh = isBalanced(root->left);
  if(lh == -1){
    return false;
  }
  int rh = isBalanced(root->right);
  if(rh == -1){
    return false;
  }
  if(abs(lh-rh)>1){
   return false;
  }else{
    return max(lh,rh)+1;
  }
}

int main(){
  node *root = new node(3);
  root->left = new node(4);
  root->right = new node(8);
  root->left->left = new node(5);
  root->left->right = new node(9);
  root->right->right = new node(7);
  root->right->right->left = new node(7);
  cout<<isBalanced(root);
  return 0; 
}