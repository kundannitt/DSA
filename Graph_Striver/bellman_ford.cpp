#include <bits/stdc++.h>
using namespace std;
//works on both directed and undirected.
//single source shortest path but it works with negative weights also, because we fixed the number of relaxtion to n-1
class Solution{
  public:
  vector<int>bellman_ford(int n,vector<vector<int>>&edges,int src){
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    for(int i=0;i<n-1;i++){
      for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
          dist[v] = wt + dist[u];
        }
      }
    }
    /*
      detect negative cycle using this algo
      1. we assume that after n-1th iteration no more edges can be relaxed
      2. So, we try to relax the edges one more time and if any edge can be relexed then the graph contains neg cycle.

      for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
          since entered here => edges can be relaxed again => neg cycle.
          return {-1};
        }
      }

    */
    return dist;
  }
};

int main() {
  int N, m;
  cin >> N >> m;
  vector<vector<int>> edges;

  for (int i = 0; i < m; ++i) {
    vector<int> temp;
    for (int j = 0; j < 3; ++j) {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    edges.push_back(temp);
  }

  int src;
  cin >> src;

  Solution obj;
  vector<int> res = obj.bellman_ford(N, edges, src);

  for (auto x : res) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}

/*
  sample input:
    6
    7
    0 1 5
    1 2 -2
    1 5 -3
    5 3 1
    3 2 6
    3 4 -2
    2 3 4
    0
  sample output :
    0 5 3 3 1 2 
*/