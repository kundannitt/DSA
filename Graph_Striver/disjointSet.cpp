//rank - height of any tree or graph like data structure
//ulp_v = ultimate parent of v
//ultimate parent = top most node from which childs are connected.
//size = no. of nodes attached to that node + self(1);
#include <bits/stdc++.h>
using namespace std;
struct DisjointSet{
  vector<int>rank,parent,size;
  DisjointSet(int n){
    rank.resize(n,0);
    parent.resize(n,0);
    size.resize(n,1);
    for(int i=0;i<n;i++){
      parent[i] = i;
    }
  }
  int findUpar(int node){
    if(node == parent[node]){
      return node;
    }
    return parent[node] = findUpar(parent[node]);
  }
  void UnionbyRank(int u,int v){
    int ulp_u = findUpar(u);
    int ulp_v = findUpar(v);
    if(ulp_u == ulp_v){//belongs to same component.
      return;
    }else if(rank[ulp_u] < rank[ulp_v]){//smaller will go to larger
      parent[ulp_u] = ulp_v;
    }else if(rank[ulp_u] > rank[ulp_v]){
      parent[ulp_v] = ulp_u;
    }else{//when same, the node with which other node get attached will have their rank increased by 1
      parent[ulp_u] = ulp_v; // u get attached to v.
      rank[ulp_v]++;
    }
  }
  void UnionbySize(int u,int v){
    int ulp_u = findUpar(u);
    int ulp_v = findUpar(v);
    if (ulp_u == ulp_v) return;
    if(size[ulp_u] <= size[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u]; // all nodes of u get attached to v.
    }else{
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

int main(){
  DisjointSet ds(7),ds2(7);
  ds.UnionbyRank(1,2);
  ds.UnionbyRank(2,3);
  ds.UnionbyRank(4,5);
  ds.UnionbyRank(6,7);
  ds.UnionbyRank(5,6);
  //check if 3 and 7 belongs to same graph
  if(ds.findUpar(3) == ds.findUpar(7)){
    cout<<"same"<<endl;
  }else{
    cout<<"not same"<<endl;
  }
  

  ds.UnionbyRank(3,7);

  if(ds.findUpar(3) == ds.findUpar(7)){
    cout<<"same"<<endl;
  }else{
    cout<<"not same"<<endl;
  }

  ds2.UnionbyRank(1,2);
  ds2.UnionbySize(2,3);
  ds2.UnionbySize(4,5);
  ds2.UnionbySize(6,7);
  ds2.UnionbySize(5,6);
  //check if 3 and 7 belongs to same graph
  if(ds2.findUpar(3) == ds2.findUpar(7)){
    cout<<"same"<<endl;
  }else{
    cout<<"not same"<<endl;
  }
  

  ds2.UnionbySize(3,7);

  if(ds2.findUpar(3) == ds2.findUpar(7)){
    cout<<"same"<<endl;
  }else{
    cout<<"not same"<<endl;
  }
  return 0;
}