#include <bits/stdc++.h>
using namespace std;

int squareroot(int n){
  int low=1;
  int high=n;
  int ans=-1;

  while(low<=high){

    int mid=low+(high-low)/2;
    int x=mid*mid;

    if (x==n){
      return mid;
    }
    else if(x>n){
      high=mid-1;
    }
    else{
      low=mid+1;
      ans=mid;
    }
  }
  return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<squareroot(n);
    return 0;
}