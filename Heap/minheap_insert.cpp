#include <bits/stdc++.h>
using namespace std;

void insert(int n){
  if(size==cap){
    return;
  }
  size++;
  arr[size-1] = n;
  int i = size -1;
  while(i>=0 && arr[parent[i]] > arr[i]){
    swap(arr[parent[i]],arr[i]);
    i = parent[i];
  } 
}