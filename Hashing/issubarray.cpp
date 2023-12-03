//subarray with sum zero
//idea : we uise prefixsum technique, if for some part sum is x and after some time we again get sum as x then there must have been a subarray with sum zero.
#include <bits/stdc++.h>
using namespace std;

bool issubarray(vector<int> &a, int n)
{
    unordered_set<int> st;
    int presum=0;
    for (int i=0;i<n;i++)
    {
        presum+=a[i];
        if (presum==0) // for some "sum" write "presum==sum";
        {
            return 0;
        }
        if (st.find(presum)!=st.end()) // for some sum write "st.find(presum-sum)";
        {
            return true;
        }
        st.insert(presum);
    }
    return false;
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

    cout<<issubarray(a,n);
    return 0;
}