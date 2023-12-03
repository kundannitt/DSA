#include <bits/stdc++.h>
using namespace std;


int search(vector<int> &a,int low,int high,int key){
    if(low>high){
      return -1;
    }
    int mid=(low+high)/2;
    if(a[mid]==key){
      return mid;
    }else if(a[mid]>key){
      return search(a,low,mid-1,key);
    }else{
      return search(a,mid+1,high,key);
    }
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for (auto &i:a) cin>>i;
  int key;
  cin>>key;
  cout<<search(a,0,n-1,key);
  return 0;
}