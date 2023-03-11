#include <bits/stdc++.h>
using namespace std;

int secondlargest(vector<int> &a){
    int n=a.size();
    int largest=a[0];
    int maxindex=0;
    for (int i=1;i<n;i++){
        if(a[i]>largest){
            largest=a[i];
            maxindex=i;
        }
    }

    int nextlargest=INT_MIN;
    for (int i=0;i<n;i++){
        if(i!=maxindex){
            if(a[i]>nextlargest){
                nextlargest=a[i];
            }
        }
    }
    return nextlargest;
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
    cout<<secondlargest(a);
    // print(a);
    return 0;
}