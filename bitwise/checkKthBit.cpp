#include <bits/stdc++.h>
using namespace std;
//using leftshifting
// bool checkKthbit(int n, int k)
// {
//     return (n&(1<<(k-1))); //left shifting the kth bit to the first position 
//                            //and then Anding with 1,, since we are already pointing to first we only shifted k-1;
 
// }

//using rightshifting
bool checkKthbit(int n, int k)
{
    return ((1>>k-1)&n);
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    cout<<checkKthbit(n,k);
    return 0;
}