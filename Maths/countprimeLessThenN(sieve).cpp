#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
  vector<int> isprime(n+1,true);
  int count=0;

  for(long long  i=2;i<n;i++){
    if(isprime[i]){
      count++;
      for(long long  j=i*i;j<n;j=j+i){
        isprime[j]=false;
      }
    }
  }
  return count;
}

int main(){
  int n;
  cin>>n;
  cout<<countPrimes(n);
  return 0;
}
