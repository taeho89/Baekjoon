#include <iostream>
#include <string>

using namespace    std;

int    main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string    line;

  cin >> line;
  for (int i = 0; i < line.length(); i++) {
    line[i] = line[i] - 32;
  }
  cout << line;
  return 0;
}