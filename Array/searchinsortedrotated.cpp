#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& a, int target) {
  int n=a.size();

  int low =0;
  int high=n-1;
  
  while(low<=high){
    int mid=(low+high)/2;
    if (a[mid]==target){
      return mid;
    }
    if (a[mid]>=a[low]){
      if(a[low]<=target && target<a[mid]){
        high=mid-1;
      }else{
        low=mid+1;
      }
    }else{
      if(a[high]>=target && target>a[mid]){
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
  }
  return -1;
}

int main(void){
  int n;
  cin>>n;
  vector<int> a(n);
  cout<<"Enter a sorted rotated array : "<<endl;
  for(auto &i:a)cin>>i;
  int target;
  cin>>target;
  cout<<search(a,target);
  return 0;
}