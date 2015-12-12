#include <iostream>
using namespace std;

template <class T>
class Pair {
  T values[2];
  public:
  Pair(T first, T second) {
    values[0] = first;
    values[1] = second;
  }
  T getmax();
};

template <class T>
T Pair<T>::getmax() {
  T result;
  result = values[0] > values[1] ? values[0] : values[1];
  return result;
}

//Template specalization. No "inheritance" of functions!
template <>
class Pair<float> {
  float values[2];
  public:
  Pair(float first, float second) {
    values[0] = first;
    values[1] = second;
  }
  float increment() { values[0]++; values[1]++;}
};

int main() {
  //sizeof(int): 4 bytes 
  cout << sizeof(Pair<int>) << endl;
  Pair<int> p(100, 75);
  cout << p.getmax() << endl;
  return 0;
}
