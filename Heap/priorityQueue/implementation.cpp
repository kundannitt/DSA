#include <bits/stdc++.h>
using namespace std;
int main(){
  priority_queue<int> pq; // maxheap default
  // priority_queue<int,vector<int>,greater<int>>pq; => for minheap
  pq.push(10);
  pq.push(12);
  pq.push(9);
  pq.push(0);
  cout<<"The size of priority queue is "<<pq.size()<<endl;
  cout<<"The top element is "<<pq.top()<<endl;
  //printing elements 
  while(pq.empty()==false){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  return 0;
}