#include <iostream>
using namespace std;

int gcd(int n, int m){
  if (m==0)
  return n;
  else return gcd(m,n%m);
}

int main(){
  int n,m;
  cout<<"Enter two numbers : ";
  cin>>n>>m;
  cout<<gcd(m,n);
  return 0;
}
