#include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int>&a){
  int n = a.size();
  int index = n-1;
  
  while(index >=0){
    int max_index = 0;
    for(int i=0;i<index;i++){
      if(a[max_index] < a[i]){
        max_index = i;
      }
    }
    if(max_index == 0){
      break;
    }
    swap(a[index],a[max_index]);
    index--;
  }
}

void print(vector<int>a){
  for(auto i:a)cout<<i<<" ";
}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(auto &i:a) cin>>i;
  selectionsort(a);
  print(a);
  return 0;
}