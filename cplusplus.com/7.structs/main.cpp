#include <iostream>
using namespace std;

struct Point {
  float x;
  float y;
} a, b;
int main () {
  cout << sizeof (float) << endl;
  cout << sizeof (Point) << endl;
  Point c;
  c.x = 10.0;
  
  return 0;
}
