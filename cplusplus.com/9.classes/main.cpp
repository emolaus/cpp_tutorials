#include <iostream>
using namespace std;

// Simple class
class Rectangle {
  // private members
  int width, height;
  public: 
  void setDimension(int,int); 
  int area() {return width*height;}
};
void Rectangle::setDimension(int w, int h) {
  width = w; height = h;
}

// Class with constructor
class Triangle {
  float base, height;
  public:
  Triangle();
  Triangle(float, float);
  float area() {return base*height/2;}
};
Triangle::Triangle() {base=2.0; height = 3.0;}
Triangle::Triangle(float b, float h) {
  base = b; height = h;
}

// Experiment
class Square {
  float side;
  public:
  Square(float s = 5.0) {side = s;};
};

class Thing {
  float a, b;
  public:
  Thing(float _a, float _b);
};
Thing::Thing(float _a, float _b): a(_a), b(_b) {}

// Default-constructing object members
class Brick {
  Square s;
  float length;
  public:
  // It is NECESSARY to construct the square in the member initialization list.
  Brick(float side, float _length): s(side), length(_length) {};
};

// Test operator overload
class CVector {
  public:
  int x,y;
  CVector() {};
  CVector (int a, int b) : x(a), y(b) {}
  CVector operator + (const CVector&);
};
CVector CVector::operator + (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

// static members
class Thing2 {
  public:
  static int counter;
  Thing2() { cout << "Thing nr " << counter++ << endl;}
};
int Thing2::counter = 0;

int main() {
  Rectangle r1;
  r1.setDimension(4,5);
  cout << "Area of r1: " << r1.area() << endl; 
  
  Triangle t1(1.0, 2.0);
  
  // INVALID, interpreted as function declaration
  //Square s1();
  Square s1;
  Square s2(1.0);
  Square *s3 = new Square();
  
  // Some other ways to create objects
  Square s4 (1.0);
  Square s5 = 2.0;
  Square s6 { 4.0 };
  Square s7 = { 5.0 };
  
  
  // Some ways to create object pointers
  Square *ps1 = &s4;
  Square *ps2 = new Square(2.0);
  Square *ps3 = new Square[2] {{1.0}, {2.0}};
  // CAUSES RUN-TIME ERROR
  //delete ps1;
  // OK
  ps1 = NULL;
  delete ps2;
  delete[] ps3;
  
  CVector v1(1, 2);
  CVector v2(2, -2);
  CVector v3 = v1 + v2;
  
  cout << "Size of CVector: " << sizeof(CVector) << endl;
  
  Thing2 th1;
  Thing2 th2;
  cout << "You can access static counter in two ways:" << endl;
  cout << th1.counter << endl;
  cout << Thing2::counter << endl;
  
  return 0;
}
