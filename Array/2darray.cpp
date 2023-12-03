#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> a(5,vector<int>(5,0));
    int x=-1;
    int y=-1;
    int flag=0;
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin>>a[i][j];
            if (a[i][j]==1){
                x=i;
                y=j;
            }
        }
    }
    cout<<abs(x-2)+abs(y-2)<<endl;
    return 0;
}

/*
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
3
*/