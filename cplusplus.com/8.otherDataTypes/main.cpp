#include <iostream>
using namespace std;

// Bättre än typedef, färre begränsningar, funkar med templates
using myChar = char;

union myUnion {
  char c;
  int i;
} mu;

union mix {
  int l;
  struct {
    short lo;
    short hi;
  } s;
} _mix;

// Anonymous union
union mix2 {
  int i;
  struct {
    short lo;
    short hi;
  };
} _mix2;

// Simple enum
enum colors_t {
  black = 1,
  white  
};

// Enumerated types
enum class Colors {
  black,
  white
};

// Enumerated types with controlled underlying datatype
enum class EyeColor : char {brown, blue, green};

int main() {
  _mix.s.lo = 1;
  _mix2.lo = 1;
  
  mix2 mt;
  mt.lo = 5;
  cout << mt.lo << endl;
  
  colors_t color;
  color = white;
  cout << color << endl;
  
  Colors color2;
  color2 = Colors::black;
  if (color2 == Colors::black)
    cout << "black" << endl;
  
  return 0;
}


