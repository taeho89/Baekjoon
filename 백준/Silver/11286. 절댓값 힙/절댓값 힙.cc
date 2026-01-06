#include <iostream>
#include <queue>

using namespace std;

int N;

template <typename T> struct compare {
  bool operator()(const T &a, const T &b) const {
    if (abs(a) == abs(b)) {
      return a > b;
    }
    return abs(a) > abs(b);
  }
};

int main(void) {
  priority_queue<int, vector<int>, compare<int>> pq;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    if (n != 0)
      pq.push(n);
    else {
      if (pq.empty()) {
        cout << 0 << '\n';
        continue;
      }
      n = pq.top();
      pq.pop();
      cout << n << '\n';
    }
  }
}