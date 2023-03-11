// we are checking if the array can be divided into 3 parts of equal sum
#include <bits/stdc++.h>
using namespace std;

// void print(vector<int> &a){
//     int n=a.size();
//     for (auto i:a) cout<<i<<" "; 
// }

bool is3equal(vector<int>&a){
    if (a.size()<3){
        return -1;
    }

    int n=a.size();
    int lsum=a[0];
    int rsum=a[n-1];
    int sum=accumulate(a.begin(),a.end(),0) - lsum - rsum ;

    for (int i=1;i<a.size()-1;i++){
        if(lsum>rsum){
            rsum+=a[n-1-i];
            sum-=a[n-1-i];
        }
        else if (lsum<rsum){
            lsum+=a[i];
            sum-=a[i];
        }
        else{
            if (sum==lsum && lsum==rsum){
            return true;
            }
            lsum+=a[i];
            rsum+=a[n-1-i];
            sum=sum-a[i]-a[n-1-i];
        }
        
        if (lsum>sum || rsum>sum){
            return false;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    cout<<is3equal(a);
    // print(a);
    return 0;
}