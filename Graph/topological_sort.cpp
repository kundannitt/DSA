#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}
// number of arrows coming to the vertex.
vector<int>indgree(vector<int>adj[],int v){
  vector<int> indegree(v,0);
  for(int i=0;i<v;i++){
    for(int u:adj[i]){
      indegree[u]++;
    }
  }
  return indegree;
}
/*
 BFS based solution:-
 1. store indegree of every vertex.
 2. create a queue q.
 3. add all 0 indegree vertices to q.
 4. while(q is not empty){
  u=q.pop();
  print u;
  for every adjacent of v of u{
    indegree[v]--;
    if indegree of v becomes 0, push into q.
  }
 }
*/
void topological_sort(vector<int>adj[],int v,vector<int>&indegree){
  queue<int>q;
  for(int i=0;i<size(indegree);i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  while(q.empty() == false){
    int x = q.front();
    q.pop();
    cout<<x<<" ";
    for(int u:adj[x]){
      indegree[u]--;
      if(indegree[u]==0){
        q.push(u);
      }
    }
  }
}

int main(){
  int v = 6;
  vector<int>adj[6];
  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,1,3);
  addEdge(adj,2,3);
  addEdge(adj,3,4);
  addEdge(adj,3,5);
  vector<int>indegree = indgree(adj,v);
  // for(int i=0;i<size(indegree);i++){
  //   cout<<indegree[i]<<" ";
  // }
  topological_sort(adj,v,indegree);
}