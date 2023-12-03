//Closest smaller or equal element.
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

node* floor(node* root,int key){
  node* ans = nullptr;

  while(root!=nullptr){
    if(root->key == key){
      return root;
    }else if(root->key > key){
      root = root->left;
    }else{
      ans = root;
      root = root->right;
    }
  }
  return ans;
}

/*
//recursive(takes aux space also)
int res;
void floor(node* root,int key){
  if (root == nullptr){
    return;
  }
  if(root->key == key){
    res = root->key;
    return;
  }else if(root->key > key){
    floor(root->left,key);
  }else{
    res = root->key;
    floor(root->right,key);
  }
}
*/


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
  cout<<floor(root,66)->key;
  // cout<<res;
  return 0;
}