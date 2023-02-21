#include <iostream>
#include <list>
#include <string>

int main() {
  std::string unscrambledWord;
  std::cin >> unscrambledWord;
  
  std::list<char> svar;
  auto idx = svar.begin();

  for (char x : unscrambledWord) {
    if (x == 'L') {
      if (idx != svar.begin()) {
        idx--;
      }
    } else if (x == 'R') {
      if (idx != svar.end()) {
        idx++;
      }
    } else if (x == 'B') {
      if (idx != svar.begin()) {
        idx--;
        idx = svar.erase(idx);
      }
    } else {
      svar.insert(idx, x);
      idx++;
    }
  }
  
  for (char c : svar) {
    std::cout << c;
  }
  std::cout << std::endl;
  
  return 0;
}

