#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void dfsrec(vector<int>adj[],int s, bool visited[]){
  visited[s] = true;
  cout<<s<<" ";
  for(int x:adj[s]){
    if(visited[x] == false){
      visited[x] = true;
      dfsrec(adj,x,visited);
    }
  }
}

int main(){
  int v = 7;
  vector<int>adj[7];
  addEdge(adj,0,1);
  addEdge(adj,1,2);
  addEdge(adj,2,3);
  addEdge(adj,0,4);
  addEdge(adj,4,5);
  addEdge(adj,4,6);
  addEdge(adj,5,6);
  bool visited[v];
  for(int i=0;i<v;i++){
    visited[i] = false;
  }
  dfsrec(adj,0,visited); // here 0 is source vertex.
  return 0;
}
/*
     0 
   /   \
  1     4
  |    / \
  2   5---6
  |
  3
*/