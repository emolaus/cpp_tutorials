#include <iostream>
#include <string>
using namespace std;

// Copy constructor example.
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
    Something *p_sth;
    Thing() :x(0), s("text"), sth(0){ p_sth = new Something(0); }
};

// Move constructor and move assignment 
Thing someFunction() { return Thing(); }

// Move constructor, move assignment, rvalue reference
class AThing {
  string *ptr;
  public:
    AThing(const string& str) : ptr(new string(str)) {}
    ~AThing() { delete ptr; }
    // move constructor. AThing&& is rvalue reference. This happens in e.g. foo = functionThatReturnsAThing().
    AThing(AThing&& x) : ptr(x.ptr) {x.ptr = nullptr; } // so x is the returned object and this is foo
    // move assignment, e.g. foo = AThing()
    AThing& operator= (AThing&& x) {
      delete ptr; // Here foo is this and the returned object is x
      ptr = x.ptr;
      x.ptr = nullptr;
      return *this;
    }
    // Access string
    const string& content() const { return *ptr; }
    // Addition:
    AThing operator+ (const AThing& rhs) {
      return AThing(content() + rhs.content());
    }
};

// Implicit members
class R {
  public:
   R(int x) {}
   R() = default;           // Include default constructor
   R(const R& x) = delete;  // Exclude default copy constructor
   
};

int main() {
  cout << "* Default constructors. Default contructor isn't created if other is defined." << endl;
  // INVALID, default contructor isn't created if other is defined
  // Something sth;
  // OK
  Something sth(1);
  cout << "* Destructors are created by default. Override with Thing::~Thing() {...} to delete heap objects. No example." << endl;
  cout << "* Copy constructor example" << endl; 
  Thing t1;
  // Use default copy constructor
  Thing t2 = t1;
  cout << "t2.x: " << t2.x << " t2.s: \"" << t2.s << "\" t2.sth.y: " << t2.sth.y << " t2.p_sth->y: " << t2.p_sth->y << endl;
  t1.x = 1;
  t1.s += " added";
  t1.sth.y = 1;
  t1.p_sth->y = 1;
  
  cout << "t2.x: " << t2.x << " t2.s: \"" << t2.s << "\" t2.sth.y: " << t2.sth.y << " t2.p_sth->y: " << t2.p_sth->y <<  endl;
  cout << "Conclusion: all elements are new copies. The p_sth is also copied, pointing to the same object: t1.p_sth = t2.p_sth" << endl;
  
  cout << "* Copy assignment. Many ways to do this. the copy assignment operator = is overloaded." << endl;
  Thing t3;
  Thing t4 (t3);
  Thing t5 = t3;
  t3 = t5;

  cout << "* Move constructor, move assignment, rvalue reference." << endl;
  // Move constructor
  Thing foo = someFunction();
  // Move assignment
  Thing baz = Thing();
  // move assigment
  AThing t6("String1");
  AThing t7("String2");
  t6 = t6 + t7;
  cout << "Result of addition/move assigment: " << t6.content() << endl;
  
  cout << "* Implicit members: decide with keywords default and delete which shall be included. Tip from site:" << endl;
  cout << "In general, and for future compatibility, classes that explicitly define one copy/move constructor or one copy/move assignment but not both, are encouraged to specify either delete or default on the other special member functions they don't explicitly define." << endl;
  
  return 0;
}
