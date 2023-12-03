#include <bits/stdc++.h>
using namespace std;

bool iscycle(vector<int>adj[],int node,vector<bool>&vis,vector<bool>&pathvis){
  vis[node] = true;
  pathvis[node] = true;
  for(auto it : adj[node]){
    if(!vis[it]){
      if(iscycle(adj,it,vis,pathvis) == true){
        return true;
      }
    }else if(pathvis[it]){ //same node found on same path 
      return true;
    }
  }
  pathvis[node] = false;
  return false;
}

int main(){
  int n;
  cin>>n;
  vector<int>adj[n+1];
  int edges;
  cin>>edges;
  for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  vector<bool>vis(n+1,false);
  vector<bool>pathvis(n+1,false);
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      if(iscycle(adj,i,vis,pathvis) == true){
        cout<<i<<" Cyclic ";
      }
    }
  }
  return 0;
}