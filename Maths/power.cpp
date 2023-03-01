#include <bits/stdc++.h>
using namespace std;

int power(int a,int n)
{
    if (n==0)
    return 1;
    
    int temp=pow(a,n/2);
    temp=temp*temp;
    
    if (n%2==0)
    return temp;
    
    else
    return temp*a;
}

int main()
{
    int a,b;
    cout<<"Enter the number : ";
    cin>>a;
    cout<<"Enter the power : ";
    cin>>b;
    cout<<power(a,b);
    return 0;
}
