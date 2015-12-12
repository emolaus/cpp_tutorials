#include <iostream>
using namespace std;

int main() {
  int a;
  cout << "Please Type a number: ";
  cin >> a;
  cout << "You typed: " << a << endl;
  cout << "Please enter a string to send to stderr: ";
  string s;
  cin >> s;
  cerr << s << endl;
  return 0;
}
