class MyCircularQueue {
public:
  vector<int> v;
  int size,head,tail;  
  MyCircularQueue(int k) {
    v(k);
    size = k;
    head = -1;
    tail = -1;
  }
  
  bool enQueue(int value) {
    if(isFull()){
      return false;
    }
    if(tail==-1){
      head=0;
      tail=0;
    }else{
      tail=(tail+1)%size;
    }
    v[tail]=value;
    return true;
  }
  
  bool deQueue() {
    if(isEmpty()){
      return false;
    }
    if(head==tail){ // only one element
      head = tail = -1;
    }else{
      head = (head+1)%size;
    }
    return true;
  }
  
  int Front() {
    if(isEmpty()){
      return -1;
    }
    return v[head];
  }
  
  int Rear() {
    if(isEmpty()){
      return false;
    }
    return v[tail];
  }
  
  bool isEmpty() {
    return (head==-1);
  }
  
  bool isFull() {
    return ((head==0 && tail==size-1) || (tail==size-1));  
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */