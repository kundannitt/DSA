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

int diameter(node* root,int &res){
  if(root == nullptr){
    return 0;
  }
  int l = diameter(root->left,res);
  int r = diameter(root->right,res);
  int ans = 0;
  int temp = max(l,r) + 1;// curr node is not max, so it will pass the max res including self so +1
  int ans = max(temp,1+l+r);// curr node gives max diamater.
  res = max(res,ans);
  return temp;
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
  int res = INT_MIN;
  cout<<diameter(root,res);
  return 0;
}