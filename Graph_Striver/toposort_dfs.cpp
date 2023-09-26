#include <bits/stdc++.h>
using namespace std;

bool topo(vector<int>adj[],int node,vector<bool>&vis,stack<int>&st){
  vis[node] = true;
  for(auto it:adj[node]){
    if(!vis[it]){
      topo(adj,it,vis,st);
    }
  }
  st.push(node);
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
  stack<int>st;
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      topo(adj,i,vis,st);
    }
  }
  vector<int>ans;
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  for(auto it:ans){
    cout<<it<<" ";
  }
  return 0;
}