#include <bits/stdc++.h>
using namespace std;
#define b 10000
int solve()
{
    int k;
    cin>>k;
    string s;
    cin>>s;

    string a;
    for (int i=1;i<=b;i++)
    {
        if (i%3==0)
        {
            a.push_back('F');
        }
        if (i%5==0)
        {
            a.push_back('B');
        }
    }
    // for (int i=0;i<100;i++)
    // {
    //     cout<<a[i];
    // }
    return(a.find(s)!=string :: npos);

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        bool x=solve();
        if (x==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}

// BFFBFFBF
//F B F F B  F  F   B F   B B   F
//3 5 6 9 10 12 15 18 20 21 24 25 27 30 
//F B F F B  F  F   F B   F F   B F F F B F F