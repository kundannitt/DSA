#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a {2,8,30,15,25,12};
  // find ceil for each element for using elements in the left side.
  // ceil: - equal to or just greater element;
  // this method used lower_bound function of set or map(we can use either).
  set<int> st;
  
  for(int i=0;i<a.size();i++){
    if(st.lower_bound(a[i])==st.end()){
      cout<<-1<<" ";
    }else{
      cout<<*(st.lower_bound(a[i]))<<" ";
    }
    st.insert(a[i]);
  }
  return 0;
}