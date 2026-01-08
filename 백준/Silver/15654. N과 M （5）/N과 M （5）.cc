#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int arr[8];
int ans[8];

int contain(int n) {
  for (int i = 0; i < N; i++) {
    if (ans[i] == n) {
      return 1;
    }
  }
  return 0;
}

void solve(int cnt) {
  if (cnt == M) {
    // print
    for (int i = 0; i < M; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < N; i++) {
    if (contain(arr[i])) {
      continue;
    }
    ans[cnt] = arr[i];
    solve(cnt + 1);
    ans[cnt] = 0;
  }
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    arr[i] = n;
  }

  sort(arr, arr + N);
  solve(0);
}