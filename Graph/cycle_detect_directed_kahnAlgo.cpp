#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}
// if there is a cycle then we wont we able to cover all the vertcies while printing topological sort.
//refer topological sort also.

void topologicalSort(vector<int>adj[],int v,vector<int>&indegree){
  int count = 0;
  queue<int> q;
  for(int i=0;i<size(indegree);i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }
  while(q.empty()==false){
    int v = q.front();
    q.pop();
    for(int u:adj[v]){
      indegree[u]--;
      if(indegree[u]==0){
        q.push(u);
      }
    }
    count++;
  }
  if(count!=v){
    cout<<"Cycle";
  }else{
    cout<<"No Cycle";
  }
}

vector<int> indgree(vector<int>adj[],int v){
  vector<int>ans(v,0);
  for(int i=0;i<v;i++){
    for(int u:adj[i]){
      ans[u]++;
    }
  }
  return ans;
}

int main(){
  int v = 5;
  vector<int>adj[5];
  addEdge(adj,0,1);
  addEdge(adj,4,1);
  addEdge(adj,1,2);
  addEdge(adj,2,3);
  addEdge(adj,3,1);
  vector<int>indegree = indgree(adj,v);
  topologicalSort(adj,v,indegree);
}