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

void vSumR(node* root,int index,map<int,vector<int>>&mp){
  if(root == nullptr){
    return;
  }
  vSumR(root->left,index-1,mp);
  mp[index].push_back(root->key);
  vSumR(root->right,index+1,mp);
}

void vSum(node* root){
  map<int,vector<int>>mp;
  vSumR(root,0,mp);

  for(auto i:mp){
    cout<<*min_element(i.second.begin(),i.second.end())<<endl;
  }
}
int main(){
  node* root = new node(10);
  root->left = new node(20);
  root->left->left = new node(30);
  root->left->right = new node(40);
  root->right = new node(50);
  root->right->left = new node(60);
  vSum(root);
  return 0;
}