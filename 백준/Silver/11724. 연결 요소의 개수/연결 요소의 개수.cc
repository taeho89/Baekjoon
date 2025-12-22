#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	cnt = 0;
int	visited[1001];
vector<int> graph[1001];

void	solve(int node) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int	next_node = graph[node][i];
		if (!visited[next_node]) {
			solve(next_node);
		}
	}
}

int	main(void) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int	n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			solve(i);
			cnt++;
		}
	}
	cout << cnt << '\n';
}