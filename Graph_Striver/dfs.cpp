#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],int start,vector<bool>&vis){
  if(vis[start]){
    return;
  }
  cout<<start<<" ";
  vis[start] = true;
  for(auto it:adj[start]){
    if(vis[it] == false){
      dfs(adj,it,vis);
    }
  }
}

int count(vector<int>adj[],int n){
  vector<bool>vis(n+1,false);
  int count = 0;
  for(int i=1;i<=n;i++){
    if(vis[i] == false){
      count++;
      dfs(adj,i,vis);
    }
  }
  cout<<endl;
  return count;
}

int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  vector<int>adj[n+1];
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v); 
    adj[v].push_back(u);
  }
  cout<<endl;
  cout<<count(adj,n); // number of provinces.
  return 0;
}

/*
5
6
1 2
1 3
3 4
2 4
2 5
4 5

  1----2
  |    | \
  |    |  5
  3----4 / 
*/