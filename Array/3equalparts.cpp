#include <bits/stdc++.h>
using namespace std;

bool is3pair(vector<int> &a, int n)
{
    int sum=0;
    for (int i =0;i<n;i++)
    {
        sum+=a[i];
    }

    int lsum=a[0];
    int rsum=a[n-1];
    int x=sum;
    for (int i=1;i<n-1;i++)
    {
        if (lsum==rsum && rsum==x)
        {
            return true;
        }
        if (lsum>rsum)
        {
            rsum=rsum+a[n-i-1];
            
        }
        else
        {
            lsum=lsum+a[i];
        }
        x=sum-(lsum+rsum);
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<is3pair(a,n);
    return 0;
}
