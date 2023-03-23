#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &a){
    int n=a.size();
    int max_ele=a[0];
    for(int i=1;i<n;i++){
        max_ele=max(max_ele,a[i]);
    }
    return max_ele;
}

//!!!! OR we can use vector library function '*max_element(a.begin(),a.end());'

// void print(vector<int> &a){
//     int n=a.size();
//     for (auto i:a) cout<<i<<" "; 
// }

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    cout<<"index is : "<<max_element(a.begin(),a.end())-a.begin()<<endl;
    cout<<largest(a);
    // print(a);
    return 0;
}