// get height of the tree.
// print all the nodes from height 0 to heigth to tree.
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

int height(node* root){
  if(root == nullptr){
    return 0;
  }
  else
    return max(height(root->left),height(root->right))+1;
}

void nodesatdistanceK(node* root,int k){
  if(root == nullptr){
    return;
  }
  if(k == 1){
    cout<<root->key<<" ";
  }
  else{
    nodesatdistanceK(root->left,k-1);
    nodesatdistanceK(root->right,k-1);
  }
}

void bfs(node* root){
  if(root == nullptr){
    return;
  }
  int x = height(root);
  cout<<"height is "<<x<<" ";
  for(int i=0;i<=x;i++){
    nodesatdistanceK(root,i);
  }
}

int main(){
  node* root = new node(10);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(40);
  root->left->right = new node(50);
  root->right->left = new node(60);
  root->right->right = new node(70);
  bfs(root);
  return 0;
}