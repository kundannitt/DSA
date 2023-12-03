// study from notebook.
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

void vSumR(node* root,int index,map<int,int> &mp){
  if(root == nullptr){
    return;
  }
  vSumR(root->left,index-1,mp);
  mp[index]+=root->key;
  vSumR(root->right,index+1,mp);
}

void vSum(node* root){
  map<int,int> mp;
  vSumR(root,0,mp); // setting root index as 0;
  for(auto i:mp){
    cout<<i.second<<" ";
  }
}

int main(){
  node* root = new node(10);
  root->left = new node(15);
  root->left->left = new node(35);
  root->left->right = new node(20);
  root->left->right->right = new node(75);
  root->left->right->right->right = new node(80);
  root->left->left->left = new node(40);
  root->right = new node(25);
  vSum(root);
  return 0;
}