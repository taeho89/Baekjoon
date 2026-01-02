#include <iostream>
#include <queue>

using namespace std;

int	map[1000][1000];
int	dist[1000][1000];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int N, M;

void	solve(int y, int x) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;

  q.push({y, x});
  dist[y][x] = 0;

  pair<int, int>  c;
  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == 0 || dist[ny][nx] >= 0) continue ;

      q.push({ny, nx});
      dist[ny][nx] = dist[cy][cx] + 1;
    }
  }
}

int	main(void) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int	target[2];

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				target[0] = i;
				target[1] = j;
			}
		}
	}

	solve(target[0], target[1]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
      if (map[i][j] == 0) {
        cout << 0 << ' ';
      } else {
        cout << dist[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}