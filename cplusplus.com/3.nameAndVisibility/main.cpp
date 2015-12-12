#include <iostream>
using namespace std;

namespace foo {
  double pi = 3.14;
}

namespace bar {
  double enlarge(double val) {return 2 * val;}
}

namespace foo {
  double e = 2.71;
}

int main() {
  using bar::enlarge;
  cout << enlarge(foo::e) << endl;
  return 0;
}
