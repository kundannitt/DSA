#include <bits/stdc++.h>
using namespace std;

bool ispowerof2(int n)
{
    if (n==0){
        return false;
    }
    return ((n&(n-1))==0);
}

int main()
{
    int n;
    cin>>n;
    cout<<ispowerof2(n);
    return 0;   
}