#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &a){
    int n=a.size();
    for (auto i:a) cout<<i<<" "; 
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;

    print(a);
    return 0;
}