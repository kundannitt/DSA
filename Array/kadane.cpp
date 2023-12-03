#include <bits/stdc++.h>
using namespace std;

int maxsumsubarray(vector<int> &a){
    int n=a.size();
    int maxsofar=a[0];
    int res=a[0];
    for (int i=1;i<n;i++)
    {
        maxsofar=max(maxsofar+a[i],a[i]);
        res=max(res,maxsofar);
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a)cin>>i;
    cout<<maxsumsubarray(a);
    return 0;
}