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

void preorder(node* root){
  stack<node*> st;
  st.push(root);
  while(!st.empty()){
    node* curr = st.top();
    st.pop();
    cout<<curr->key<<" ";
    if(curr->right){
      st.push(curr->right);
    }
    if(curr->left){
      st.push(curr->left);
    }
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
  preorder(root);
  return 0; 
}