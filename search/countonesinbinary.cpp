#include <bits/stdc++.h>
using namespace std;

int firstoccur(vector<int> &a){
  int low=0;
  int high=a.size()-1;
  int n=a.size();
  while(low<=high){

    int mid=(low+high)/2;

    if(a[mid]==0){
      low=mid+1;
    }

    else{
      if(mid==0 || a[mid-1]!=a[mid]){
        return n-mid;
      }
      else{
        high=mid-1;
      }
    }
  }
  return -1;
}

int count(vector<int> &a){
  cout<<"first occur : "<<firstoccur(a)<<endl;
  return(firstoccur(a));
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    cout<<count(a);
    return 0;
}