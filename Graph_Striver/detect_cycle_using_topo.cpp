#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>adj[n];
  int edges;
  cin>>edges;
  for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  
  vector<int>indegree(n,0);
  for(int i=0;i<n;i++){
    for(auto it:adj[i]){
      indegree[it]++;
    }
  }
  queue<int>q;
  for(int i=0;i<indegree.size();i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  vector<int>topo;
  while(q.empty() == false){
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for(auto it : adj[node]){
      indegree[it]--;
      if(indegree[it] == 0){
        q.push(it);
      }
    }
  }
  if(topo.size() == n){
    cout<<"No cycle"<<endl;
  }else{
    cout<<"Cycle"<<endl;
  }
  return 0;
}
