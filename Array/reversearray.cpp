#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &a){
    int n=a.size();
    int low =0;
    int high=n-1;
    while(low<high)
    {
        swap(a[low],a[high]);
        low++;
        high--;
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
    reverse(a);
    print(a);
    return 0;
}