#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

vector<int> shortestpath(vector<int> adj[],int s,int v){
  vector<int>dist(v,INT_MAX);
  dist[0] = 0;
  queue<int> q;
  vector<bool> visited(v,false);
  q.push(s);
  visited[s] = true;
  while(q.empty()==false){
    int u = q.front();
    q.pop();
    for(int v:adj[u]){
      if(visited[v] ==false){
        dist[v]= dist[u]+1;
        visited[v] = true;
        q.push(v);
      }
    }
  }
  return dist;
}

void print(vector<int> dist){
  for(auto i:dist){
    cout<<i<<" ";
  }
}

int main(){
  int v = 6;
  vector<int>adj[6];
  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,0,4);
  addEdge(adj,2,3);
  addEdge(adj,2,4);
  addEdge(adj,1,3);
  addEdge(adj,4,5);
  addEdge(adj,3,5);
  // shortest path to all other vertices from vertex '0'
  vector<int> dist = shortestpath(adj,0,v); //0 is source vertex.
  print(dist);
}