#include <bits/stdc++.h>
using namespace std;

int count(vector<int>&a){
    int n=a.size();
    int count=0;
    int res=0;
    for (int i = 1 ; i < n ; i++){
        if ((a[i]%2==0 && a[i-1]%2!=0) || a[i]%2!=0 && a[i-1]%2==0){
            count++;
            res=max(res,count);
        }
        else{
            count=1;
        }
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
    cout<<count(a);
    // print(a);
    return 0;
}