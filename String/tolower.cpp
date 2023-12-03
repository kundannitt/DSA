#include <bits/stdc++.h>
using namespace std;

string lower(string s){
    transform(s.begin(),s.end(),s.begin(),::tolower);
    return s;
}

int main()
{
    string s;
    cin>>s;
    cout<<lower(s);
    return 0;
}