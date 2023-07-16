#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// adj = adjacency matrix, v = number of vertex , s= source vertex
void bfs(vector<int>adj[],int v, int s){
  //using queue
  // since here a cycle can be present we must ensure that no vertex gets repeated.
  vector<bool>visited(v,false);
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while(q.empty() == false){
    int u = q.front();
    q.pop();
    cout<<u<<" ";
    for(int v : adj[u]){
      if(visited[v]==false){
        q.push(v);
        visited[v] = true;
      }
    }
  }
}

int main(){
  int v = 4;
  vector<int>adj[4];
  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,1,2);
  addEdge(adj,1,3);
  bfs(adj,v,0);
  return 0;
}
/*
 0---1---3
  \ /
   2
in bfs first we print the source vertex then its friends and then their friends ans so on.
*/

