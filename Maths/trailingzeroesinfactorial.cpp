#include <iostream>
using namespace std;

int trailingzeroes(int n){
  int res=0;
  for(int i=5;i<=n;i=i*5){
    res+=n/i;
  }
  return res;
}

int main(){
  int n;
  cout<<"Enter a number : ";
  cin>>n;
  cout<<trailingzeroes(n);
  return 0;
}
