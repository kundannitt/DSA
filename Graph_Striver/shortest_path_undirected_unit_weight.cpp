#include<bits/stdc++.h>
using namespace std;

vector<int>distance(vector<int>adj[],int n){
  vector<int>dist(n,INT_MAX);
  dist[0] = 0;
  queue<int>q;
  q.push(0);
  while(q.empty() == false){
    int node = q.front();
    q.pop();
    for(auto it : adj[node]){
      if(dist[node] + 1 < dist[it]){
        dist[it] = 1 + dist[node];
        q.push(it);
      }
    }
  }
  return dist;
}

int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  vector<int>adj[n];
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int>dist = distance(adj,n);
  for(auto it : dist){
    cout<<it<<" ";
  }
  return 0;
}