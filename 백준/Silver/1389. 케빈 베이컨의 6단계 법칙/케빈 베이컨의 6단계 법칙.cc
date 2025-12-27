#include <algorithm>
#include <climits>
#include <iostream>

#define INF 1e9

using namespace std;

int N, M;
int v[101][101];

void print() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (v[i][j] == INF) {
        cout << "INF" << ' ';
      } else {
        cout << v[i][j] << "   ";
      }
    }
    cout << '\n';
  }
}

int solve() {
  int min_num = INF;
  int min = INF;

  // 기준 노드
  for (int k = 1; k <= N; k++) {
    // 출발지 노드
    for (int i = 1; i <= N; i++) {
      // 도착지 노드
      for (int j = 1; j <= N; j++) {
        v[i][j] = std::min(v[i][j], v[i][k] + v[k][j]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    v[i][0] = 0;
    for (int j = 1; j <= N; j++) {
      v[i][0] += v[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    if (v[i][0] < min) {
      min = v[i][0];
      min_num = i;
    }
  }

  return min_num;
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) {
        v[i][j] = 0;
      } else {
        v[i][j] = INF;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    v[a][b] = 1;
    v[b][a] = 1;
  }

  cout << solve() << '\n';
}