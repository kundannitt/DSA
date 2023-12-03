// occur more than n/2 times in an array
#include <bits/stdc++.h>
using namespace std;
//using array finding majority element is hard so we will use hashmap
int majority(vector<int> &a){
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++){
        mp[a[i]]++;
    }
    int flag=0; // to check if the majority element existed or not.
    for (auto i:mp){
        if (i.second>a.size()/2){
            return i.first;
        }
    }
    return -1; // not exist
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
    cout<<majority(a);
    // print(a);
    return 0;
}