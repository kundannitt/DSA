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

bool CSP(node* root){
  if(root==nullptr){
    return 1;
  }
  if(root->left ==nullptr && root->right == nullptr){
    return true;
  }
  int sum = 0;
  if(root->left){
    sum += root->left->key;
  } 
  if(root->right){
    sum += root->right->key;
  }
  return (root->key == sum && CSP(root->left) && CSP(root->right));
}

int main(){
  node *root = new node(20);
  root->left = new node(10);
  root->right = new node(13);
  root->left->left = new node(4);
  root->left->right = new node(6);
  root->right->left = new node(2);
  root->right->right = new node(8);
  cout<<CSP(root); //Children Sum Property:- sum of child should be equal to its parents. whether only one child exist.
  return 0; 
}