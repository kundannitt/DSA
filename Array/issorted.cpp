#include <bits/stdc++.h>
using namespace std;

bool issorted(vector<int> &a){
  int n=a.size();
  for(int i=1;i<n;i++){
    if (a[i-1]>a[i])
        return false;
  }
  return true;
}

// void print(vector<int> &a){
//     int n=a.size();
//     for (auto i:a) cout<<i<<" "; 
// }

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    cout<<issorted(a);
    // print(a);
    return 0;
}