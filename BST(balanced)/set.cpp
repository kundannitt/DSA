#include <bits/stdc++.h>
using namespace std;
int main(){
  set<int>st;
  st.insert(11);
  st.insert(91);
  st.insert(6);
  st.insert(21);
  st.insert(15);
  //iteration techniques: -
  /*
  1.
  for(auto it:st){
    cout<<it<<" ";
  }
  2.
  for(auto it=st.begin();it!=st.end();it++){
    cout<<(*it)<<" ";
  }
  */
  if(st.find(6)!=st.end()){
    cout<<"found"<<endl;
  }else{
    cout<<"not found\n";
  }
  //lower bound => returns elemnet if found else returns next greater
  auto it = st.lower_bound(11);
  cout<<*it<<endl;
  //upper bound

  auto i = st.upper_bound(11); // even if element is present returns next greater
  cout<<*i<<endl;

  if(it == i ){
    cout<<"Element is not present"<<endl;
  }else{
    cout<<"Element is present"<<endl;
  }
  return 0;
}