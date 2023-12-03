//This program will give the max appearing element in the provided ranges. 
#include <bits/stdc++.h>
using namespace std;

int maxappear(vector<int> &l, vector<int> &r, int n)
{
    vector<int> maxocc(1000,0);

    for (int i=0;i<n;i++)
    {
        maxocc[l[i]]++;
        maxocc[r[i]+1]--;
    }

    for (int i=1;i<1000;i++)
    {
        maxocc[i]+=maxocc[i-1];
    }

    int max_element=0;
    // int count=0;
    for(int i=1;i<1000;i++)
    {
        if (maxocc[i]>max_element)
        {
            max_element=i;
            // count=a[i];
        }
    }
    return max_element;
    // to return the count-> return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<"Enter the ranges : "<<endl;
    vector<int>l(n);
    vector<int> r(n);
    for (int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
    }
    
    cout<<maxappear(l,r,n)<<endl;
    return 0;
}