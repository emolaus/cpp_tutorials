#include <iostream>
#include <string>
using namespace std;

// Copy constructor example.
// Very unexpected result!
class Something {
  public:
    int y;
    Something(int val) : y(val) {}
};
class Thing {
  public:
    int x;
    string s;
    Something sth;
    Thing() :x(0), s("text"), sth(0){}
};

int main() {
  
  Thing t1;
  Thing t2 = t1;
  cout << "t2.x: " << t2.x << " t2.s: " << t2.s << " t2.sth.y: " << t2.sth.y << endl;
  t1.x = 1;
  t1.s += " added";
  t1.sth.y = 1;
  
  cout << "t2.x: " << t1.x << " t2.s: " << t2.s << " t2.sth.y: " << t2.sth.y << endl;
  return 0;
}
