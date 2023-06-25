#include <bits/stdc++.h>
using namespace std;

void maxheapify(int a[],int size,int i){
  int largest = i;
  int lt = (2*i)+1;
  int rt = (2*i)+2;
  if(size > lt && a[lt]>a[largest]){
    largest = lt;
  }
  if(size >  rt && a[rt] > a[largest]){
    largest = rt;
  }
  if(largest!=i){
    swap(a[i],a[largest]);
    maxheapify(a,size,largest);
  }
}

void buildmaxheap(int a[], int n){
  for(int i = (n-2)/2;i>=0;i--){
    maxheapify(a,n,i);
  }
}

void heapsort(int a[],int n){
  buildmaxheap(a,n);
  for(int i= n-1;i>=0;i--){
    swap(a[0],a[i]);
    maxheapify(a,i,0); 
    // i= new size upto which heapify is applied.
    /* 0 = since we swapped value at 0th index.
    it is violated in maxheap so we have to call heapify for that index.
    */

  }
}

void print(int a[], int n){
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(auto &i:a) cin>>i;
  heapsort(a,n);
  print(a,n);
  return 0;
}