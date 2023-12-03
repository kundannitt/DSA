#include<bits/stdc++.h>
using namespace std;

int editdistance(string s1,string s2,int m,int n){
  //base cases: -
  if(m == 0){
    //if m == 0 and n != 0 then we have to inset all the elements left in s2 to s1.
    return n;
  }
  if(n == 0){
    //if n ==0 and m!=0 then we have to delete extra characters from s1.
    return m;
  }
  if(s1[m-1] == s2[n-1]){ // when last char is matching
    return editdistance(s1,s2,m-1,n-1);
  }
  // when last char is not matching then we will try all three  possible combination of insert replace and remove.
  // and check which operation takes min operation.
  else{
    return 1 + min({editdistance(s1,s2,m,n-1), // insert operation. insert last char of s2 to s1 then match and remove last char from both.
                  editdistance(s1,s2,m-1,n), // delete operation. delete last char of s1. s2 remains same.
                  editdistance(s1,s2,m-1,n-1)}); // replace last char of s1 with last char of s2. and remove last char from both.
  }
}

int main(){
  string s1,s2;
  cin>>s1>>s2;
  cout<<editdistance(s1,s2,s1.size(),s2.size());
  return 0;
}