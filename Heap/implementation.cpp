#include <bits/stdc++.h>
using namespace std;
class myheap{
  int cap;
  int size;
  vector<int> a;
  public:
  myheap(int n){
    cap = n;
    a = vector<int>(n);
    size = 0;
  }
  int left(int i){
    return 2*i + 1;
  }
  int right(int i){
    return 2*i + 2;
  }
  int parent(int i){
    return (i-1)/2;
  }
};

int main(){
  myheap x(10);  
}