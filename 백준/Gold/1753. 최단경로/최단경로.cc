#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int V, E;
vector<pair<int, int>> adj[20001];
int dist[20001];

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    auto [d, c] = pq.top();
    pq.pop();

    if (d > dist[c])
      continue;

    for (pair<int, int> e : adj[c]) {
      int n = e.first;
      int nd = e.second + d;

      if (nd < dist[n]) {
        dist[n] = nd;
        pq.push({nd, n});
      }
    }
  }
}

void solve(int start) {
  fill(dist, dist + V + 1, INF);

  dijkstra(start);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << '\n';
  }
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> V >> E;
  int start;

  cin >> start;
  for (int i = 0; i < E; i++) {
    int s, e, w;
    cin >> s >> e >> w;
    adj[s].push_back({e, w});
  }

  solve(start);
  return 0;
}