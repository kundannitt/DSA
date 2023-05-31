// Greater than or equal to the given key.
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

node* ceil(node* root,int key){
  node* ans = nullptr;
  while(root!=nullptr){
    if(root->key == key){
      ans = root;
      return ans;
    }
    else if(root->key > key){
      ans = root;
      root = root->left;
    }else{
      root = root->right;
    }
  }
  return ans;
}
int main(){
  node* root = new node(50);
  root->left = new node(30);
  root->left->left = new node(20);
  root->left->right = new node(40);
  root->right = new node(70);
  root->right->left = new node(60);
  root->right->right = new node(80);
  root->right->left->left= new node(55);
  root->right->left->right= new node(65);
  cout<<ceil(root,54)->key;
  return 0;
}