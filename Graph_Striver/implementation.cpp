#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; // no. of nodes
  cin>>n;
  int m; // no. of edges
  cin>>m;
  /*
  undirected graph adjacency matrix =>
  vector<vector<int>>adj(n+1,vector<int>(m+1,0));
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u][v] = 1; // for weighted instead of 1 write the weight
    adj[v][u] = 1;
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  vector<int>adj[n+1];
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v); // for weighted take pair data structure and push_back(v,wt);
    adj[v].push_back(u);// for weighted take pair data structure and push_back(u,wt);
  }
  cout<<endl;
  for(int i=1;i<n+1;i++){
    cout<<i<<" ";
    for(int j=0;j<adj[i].size();j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}