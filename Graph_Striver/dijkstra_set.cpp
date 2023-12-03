//fives shortest path from source to all nodes.
#include <bits/stdc++.h>
using namespace std;

vector<int>dijkstra(vector<pair<int,int>>adj[],int S,int n){
  vector<int>dist(n,INT_MAX);
  dist[S] = 0;
  set<pair<int,int>>st;
  st.insert({0,S});
  while(!st.empty()){
    int curr_dist = (*st.begin()).first;
    int node = (*st.begin()).second;
    st.erase(st.begin());

    for(auto it : adj[node]){
      int wt = it.second;
      int adjNode = it.first;

      if(curr_dist + wt < dist[adjNode]){
        dist[adjNode] = wt + curr_dist;
        st.insert({dist[adjNode],adjNode});
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
  int source;
  cin>>source;
  vector<pair<int,int>>adj[n];
  for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
  }
  vector<int>dist = dijkstra(adj,source,n);
  for(int i=0;i<dist.size();i++){
    cout<<dist[i]<<" ";
  }
  return 0;
}

/*
  6
  8 
  0
  0 1 4
  0 2 4
  1 2 2
  2 3 3
  3 5 2
  2 4 1
  4 5 3
  2 5 6
*/
//output : 0 4 4 7 5 8