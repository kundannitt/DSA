#include <bits/stdc++.h>
using namespace std;

int maxcount(vector<int> &a){
    int n=a.size();
    int count=0;
    int res=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]==1){
            count++;
            res=max(res,count);
        }
        else{
            count=0;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    cout<<maxcount(a);
    return 0;   
}