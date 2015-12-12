#include <iostream>
#include <string>
using namespace std;

class Vector {
  unsigned int m_size;
  float *pData;
  public:
  Vector(unsigned int);
  unsigned int size() {return m_size;}
  string toString() const;
  Vector operator+ (const Vector&);
  const float& operator[] (unsigned int pos) const { return pData[pos]; }
  float& operator[] (unsigned int pos) {return pData[pos];}
};

Vector::Vector(unsigned int _size) : m_size(_size) {
  pData = new float[_size];
  for(int i = 0; i < _size; i++) {
    pData[i] = i;
  }
}
string Vector::toString() const {
  // We'd like to print something like
  // [1.000000 -2.500000]
  string res = "[";
  for (int i = 0; i < m_size; i++) {
    res += to_string(pData[i]);
    if (i < m_size - 1) res += " "; 
  }
  res += "]";
  return res;
}
// a + b
Vector Vector::operator + (const Vector& b) {
  
  Vector result(b.m_size);
  for (int i = 0; i < this->m_size; i++) {
    result.pData[i] = this->pData[i] + b.pData[i];
  }
  return result;
}

int main() {
  Vector v(3);
  Vector w(3);
  cout << "v: " << v.toString() << endl;
  cout << "w: " << w.toString() << endl;
  cout << "v + w: " << (v+w).toString() << endl;
  cout << "v[2]: " << to_string(v[2]) << endl;
  v[0] = 5.0;
  cout << "v[0] = 5.0 => v: " << v.toString() << endl;
  return 0;
}
