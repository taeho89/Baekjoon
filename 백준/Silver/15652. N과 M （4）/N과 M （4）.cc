#include <iostream>
#include <vector>

using namespace	std;

int N, M;
vector<int> v;

void  solve(int low, int d) {
  if (d == 1) {
    // 출력
    for (int i = low; i <= N; i++) {
      for (int n : v) {
        cout << n << ' ';
      }
      cout << i << '\n';
    }
    return ;
  }
  else {
    for (int i = low; i <= N; i++) {
      v.push_back(i);
      solve(i, d - 1);
      v.pop_back();
    }
  }
}

int	main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  solve(1, M);
  return 0;
}