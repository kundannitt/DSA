//no element greater in right of the element 'x' then x is a leader element
#include <bits/stdc++.h>
using namespace std;

vector<int> findleader(vector<int> &a){
    int n=a.size();
    int curr_leader=INT_MIN;

    vector<int> ans;

    for (int i=n-1;i>=0;i--)
    {
        if (a[i]>curr_leader)
        {
            curr_leader=a[i];
            ans.push_back(a[i]);
        }
    }
    return ans;
}

void print(vector<int> &a)
{
    for (int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i:a) cin>>i;
    
    vector<int> leader=findleader(a);
    print(leader);
    return 0;

}