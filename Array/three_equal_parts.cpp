#include <bits/stdc++.h>
using namespace std;

bool threeparts(vector<int>a){
  int sum = accumulate(a.begin(),a.end(),0);
  if(sum % 3 !=0 ){
    return false;
  }
  // we have to check if there exist lsum and rsum such that lsum == rsum == sum - lsum -rsum
  int lsum = 0;
  int rsum = 0;
  //also we have to check if lsum is 0 and rsum is 0  and sum = 0 then is it 3 parts or 2 parts.
  int l_count = 0;
  int r_count = 0;
  for(int i=0;i<a.size();i++){
    if(lsum < sum/3){
      lsum += a[i];
      l_count++;
    }
    if(rsum < sum/3){
      rsum += a[a.size() - 1-i];
      r_count++;
    }
    if(lsum == rsum && rsum == sum - lsum - rsum && (l_count + r_count) != a.size()) {
      return true;
    }
  }
  return false;
}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(auto &i:a) cin>>i;
  cout<<threeparts(a);
  return 0;
}