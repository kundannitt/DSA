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
    reverse(a.begin(),a.end()-n+k);
    reverse(a.begin()+k,a.end());
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