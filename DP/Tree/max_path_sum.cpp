#include<bits/stdc++.h>
using namespace std;
struct node{
  int val;
  node* left;
  node* right;
  node(int n){
    val = n;
    left = nullptr;
    right = nullptr;
  }
};

int solve(node* root,int &res){
  if(root == nullptr){
    return 0;
  }
  int l = solve(root->left,res);
  int r = solve(root->right,res);
  int ans = 0;
  int temp = max(max(l,r)+root->val,root->val); // since(max(l,r)) can be -ve.we take max only.
  int ans = max(temp,l+r+root->val); // take curr node as answer. take answer calculated from left and right and add curr node->val.
  res = max(res,ans);
  return temp;
}

void maxpathsum(node* root){
  int res = INT_MIN;
  solve(root,res);
  cout<<res;
}

int main (){
  node* root = new node(10);
  root->left = new node(9);
  root->right = new node(11);
  root->left->left = new node(7);
  root->left->right = new node(8);
  root->left->left->left = new node(4);
  root->left->left->right = new node(6);
  root->right->left = new node(9);
  root->right->right = new node(12);
  maxpathsum(root);
  return 0;
}