#include <bits/stdc++.h>
using namespace std;

bool isequi(vector<int > &a, int n)
{
    int sum=accumulate(a.begin(),a.end(),0); // to add all elements, initialize initial sum as zero
    int lsum=0;
    int rsum=0;
    for(int i=1;i<n;i++)
    {
        lsum+=a[i-1];
        rsum=sum-a[i]-lsum;
        if (lsum==rsum)
        {
            return true;
        }
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
    cout<<isequi(a,n);
    return 0;
}