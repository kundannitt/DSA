
void reduce(vector<int>&a, int index, int new_value){
  a[index] = new_value;
  int i = index;
  while(i!=0 && a[parent[i]] > a[i]){
    swap(a[parent[i]],a[i]);
    i=parent[i];
  }
}