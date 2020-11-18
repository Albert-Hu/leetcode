#include <iostream>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.convert("PAYPALISHIRING", 3) << endl;
  cout << s.convert("PAYPALISHIRING", 4) << endl;
  cout << s.convert("A", 1) << endl;
  cout << s.convert("A", 2) << endl;
  cout << s.convert("A", 3) << endl;
  cout << s.convert("AB", 1) << endl;

  return 0;
}
