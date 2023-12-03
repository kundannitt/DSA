#include <bits/stdc++.h>
using namespace std;

void removeduplicates(vector<int>&a){
    int n=a.size();

    //nums.erase(unique(nums.begin(),nums.end()));// =>best method 

    vector<int> :: iterator it=unique(a.begin(),a.end()); // ok ok method 
    a.resize(distance(a.begin(),it));
}

void print(vector<int> &a){
    for (auto i:a){
        cout<<i<<" ";
    }
}

int main(){   
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    removeduplicates(a);
    print(a);
    return 0;
}