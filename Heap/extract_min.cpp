// remove minimum element from the heap
/* for a min heap the Smallest element is its Root*/
//remove the root.
/*
Step 1: swap root with last element of the array
step 2: remove last element
step 3: call heapify for root(index = 0);
*/

void extractmin(){
  if(size==0){
    return;
  }
  if(size == 1){
    size--;
    return a[0];
  }
  swap(a[0],a[size-1]);
  size--;
  heapify(0);
  //size will reduce by 1.
}