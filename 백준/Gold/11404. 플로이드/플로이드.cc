#include <iostream>

#define INF 1e9

using namespace std;

int N, M;
int g[101][101];

void solve() {
  // pivot
  for (int i = 1; i <= N; i++) {
    // start
    for (int j = 1; j <= N; j++) {
      // end
      for (int k = 1; k <= N; k++) {
        g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
      }
    }
  }
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    fill(g[i], g[i] + 101, INF);
  }
  for (int i = 0; i < M; i++) {
    int s, e, w;

    cin >> s >> e >> w;
    if (w < g[s][e])
      g[s][e] = w;
  }

  solve();

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (g[i][j] == INF || i == j)
        cout << 0 << ' ';
      else
        cout << g[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}