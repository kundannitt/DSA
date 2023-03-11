#include <bits/stdc++.h>
using namespace std;

void moveallzeroes(vector<int> &a){
    int n=a.size();
    int count=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]!=0)
        {
            swap(a[i],a[count]);
            count++;
        }
    }
}

void print(vector<int> &a)
{
    for (auto i:a){
        cout<<i<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a)cin>>i;
    moveallzeroes(a);
    print(a);
    return 0;
}