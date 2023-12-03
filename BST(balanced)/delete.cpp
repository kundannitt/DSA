#include <bits/stdc++.h>
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
// for printing: -
void bfs(node* root){
  if(root==nullptr){
    return;
  }
  queue<node*>q;
  q.push(root);
  while(q.empty()==false){
    node* curr = q.front();
    q.pop();
    cout<<curr->key<<" ";
    if(curr->left){
      q.push(curr->left);
    }
    if(curr->right){
      q.push(curr->right);
    }
  }
}

// when both left and right child are not empty:-
node* getSuccessor(node* curr){
  curr = curr->right;
  while(curr!=nullptr && curr->left!=nullptr){
    curr = curr->left;
  }
  return curr;
}

node* remove(node* root,int key){
  if(root == nullptr){
    return root;
  }
  if(root->key > key){
    root->left = remove(root->left,key);
  }else if(root->key < key){
    root->right = remove(root->right,key);
  }else{
    if(root->left == nullptr){ //left child is null
      node* temp = root->right;
      delete root;
      return temp;
    }else if(root->right == nullptr){//right child is null
      node* temp = root->left;
      delete root;
      return temp;
    }else{ // both child are not null
      node* successor = getSuccessor(root);
        root->key = successor->key;
        root->right = remove(root->right,successor->key); 
      }
    }
  return root;
}

int main(){
  node* root = new node(15);
  root->left = new node(5);
  root->left->left = new node(3);
  root->right = new node(20);
  root->right->left = new node(18);
  root->right->right = new node(80);
  root->right->left->left= new node(16);
  remove(root,20);
  bfs(root);
  return 0;
}