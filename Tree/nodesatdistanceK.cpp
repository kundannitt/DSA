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
void nodesatdistanceK(node* root,int k){
  if(root==nullptr){
    return;
  }
  if(k==0){
    cout<<root->key<<" ";
  }else{
    nodesatdistanceK(root->left,k-1);
    nodesatdistanceK(root->right,k-1);
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
  int k;
  cin>>k;
  nodesatdistanceK(root,k);
  return 0;
}