#include<bits/stdc++.h>
using namespace std;

bool ispair(vector<int> &a, int n , int sum)
{
    unordered_set<int> st;
    for (int i=0;i<n;i++)
    {
        if (st.find(sum-a[i])!=st.end())
        {
            return true;
        }
        st.insert(a[i]);
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
    int sum;
    cin>>sum;
    cout<<ispair(a,n,sum)<<endl;
    return 0;
}