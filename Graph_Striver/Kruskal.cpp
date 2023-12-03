//used to find MST
#include <bits/stdc++.h>
using namespace std;
struct DisjointSet{
  vector<int>rank,parent,size;
  DisjointSet(int n){
    rank.resize(n,0);
    parent.resize(n,0);
    size.resize(n,0);
    for(int i=0;i<n;i++){
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findUPar(int node){
    if(node == parent[node]){
      return node;
    }
    return parent[node] = findUPar(parent[node]);
  }
  void UnionbyRank(int u,int v){
    int ulp_u = parent[u];
    int ulp_v = parent[v];
    if(ulp_u == ulp_v){//belongs to same component.
      return;
    }else if(rank[ulp_u] < rank[ulp_v]){//smaller will go to larger
      parent[ulp_u] = ulp_v;
    }else if(rank[ulp_u] > rank[ulp_v]){
      parent[ulp_v] = ulp_u;
    }else{//when same, the node with which other node get attached will have their rank increased by 1
      parent[ulp_u] = ulp_v; // u get attached to v.
      rank[ulp_v]++;
    }
  }
  void UnionbySize(int u,int v){
    int ulp_u = parent[u];
    int ulp_v = parent[v];
    if(size[ulp_u] < size[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u]; // all nodes of u get attached to v.
    }else{
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

int MST(vector<vector<int>>&edges,int n){
  vector<pair<int,pair<int,int>>>graph;

  for(auto it:edges){
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    graph.push_back({wt,{u,v}});
  }

  DisjointSet ds(n);

  sort(graph.begin(),graph.end());
  int sum = 0;

  for(int i=0;i<graph.size();i++){
    int wt = graph[i].first;
    int u = graph[i].second.first;
    int v = graph[i].second.second;
    //check if u and v belongs to same component
    if(ds.findUPar(u) != ds.findUPar(v)){
      sum += wt;
      ds.UnionbySize(u,v);
    }
  }
  return sum;
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>>edges;
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back({u,v,wt});
  }
  cout<<MST(edges,n);
}

/*
9
14
0 1 4
1 2 8
0 7 8 
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
1 7 11
7 8 7
6 8 6
2 8 2
2 5 4
3 5 14

output:- 37
*/