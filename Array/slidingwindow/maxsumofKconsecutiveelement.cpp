#include <bits/stdc++.h>
using namespace std;

// void print(vector<int> &a){
//     int n=a.size();
//     for (auto i:a) cout<<i<<" "; 
// }

int maxsum(vector<int> &a, int k){
    int curr_sum=0;
    for (int  i=0;i<k;i++){
        curr_sum+=a[i];
    }

    int max_sum=curr_sum;

    for (int i=k;i<a.size();i++){
        curr_sum=curr_sum+a[i]-a[i-k];
        max_sum=max(max_sum,curr_sum);
       
    }
    return max_sum;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    int k;
    cin>>k;
    cout<<maxsum(a,k);
    // print(a);
    return 0;
}