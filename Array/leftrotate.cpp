/*
eg 1 2 3 4 5 6 7 k=3
1. rotate first k element :  3 2 1 4 5 6 7
2. rotate last n-k element : 3 2 1 7 6 5 4
3. rotate whole array:       4 5 6 7 1 2 3
*/  

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &a, int k)
{
    int n=a.size();
    k=k%n; // if n==3 and k==5 then we have to rotate the array only by 2.
    reverse(a.begin(),a.end()-k); // rotating first n-k elements.
    reverse(a.begin()+n-k,a.end());
    reverse(a.begin(),a.end());
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
    int k; // for how much we want to rotate
    cin>>k;
    rotate(a,k);
    print(a);
    return 0;   
}