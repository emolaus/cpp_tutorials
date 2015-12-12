#include <iostream>
#include <new>
using namespace std;

int main() {
  // malloc etc are available in c++ but to create 
  // stuff dynamically (on the heap), use new and free with delete.
  
  cout << "How long shall the array be? ";
  int a;
  cin >> a;
  int *arr = new (nothrow) int[a];
  if (arr == NULL) {
    cout << "Out of memory" << endl;
    return 1;
  }
  int *p = arr;
  for (int i = 0; i < a; i++) {
    *(p++) = i;
  }
  for (int i = 0; i < a; i++) {
    cout << arr[i] << " ";
  }
  delete[] arr;
  cout << endl;
  return 0;
}
