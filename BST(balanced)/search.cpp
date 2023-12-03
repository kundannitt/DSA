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

//iterative
bool search(node* root,int key){
  while(root!=nullptr){
    if(root->key == key){
      return true;
    }else if(root->key > key){
      root = root->left;
    }else{
      root = root->right;
    }
  }
  return false;
}



// // recursive
// bool search(node* root,int key){
//   if(root == nullptr){
//     return false;
//   }
//   if(root->key == key){
//     return true;
//   }
//   else if(root->key > key){
//     search(root->left,key);
//   }
//   else{
//     search(root->right,key);
//   }
// }

int main(){
  node* root = new node(15);
  root->left = new node(5);
  root->left->left = new node(3);
  root->right = new node(20);
  root->right->left = new node(18);
  root->right->right = new node(80);
  root->right->left->left= new node(16);
  cout<<search(root,16);
  return 0;
}