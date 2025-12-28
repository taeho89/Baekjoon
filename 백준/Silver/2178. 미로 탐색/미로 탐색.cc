#include <iostream>
#include <queue>
#include <string>

#define MAX 101

using namespace std;

int N, M;
int map[MAX][MAX];
int dist[MAX][MAX];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int solve() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;
  q.push({1, 1});
  dist[1][1] = 1;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    int y = cur.first;
    int x = cur.second;

    if (y == N && x == M)
      return dist[y][x];

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny > 0 && ny <= N && nx > 0 && nx <= M) {
        if (map[ny][nx] == 1 && dist[ny][nx] == -1) {
          dist[ny][nx] = dist[y][x] + 1;
          q.push({ny, nx});
        }
      }
    }
  }
  return -1;
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string line;

    cin >> line;
    for (int j = 1; j <= M; j++) {
      map[i][j] = line[j - 1] - '0';
    }
  }

  cout << solve() << '\n';
}