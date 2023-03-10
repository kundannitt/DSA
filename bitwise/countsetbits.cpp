#include <bits/stdc++.h>
using namespace std;

int countsetbits(int n)
{
    int count=0;
    while(n!=0)
    {
        if (n&(1)==1)
        {
            count++;
        }
        n=n>>1; //right shifting 1 bit at a time and ANDING with 1
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<countsetbits(n);
    return 0;
}