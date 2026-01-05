#include <iostream>
#include <string>

using namespace std;

int N, M;
string S;

int solve() {
  int ans = 0;
  for (int i = 0; i < M; i++) {
    int cnt = 0;
    while (S[i] == 'I' && S[i + 1] == 'O' && S[i + 2] == 'I') {
      cnt++;
      if (cnt >= N) {
        ans++;
      }
      i += 2;
    }
  }
  return ans;
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> S;

  cout << solve() << '\n';
}