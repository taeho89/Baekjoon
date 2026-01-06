#include <iostream>
#include <string>

using namespace std;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  int robot, box, dest;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '@')
      robot = i;
    if (s[i] == '#')
      box = i;
    if (s[i] == '!')
      dest = i;
  }

  if ((robot < box && box > dest) || (robot > box && box < dest)) {
    cout << -1;
    return 0;
  }
  cout << abs(dest - robot) - 1;
  return 0;
}