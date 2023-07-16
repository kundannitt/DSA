#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}

bool dfsrec(vector<int>adj[],int s, vector<bool>&visited,vector<bool>&recSt){
  visited[s] = true;
  recSt[s] = true;
  for(int u:adj[s]){
    if(visited[u] ==false && dfsrec(adj,u,visited,recSt)){
      return true;
    }else if(recSt[u] == true){
      return true;
    }
  }
  recSt[s] = false; // since we are doing it for each vertex.. we have to mark it false after checking for each vertex 's'.
  return false;
}

//refer notes.
//we maintain boolean array of called recursion function for each vertex.
bool isCycle(vector<int>adj[],int v){
  vector<bool> visited(v,false);
  vector<bool>recSt(v,false);
  for(int i=0;i<v;i++){
    if(visited[i]==false){
      if(dfsrec(adj,i,visited,recSt)==true){
        return true;
      }
    }
  }
  return true; 
}

int main(){
  int v = 6;
  vector<int>adj[6];
  addEdge(adj,0,1);
  addEdge(adj,2,1);
  addEdge(adj,2,3);
  addEdge(adj,3,4);
  addEdge(adj,4,5);
  // addEdge(adj,3,5);
  cout<<isCycle(adj,v);
}