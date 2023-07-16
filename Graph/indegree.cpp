#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}
// number of arrows coming to the vertex.
vector<int>fun(vector<int>adj[],int v){
  vector<int> indegree(v,0);
  for(int i=0;i<v;i++){
    for(int u:adj[i]){
      indegree[u]++;
    }
  }
  return indegree;
}

int main(){
  int v = 5;
  vector<int>adj[5];
  addEdge(adj,0,2);
  addEdge(adj,0,3);
  addEdge(adj,2,3);
  addEdge(adj,1,3);
  addEdge(adj,1,4);
  vector<int>indegree = fun(adj,v);
  for(int i=0;i<v;i++){
    cout<<i<<" "<<indegree[i]<<endl;
  }
}