#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int N, M;
vector<pair<int, int>> ch; // 1 <= M <= 13
vector<pair<int, int>> s;
vector<pair<int, int>> home;

int res = INF;

void calculate_distance() {
  int total_sum = 0;
  for (auto h : home) {
    int min_dist = INF;
    for (auto c : s) {
      int d = abs(h.first - c.first) + abs(h.second - c.second);
      min_dist = min(min_dist, d);
    }
    total_sum += min_dist;
  }
  res = min(res, total_sum);
}

void solve(int index, int depth) {
  if (depth == M) {
    calculate_distance();
    return;
  }
  for (int i = index; i < ch.size(); i++) {
    s.push_back(ch[i]);
    solve(i + 1, depth + 1);
    s.pop_back();
  }
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int n;
      cin >> n;
      if (n == 1)
        home.push_back({i, j});
      if (n == 2)
        ch.push_back({i, j});
    }
  }
  solve(0, 0);
  cout << res << '\n';
}