#include <bits/stdc++.h>
using namespace std;

// void print(vector<int> &a){
//     int n=a.size();
//     for (auto i:a) cout<<i<<" "; 
// }

int search(vector<int> &a, int key){
    for(int i=0;i<a.size();i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    int key;
    cin>>key;
    cout<<search(a,key);
    // print(a);
    return 0;
}