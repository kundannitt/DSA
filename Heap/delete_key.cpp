/*
Step 1: set the key to INT_MIN;
Step 2: Heapify on that key => it will move to the root
Step 3: Extract min.
*/

void delete_key(vector<int>&a, int index){
  a[index] = INT_MIN;
  int i = index;
  while(i!=0 && a[parent[i]] > a[i]){
    swap(a[i],a[parent[i]]);
    i = parent[i];
  }
  extractmin();
}