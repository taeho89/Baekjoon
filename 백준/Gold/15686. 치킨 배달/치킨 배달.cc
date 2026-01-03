#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int N, M;
int g[51][51];             // 2 <= N <= 50
vector<pair<int, int>> ch; // 1 <= M <= 13
vector<pair<int, int>> s;
vector<pair<int, int>> home;

int dist[51][51];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void bfs() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;

  for (pair<int, int> p : s) {
    // cout << "selected: (" << p.first << ", " << p.second << ")\n";
    q.push(p);
    dist[p.first][p.second] = 0;
  }

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= N)
        continue;
      if (dist[ny][nx] != -1)
        continue;

      dist[ny][nx] = dist[y][x] + 1;
      q.push({ny, nx});
    }
  }

  // cout << "\nResult dist\n";
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << dist[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
}

int res = INF;

void solve(int index, int depth) {
  if (depth == M) {
    bfs();
    int sum = 0;
    for (pair<int, int> p : home) {
      sum += dist[p.first][p.second];
    }
    res = min(res, sum);
    return;
  }
  for (; index < ch.size(); index++) {
    s.push_back(ch[index]);
    solve(index + 1, depth + 1);
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
      g[i][j] = n;
      if (n == 2)
        ch.push_back({i, j});
      if (n == 1)
        home.push_back({i, j});
    }
  }
  solve(0, 0);
  cout << res << '\n';
}