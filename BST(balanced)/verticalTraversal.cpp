// study verticalSum.cpp for referral.
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

void vSumR(node* root,int index,map<int,vector<int>> &mp){
  if(root == nullptr){
    return;
  }
  vSumR(root->left,index-1,mp);
  mp[index].push_back(root->key);
  vSumR(root->right,index+1,mp);
}

void vSum(node* root){
  map<int,vector<int>> mp;
  vSumR(root,0,mp); // setting root index as 0;
  for(auto i:mp){
    for(auto j:i.second){
      cout<<j<<" ";
    }
    cout<<endl;
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