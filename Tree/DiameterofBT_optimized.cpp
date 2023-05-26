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

int res = 0;

int height(node* root){
  if(root == nullptr){
    return 0;
  }
  int lh = height(root->left);
  int rh = height(root->right);
  res = max(res,(lh+rh+1));
  return 1+max(lh,rh); // return height of the BT.
}

int main(){
  node *root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  // root->left->left = new node(40);
  // root->left->right = new node(50);
  // root->left->right->left = new node(70);
  // root->left->right->right = new node(80);
  root->right->left = new node(40);
  root->right->left->left = new node(50);
  root->right->right = new node(60);
  root->right->right->right = new node(70);
  height(root);
  int diameter = res;
  cout<<diameter;
  return 0; 
}