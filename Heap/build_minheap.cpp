//given a random vector, convert it to min heap.
// take bottom most rightmost node which has atleast 1 child.
void buildheap(vector<int>&a){
  //parent of last node
  int size = a.size();
  int last_index  = size - 1;

  //index of parent of index i = (i-1)/2;
  //so parent of last_index is ((size-1)-1)/2;
  
  for(int i=(size-2)/2;i>=0;i--){
    minheapify(i);
  }
}