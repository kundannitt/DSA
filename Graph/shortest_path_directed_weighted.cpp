#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>wt;

/*
  Steps:-
  1. find topological sort.
  2. traverse throught the topological sort vector.
  3. Initialize a vector dist of size 'v' and initial value to INT_MAX.
  4. for every adjacent 'v' of 'u' :-
      if(dist[v] > (dist[u] + wt[{u,v}])){
        dist[v] = dist[u] + wt[{u,v}];
      }
*/

void addEdge(vector<int>adj[],int u,int v,int w){
  adj[u].push_back(v);
  wt[{u,v}] = w;
}

vector<int>indegree(vector<int>adj[],int v){
  vector<int> ans(v,0);
  for(int i=0;i<v;i++){
    for(int u:adj[i]){
      ans[u]++;
    }
  }
  return ans;
}

vector<int>topological_sort(vector<int>adj[],int v,vector<int>&indegree){
  vector<int>ans;
  queue<int>q;
  for(int i=0;i<size(indegree);i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }
  while(q.empty()==false){
    int v = q.front();
    q.pop();
    ans.push_back(v);
    for(int u:adj[v]){
      indegree[u]--;
      if(indegree[u]==0){
        q.push(u);
      }
    }
  }
  return ans;
}
vector<int>shortestpath(vector<int>adj[],int s,int v){
  vector<int>indgree = indegree(adj,v);
  vector<int>topo_sort = topological_sort(adj,v,indgree);
  // for(auto i:topo_sort){
  //   cout<<i<<" ";
  // }
  // cout<<endl;
  vector<int> dist(v,INT_MAX);
  dist[s] = 0;

  for(int i=0;i<size(topo_sort);i++){
    int u = i;
    for(int v:adj[u]){
      if(dist[v] > (dist[u] + wt[{u,v}])){
        dist[v] = dist[u] + wt[{u,v}];
      }
      // cout<<u<<" "<<v<<endl;
      // cout<<wt[{u,v}];
    }
  }
  return dist;
}

int main(){
  int v = 6;
  vector<int>adj[6];
  addEdge(adj,0,1,2);
  addEdge(adj,0,4,1);
  addEdge(adj,1,2,3);
  addEdge(adj,4,2,2);
  addEdge(adj,4,5,4);
  addEdge(adj,2,3,6);
  addEdge(adj,5,3,1);
  // for(auto i:wt){
  //   cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
  // }
  // cout<<wt[{1,2}];
  vector<int> vec = shortestpath(adj,0,v); // 0 is source
  for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<" ";
  }
}