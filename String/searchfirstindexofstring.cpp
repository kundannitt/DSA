//return first index of occurenece of s2 in s1.
#include <bits/stdc++.h>
using namespace std;

int firstindex(string s1,string s2){
    auto found = s1.find(s2);
    if(found ==string ::npos){
        return -1;
    }
    return found;
}

int main(){
    string s1; cin>>s1;
    string s2; cin>>s2;

    cout<<firstindex(s1,s2);
    return 0;
}