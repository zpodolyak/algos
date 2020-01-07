#include <iostream>
#include <vector>

void merge(std::vector<int>& a, int low, int middle, int high) {
  std::vector<int> b = a;
  int i = low, j = middle;
  
  for(int k = low; k < high; ++k) {
    if(i < middle && (j >= high || b[i] <= b[j])) a[k]=b[i++];
    else a[k]=b[j++];
  }
}

void merge_sort(std::vector<int>& a, int low, int high) {
  if(high-low < 2) return;

  int mid = (low+high)/2;
  merge_sort(a, low, mid);
  merge_sort(a, mid, high);
  merge(a, low, mid, high);
}

int main() {
  std::vector<int> v{4,23,52,84,5,24,2,38,123,6,42,86,3};
  merge_sort(v, 0, v.size());
  for(auto n : v)
    std::cout << n << ' ';
  std::cout << '\n';
  return 0;
}