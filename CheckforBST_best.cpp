#include <bits/stdc++.h>
using namespace std;
int pre = INT_MIN;

struct node{
  int key;
  node* left;
  node* right;
  node(int n){
    key = n;
    left = right = nullptr;
  }
};


bool checkforBST(node* root){
  if(root == nullptr){
    return true;
  }
  if(checkforBST(root->left)==false){
    return false;
  }
  if(root->key <= pre){
    return false;
  }
  pre = root->key;
  return checkforBST(root->right); 
  /*
  or we can write: -
  if(checkforBST(root->right)==false){
    return false;
  }
  
  */
}
int main(){
  node* root = new node(80);
  root->left = new node(70);
  root->left->left = new node(60);
  root->left->right = new node(75);
  root->right = new node(90);
  root->right->left = new node(79);
  root->right->right = new node(100);
  cout<<checkforBST(root); // using inorder traversal.
  return 0;
}