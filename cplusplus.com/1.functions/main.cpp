#include <stdio.h>
#include <iostream>

void duplicate(int &a) {
  a = 3;
}

using namespace std;

string concat(const string &a, const string &b) {
  return a+b;
}

int main (void) {
  int a = 2;
  duplicate(a);
  string s = "kakaka";
  string t = "kokoko";
  printf("%i\n", a);
  cout << concat(s,t) << endl;
  return 0;
}
