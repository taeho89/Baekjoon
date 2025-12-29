#include <iostream>

using namespace std;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    int target;
    cin >> target;

    cout << "Pairs for " << target << ": ";
    for (int j = 1; j < target / 2 + 1; j++) {
      if (j == target - j) {
        break;
      }
      if (j != 1) {
        cout << ", ";
      }
      cout << j << ' ' << target - j;
    }
    cout << '\n';
  }
}