#include <iostream>
#include <queue>

using namespace std;

int N, K;
int dist[100001];
int visited[100001];

int solve() {
  queue<int> q;
  int cur;

  q.push(N);
  while (!q.empty()) {
    cur = q.front();
    q.pop();

    if (cur == K) {
      break;
    }

    int next_pos[3] = {cur - 1, cur + 1, cur * 2};

    for (int next : next_pos) {
      if (next >= 0 && next <= 100000 && !visited[next]) {
        visited[next] = 1;
        dist[next] = dist[cur] + 1;
        q.push(next);
      }
    }
  }
  return dist[cur];
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  cout << solve() << '\n';
}