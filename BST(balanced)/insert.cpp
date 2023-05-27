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

void bfs(node* root){
  if(root == nullptr){
    return;
  }
  queue<node*> q;
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

//iterative
node* insert(node* root,int key){
  while(root!=nullptr){
    if(root->key > key){
      if(root->left==nullptr){
        root->left = new node(key);
        return root;
      }else{
        root = root->left;
      }
    }else if(root->key < key){
      if(root->right == nullptr){
        root->right = new node(key);
        return root;
      }else{
      root = root->right;
      }
    }
  }
  return root;
}

/*
//recursive
node* insert(node* root, int key){
  if(root == nullptr){
    root = new node(key);
  }else if(root->key > key){
    root->left = insert(root->left,key);
  }else if(root->key < key){
    root->right = insert(root->right,key);
  }
  return root;
}
*/


int main(){
  node* root = new node(15);
  root->left = new node(5);
  root->left->left = new node(3);
  root->right = new node(20);
  root->right->left = new node(18);
  root->right->right = new node(80);
  root->right->left->left= new node(16);
  insert(root,17);
  bfs(root);
  return 0;
}