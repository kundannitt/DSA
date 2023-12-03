// given a max heapify with only one violation at ith index.
void maxheapify(int i){
  int largest = i;
  int lt = left(i);
  int right = right(i);
  int size // size of heap
  if(lt<size && a[lt] > a[largest]){
    largest = lt;
  }
  if(rt<size && a[rt] > a[largest]){
    largest = rt;
  }
  if(largest != i){
    swap(a[largest],a[i]);
    maxheapify(largest);
  }
}