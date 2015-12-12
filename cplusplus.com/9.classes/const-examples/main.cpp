#include <iostream>
using namespace std;

class Class1 {
  int x;
  public:
  static int counter; 
  Class1(int val) : x(val) {counter++;}
  // Returns modifiable 
  int& get() {return x;}
  // Overloading, called by const objects
  int get() const {return x;}
  void set(int val) {x = val;}
  
  // const return types are considered obsolete, see
  // http://stackoverflow.com/questions/8716330/purpose-of-returning-by-const-value 
  Class1 clone() {
    Class1 result(this->x);
    return result;
  }
};
int Class1::counter = 0;

int main() {
  Class1 c1(10);
  // OOOOBBBSSS!!
  c1.get() = 5;
  cout << c1.get() << endl;
  
  const Class1 c2(20);
  cout << c2.get() << endl;
  
  Class1 cloned = c1.clone();
  cloned.set(30);
  cout << cloned.get() << endl;
  return 0;
}
