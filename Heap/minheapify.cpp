// given a minheap with one violation.
// given the index of the violated element.
// take min of index and its children and swap if min is not root call for its subtrees.

void heapify(int i){
  int lt = left(i);
  int rt = right(i);
  int min_index = i;
  if(lt<size && arr[i]>arr[lt]){
    min_index = lt;
  }
  if(rt<size && arr[i]>arr[rt]){
    min_index = rt;
  }
  if(smallest!=i){ // smaleest is not root
    swap(a[i],a[smallest]);
    minheapify(smallest); //if curr given index is not violated then others won't be called.
  }
}