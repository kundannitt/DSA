#include<bits/stdc++.h>
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

node* pre = nullptr;
node* first = nullptr;
node* second = nullptr;

void fixBST(node* root){
  if(root == nullptr){
    return;
  }
  fixBST(root->left);
  if(pre!=nullptr && root->key < pre->key){
    if(first == nullptr){
      first = pre;
    }
    second = root;
  }
  pre = root;
  fixBST(root->right);
}

int main(){
  node* root = new node(80);
  root->left = new node(70);
  root->left->left = new node(60);
  root->left->right = new node(75);
  root->right = new node(90);
  root->right->left = new node(85);
  root->right->right = new node(100);
  fixBST(root);
  return 0;
}