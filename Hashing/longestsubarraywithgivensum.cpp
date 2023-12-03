#include <bits/stdc++.h>
using namespace std;

int maxlength(vector<int>&a, int n, int sum)
{
    unordered_map<int,int>mp;
    int res=0;
    int presum=0;
    for (int i=0;i<n;i++)
    {
        presum+=a[i];
        if (presum==sum)
        {
            res=i+1;
        }
        if (mp.find(presum-sum)==mp.end())
        {
            mp.insert({presum,i});
        }
        if (mp.find(presum-sum)!=mp.end())
        {
            res=max(res,i-mp[presum-sum]);
        }

    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    cin>>sum;
    cout<<maxlength(a,n,sum);
    return 0;
}