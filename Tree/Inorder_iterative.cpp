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
  if(root==nullptr){
    return;
  }
  stack<node*> st;
  node* curr = root;
  while(curr!=nullptr || !st.empty()){
    while(curr!=nullptr){
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout<<curr->key<<" ";
    curr = curr->right;
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
  return 0; 
}