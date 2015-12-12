#include <iostream>
#include <string>

using namespace std;

int main() {

  for (int i = 0; i < 2; ++i) cout << i << endl;
  int j = 0;
  for (;j < 2; j++) cout << j << endl;
  string str = "Hello";
  for (char c:str) cout << "[" << c << "]";
  cout << endl;
  
  return 0;
}
