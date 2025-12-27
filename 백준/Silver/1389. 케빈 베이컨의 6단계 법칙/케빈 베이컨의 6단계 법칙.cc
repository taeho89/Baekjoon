#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> adj[101];

int bfs(int start) {
  queue<int> q;
  vector<int> dist(N + 1, -1);
  int bacon = 0;

  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int neighbor : adj[cur]) {
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[cur] + 1;
        q.push(neighbor);
        bacon += dist[neighbor];
      }
    }
  }
  return bacon;
}

int solve() {
  int min = 1e9;
  int answer = 0;

  for (int i = 1; i <= N; i++) {
    int res = bfs(i);

    if (res < min) {
      min = res;
      answer = i;
    }
  }
  return answer;
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout << solve() << '\n';
}