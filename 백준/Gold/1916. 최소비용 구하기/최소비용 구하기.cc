#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int N, M;
vector<pair<int, int>> g[1001];
int dist[1001];

void dijkstra(int start) {
  fill(dist, dist + N + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int w = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (dist[cur] < w)
      continue;

    for (pair<int, int> &edge : g[cur]) {
      int next = edge.first;
      int nw = w + edge.second;

      if (nw < dist[next]) {
        dist[next] = nw;
        pq.push({nw, next});
      }
    }
  }
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  int s, e, w;
  for (int i = 0; i < M; i++) {
    cin >> s >> e >> w;
    g[s].push_back({e, w});
  }

  int start, dest;
  cin >> start >> dest;
  dijkstra(start);
  cout << dist[dest] << '\n';
}