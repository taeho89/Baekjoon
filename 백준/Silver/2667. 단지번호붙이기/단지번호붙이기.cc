#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N;
int map[25][25];
int visited[25][25];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int inside(int y, int x) {
  if (y < 0 || y >= N) {
    return 0;
  }
  if (x < 0 || x >= N) {
    return 0;
  }
  return 1;
}

int bfs(int y, int x) {
  int cnt = 1;
  queue<pair<int, int>> q;
  pair<int, int> cur;

  q.push({y, x});
  visited[y][x] = 1;

  while (!q.empty()) {
    cur = q.front();
    q.pop();
    int y = cur.first;
    int x = cur.second;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (inside(ny, nx) && map[ny][nx] == 1 && !visited[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = 1;
        cnt++;
      }
    }
  }
  return cnt;
}

void solve() {
  vector<int> homes;
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j] == 1 && !visited[i][j]) {
        homes.push_back(bfs(i, j));
        cnt++;
      }
    }
  }

  sort(homes.begin(), homes.end());
  cout << cnt << '\n';
  for (int n : homes) {
    cout << n << '\n';
  }
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    string line;

    cin >> line;
    for (int j = 0; j < N; j++) {
      map[i][j] = line[j] - '0';
    }
  }

  solve();
}
