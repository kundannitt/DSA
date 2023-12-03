#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>adj[],int start,vector<bool>&vis){
  queue<int>q;
  q.push(start);
  while(q.empty() == false){
    auto x = q.front();
    q.pop();
    cout<<x<<" ";
    vis[x] = true;
    for(auto it:adj[x]){
      if(vis[it] == false){
        vis[it] = true;
        q.push(it);
      }
    }
  }
}

int count(vector<int>adj[],int n){
  vector<bool>vis(n+1,false);
  int count = 0;
  for(int i=1;i<=n;i++){
    if(vis[i] == false){
      count++;
      bfs(adj,i,vis);
    }
  }
  cout<<endl;
  return count;
}

int main(){
  int n;
  cin>>n;
  int m; // to know how much input of edges we have to take.
  cin>>m;
  vector<int>adj[n+1];
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v); 
    adj[v].push_back(u);
  }
  cout<<endl;
  cout<<count(adj,n); // number of provinces.
  return 0;
}

/*
5
6
1 2
1 3
3 4
2 4
2 5
4 5

  1----2
  |    | \
  |    |  5
  3----4 / 
*/