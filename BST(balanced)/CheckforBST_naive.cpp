//If the tree is balanced BST then its inorder traversal will be sorted in increasing order.
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

vector<int> temp;

void inorder(node* root){
  if(root == nullptr) return;
  inorder(root->left);
  temp.push_back(root->key);
  inorder(root->right);
}

bool checkforBST(vector<int> temp){
  for(int i=1;i<temp.size();i++){
    if(temp[i-1]>temp[i]){
      return false;
    }
  }
  return true;
}

int main(){
  node* root = new node(80);
  root->left = new node(70);
  root->left->left = new node(60);
  root->left->right = new node(75);
  root->right = new node(90);
  root->right->left = new node(85);
  root->right->right = new node(100);
  inorder(root); 
  cout<<checkforBST(temp);
  return 0;
}