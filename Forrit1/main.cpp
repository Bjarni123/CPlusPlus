#include <iostream>
#include <string>

using namespace std;

int main() {
  unsigned int i = 10;
  i++;
  ++i;
  i--;
  --i;

  cout << i++ << ":" << ++i << endl;


  /*
  string nafn = "Bjarni";
  bool b = true;
  float f = 22 / 7;
  double d = 22. / 7;

  cout << sizeof(i) << ":" << i << endl;
  cout << sizeof(f) << ":" << f << endl;
  cout << sizeof(d) << ":" << d << endl;
  cout << sizeof(nafn) << ":" << nafn << endl;
  cout << sizeof(b) << ":" << b << endl;
  */

  return 0;
}