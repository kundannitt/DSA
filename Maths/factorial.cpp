#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n<=1)
    return 1;
    
    else return n*fact(n-1);
}


int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"The factorial is " <<fact(n);
    return 0;
}
