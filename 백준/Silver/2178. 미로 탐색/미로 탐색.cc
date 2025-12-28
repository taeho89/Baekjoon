#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;

int map[101][101];
int visited[101][101];
int dist[101][101];

int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve() {
  queue<pair<int, int>> q;
  pair<int, int> cur;

  q.push({1, 1});
  visited[1][1] = 1;
  dist[1][1] = 1;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    int y = cur.first;
    int x = cur.second;

    if (y == N && x == M) {
      break;
    }
    for (int i = 0; i < 4; i++) {
      int next_y = y + pos[i][0];
      int next_x = x + pos[i][1];

      if (next_y >= 1 && next_x >= 1 && map[next_y][next_x] &&
          !visited[next_y][next_x]) {
        dist[next_y][next_x] = dist[y][x] + 1;
        visited[next_y][next_x] = 1;
        q.push({next_y, next_x});
      }
    }
  }
  return dist[cur.first][cur.second];
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string line;

    cin >> line;
    for (int j = 1; j <= M; j++) {
      map[i][j] = line[j - 1] - 48;
    }
  }

  cout << solve() << '\n';
}