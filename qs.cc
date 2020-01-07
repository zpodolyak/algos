#include <iostream>
#include <vector>

int part(std::vector<int>& a, int low, int high) {
  int p = high;
  int j = low;
  
  for(int k = low; k < high; ++k)
    if(a[k] < a[p])
      std::swap(a[k], a[j++]);
  std::swap(a[p], a[j]);
  return j;
}

void quick_sort(std::vector<int>& a, int low, int high) {
  int p;
  if(high-low > 0) {
    p = part(a, low, high);
    quick_sort(a, low, p-1);
    quick_sort(a, p+1, high);
  }
}

int main() {
  std::vector<int> v{4,23,52,84,5,24,2,38,123,6,42,86,3};
  quick_sort(v, 0, v.size()-1);
  for(auto n : v)
    std::cout << n << ' ';
  std::cout << '\n';
  return 0;
}