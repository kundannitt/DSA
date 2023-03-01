#include <bits/stdc++.h>
using namespace std;

int lcm(int m,int n)
{
    return m*n/gcd(m,n);
}

int gcd(int m,int n)
{
    if (n==0)
    return m;
    else return gcd(n,m%n);
}

int main()
{
    int m,n;
    cout<<"Enter two numbers : ";
    cin>>m>>n;
    cout<<lcm(m,n);
    return 0;     
}
