// max value of a[j]-a[i] such that j>i;
#include <bits/stdc++.h>
using namespace std;

int maxdiff(vector<int> &a){
    int n=a.size();
    int res=a[1]-a[0];
    int minval=a[0];
    for (int i=1;i<n;i++){
        res=max(res,a[i]-minval);
        minval=min(minval,a[i]);
    }
    return res;
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
    cout<<maxdiff(a);
    // print(a);
    return 0;
}