//min diff between two adjacent cells in any path to reach (n-1,m-1) from (0,0);
#include <bits/stdc++.h>
using namespace std;

int min_effort(vector<vector<int>>&mat,int n,int m){
  vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
  dist[0][0] = 0;

  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
  pq.push({0,{0,0}});

  vector<int>delrow = {-1,0,1,0};
  vector<int>delcol = {0,1,0,-1};

  while(!pq.empty()){
    int curr_effort = pq.top().first;
    int row = pq.top().second.first;
    int col = pq.top().second.second;
    pq.pop();

    if(row == n-1 && col == m-1){
      return curr_effort;
    }

    for(int i=0;i<4;i++){
      int nrow = row + delrow[i];
      int ncol = col + delcol[i];
      if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){

        int new_effort = max(abs(mat[row][col] - mat[nrow][ncol]),curr_effort);//max diff b/w two cells in a path.

        if(new_effort < dist[nrow][ncol]){
          dist[nrow][ncol] = new_effort;
          pq.push({dist[nrow][ncol],{nrow,ncol}});
        }

      }
    }
  }
  return -1; // unreachable
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>mat(n,vector<int>(m));
  for(auto &i:mat){
    for(auto &j:i){
      cin>>j;
    }
  }
  cout<<min_effort(mat,n,m);
  return 0;
}
