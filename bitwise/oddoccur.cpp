//x^x=0;
//0^x=x;
//x^y=x^y

//!! this works only for only one odd appearing element!!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    int x=0;
    for (int i=0;i<n;i++)
    {
        x=x^a[i];
    }
    cout<<x;
    return 0;
}