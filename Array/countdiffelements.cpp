#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &a, int n, int k )
{
    unordered_map<int, int> mp;
    for (int i=0;i<k;i++)
    {
        mp[a[i]]++;
    }
    

    int low=0;
    int high=k-1;
    int count=0;
    while(high<n)
    {

        // for(auto i:mp)
        // {
        //     cout<<i.first<<" "<<i.second<<" ";
        // }
        

        cout<<mp.size();
        count+=mp.size();
        high++;
        mp[a[high]]++;

        mp[a[low]]--;
       
        if (mp[a[low]]==0)
        {
            mp.erase(a[low]);
        }
        low++;
        
    }
    return count;
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
    cout<<"Enter the size of window : ";
    int k;
    cin>>k;
    cout<<count(a,n,k);
    return 0;
}