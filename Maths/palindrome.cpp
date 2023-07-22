#include <bits/stdc++.h>
using namespace std;

void checkpalindrome(int t){
  int x=t;
  int y=0;
  while(t>0){
  y=y*10+t%10;
  t=t/10;
  }

  if (x==y){
    cout<<"Yes";
  }else{
    cout<<"NO"<<y;
  }
}

int main()
{
  int n;
  cout<<"Enter a number : ";
  cin>>n;
  checkpalindrome(n);
  return 0;
}
