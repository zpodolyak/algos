#include <iostream>

const int HEAP_SIZE=1024;

class minheap {
public:
  int items[HEAP_SIZE];
  int n = -1;

  void insert(int item) {
      if(n == HEAP_SIZE-1)
        return;
      items[++n]=item;
      bubbleUp(n);
  }

  void printHeap() {
    for(int i=0; i < n+1; ++i)
      std::cout << items[i] << '\n';
  }

  int extractMin() {
    if(n==-1) return -1;
    int min = items[0];
    items[0] = items[n--];
    bubbleDown(0);
    return min;
  }

  int parent(int item) const {
    if(item==-1) return -1;
    return item/2;  
  }

  int child(int item) const {
    return item*2;
  }

private:
  void bubbleUp(int item) {
    int p = parent(item);
    if(p == -1) return;
    if(items[p] > items[item]) {
      std::swap(items[p], items[item]);
      bubbleUp(parent(item));
    }
  }

  void bubbleDown(int item) {
    int min = item;
    int c = child(item);

    if(c<=n && items[min] > items[c]) 
      min = c;
    if(++c<=n && items[min] > items[c]) 
      min = c;
    if(min != item) {
      std::swap(items[min], items[item]);
      bubbleDown(min);
    }
  }
};

minheap make_heap(int arr[], int size) {
  minheap h;
  for(int i=0; i<size; ++i)
    h.insert(arr[i]);
  return h;
}

void heapsort(int arr[], int size) {
  auto h = make_heap(arr, size);

  for(int i=0; i<size; ++i)
    arr[i]=h.extractMin();
}
