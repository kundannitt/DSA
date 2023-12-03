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

vector<int> inordr; // for method1
unordered_set<int>st; // for method2

void method1(node* root){
  if(root != nullptr){
    method1(root->left);
    inordr.push_back(root->key);
    method1(root->right);  
  }
}

bool check(int sum){
  int low = 0 ;
  int high = inordr.size();
  while(low < high){
    if(inordr[low]+inordr[high]==sum){
      return true;
    }else if(inordr[low]+inordr[high]>sum){
      high--;
    }else{
      low++;
    }
  }
  return false;
}

bool method2(node* root,int sum){
  if(root == nullptr){
    return false;
  }
  if(method2(root->left,sum)==true){
    return true;
  }
  if(st.find(sum - root->key) != st.end()){
    return true;
  }
  else
    st.insert(root->key);
  return method2(root->right,sum);
}

int main(){
  node* root = new node(10);
  root->left = new node(8);
  root->left->left = new node(4);
  root->left->right = new node(9);
  root->right = new node(20);
  root->right->left = new node(11);
  root->right->right = new node(30);
  root->right->right->left = new node(25);
  int sum;
  cout<<"Enter the sum of the pair : ";
  cin>>sum;

  method1(root);
  cout<<"from mehtod1 : "<<check(sum);

  cout<<endl<<"from method2 : "<<method2(root,sum);
  /*
  Method 1:- do inorder traversal and store the values in array and use two pointer
             to get the pair.
  Method 2:- store the values in hashmap while traversing and if we get a pair return true;
  */
  return 0;
}