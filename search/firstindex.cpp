#include <bits/stdc++.h>
using namespace std;


int search(vector<int> &a, int key){
    int low=0;
    int high=a.size()-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>key){
            high=mid-1;
        }
        else if (a[mid]<key){
            low=mid+1;
        }
        else{
          if(mid==0 || a[mid-1]!=a[mid]){
            return mid;
          }
          else{
            high=mid-1;
          }
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
    return 0;
}