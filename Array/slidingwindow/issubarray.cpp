#include <bits/stdc++.h>
using namespace std;

bool issubarray(vector<int> &a, int sum)
{
    int n=a.size();
    int s=0;
    int curr=0;

    for (int i=0;i<n;i++)
    {
        curr+=a[i];

        while (curr>sum)
        {
            curr-=a[s];
            s++;
        }
        if(curr==sum)
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
    vector<int> a;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    int sum=0;
    cin>>sum;
    cout<<issubarray(a,sum);
    return 0;

}