#include <bits/stdc++.h>
using namespace std;

string reverseword(string &s)
{
    int n=s.length();
    int start=0;
    int count=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]==' ')
        {
            reverse(s.begin()+start,s.end()-n+count);
            start=i+1;
        }
        count++;
    }
    reverse(s.begin()+start,s.end());
    return s;
}

int main()
{
    string s;
    getline(cin,s);
    reverseword(s);
    cout<<s;
    return 0;
}