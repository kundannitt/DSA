#include <bits/stdc++.h>
using namespace std;
// it tells us shortest path from any node to any other node in a matrix.
// apply algorithm in adjacency matrix.
// works on both directed and undirected

class Solution{
  public:
  void floyd(vector<vector<int>>&adjMat,int n){
    // we go via every node to every node => time :- O(n^3)
    for(int via = 0;via<n;via++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          adjMat[i][j] = min(adjMat[i][j] , adjMat[i][via] + adjMat[via][j]);
        }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(adjMat[i][j] == 1e9){
          adjMat[i][j] = -1;
        }
      }
    }
  }
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>adjMat(n,vector<int>(n,1e9));
  for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    adjMat[u][v] = wt;
  }
  for(int i=0;i<n;i++){
    adjMat[i][i] = 0;
  }
  Solution obj;
  obj.floyd(adjMat,n);
  for(auto i:adjMat){
    for(auto j:i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}

/*
  Sample Input:-
    4
    6
    0 1 3
    1 0 2
    2 1 1
    3 2 2
    1 3 4
    0 3 5
    
  Sample Output:-
    0 3 7 5 
    2 0 6 4 
    3 1 0 5 
    5 3 2 0
*/