#include <iostream>
#include <string>
using namespace std;

int doSth(int a, int b) {
  return a*b;
}
double doSth(double a, double b) {
  return a/b;
}

template <class T>
T sum(T a, T b) {
  T result;
  result = a + b;
  return result;
}

int main() {
  int x=2, y=5;
  double n=5.0, m=2.0;
  cout << doSth(x,y) << endl;
  cout << doSth(n,m) << endl;
  cout << sum(1.0, 2.0) << endl;
  cout << sum(2, 3) << endl;
  return 0;
}
