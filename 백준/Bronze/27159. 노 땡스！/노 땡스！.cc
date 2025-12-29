#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    v.push_back(n);
  }

  int sum = v[0];
  for (int i = 1; i < N; i++) {
    if (v[i] - 1 == v[i - 1])
      continue;
    sum += v[i];
  }
  cout << sum << '\n';
}
