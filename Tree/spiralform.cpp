// first level in left to right
// second level right to left and so on.
#include <bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node* left;
  node* right;
  node(int n){
    key = n;
    left = right =nullptr;
  }
};

vector<int> spiralform(node* root){
  if(root==nullptr){
    return {};
  }
  vector<int> ans;
  queue<node*> q;
  q.push(root);
  int flag = 0;
  while(q.empty()==false){
    vector<int> temp;
    int size = q.size();
    for(int i=0;i<size;i++){
      node* curr = q.front();
      q.pop();
      temp.push_back(curr->key);
      if(curr->left){
        q.push(curr->left);
      }
      if(curr->right){
        q.push(curr->right);
      }
    }
    if(flag%2 == 0){
      ans.insert(ans.end(),temp.begin(),temp.end());
    }else{
      reverse(temp.begin(),temp.end());
      ans.insert(ans.end(),temp.begin(),temp.end());
    }
    flag++;
  }
  return ans;
}
void print(vector<int> ans){
  for(auto i:ans){
    cout<<i<<" ";
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
  root->left->left->left = new node(80);
  root->left->left->right = new node(90);
  root->right->left->left = new node(100);
  vector<int> ans = spiralform(root);
  print(ans);
  return 0; 
}

//time = theta(n);
// space = at any time at most one level of tree is in queue.