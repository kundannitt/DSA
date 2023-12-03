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

int countNodes(node* root){
  if(root == nullptr){
    return 0;
  }
  node* curr = root;
  int lh,rh;
  while(curr != nullptr){
    curr = curr->left;
    lh++;
  }
  curr = root;
  while(curr != nullptr){
    curr = curr->right;
    rh++;
  }
  if(lh == rh){
    return pow(2,lh) - 1;
  }
  else
    return 1 + countNodes(root->left) + countNodes(root->right); 
  
}

int main(){
  node *root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(40);
  root->left->right = new node(50);
  root->left->right->left = new node(70);
  root->left->right->right = new node(80);
  // root->right->right = new node(60);
  cout<<countNodes(root)<<" ";
  return 0; 
}