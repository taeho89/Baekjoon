#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

int solve() {
  int cnt = 1;
  pair<int, int> select;

  select = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first < select.second)
      continue;
    select = v[i];
    cnt++;
  }
  return cnt;
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int s, e;
    cin >> s >> e;
    v.push_back({s, e});
  }

  sort(v.begin(), v.end(), compare);

  cout << solve() << '\n';
  return 0;
}