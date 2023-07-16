#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool dfsrec(vector<int>adj[],int s,vector<bool>&visited,int parent){
  visited[s] = true;
  for(int u:adj[s]){
    if(visited[u] == false){
      if(dfsrec(adj,u,visited,s)==true){
        return true;
      }
    }else if(u!=parent){
      return true;
    }
  }
  return false;
}

bool iscycle(vector<int>adj[],int v){
  vector<bool> visited(v,false);
  for(int i=0;i<v;i++){
    if(visited[i]==false){
      if(dfsrec(adj,i,visited,-1)==true){
        return true;
      }
    }
  }
  return false;
}

int main(){
  int v = 6;
  vector<int>adj[6];
  addEdge(adj,0,1);
  addEdge(adj,1,2);
  addEdge(adj,1,3);
  addEdge(adj,2,3);
  addEdge(adj,2,4);
  addEdge(adj,4,5);
  cout<<iscycle(adj,v);
}