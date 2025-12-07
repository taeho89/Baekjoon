// 최소 힙 구현 문제
// input
// 첫째줄, (1 <= N <= 100,000) 연산 개수
// N개의 정수 x(0 <= x <= 2^31) == unsigned int 자료형내의 수,
// (x > 0) 이라면 push 연산
// (x == 0) 이라면 pop 연산 및 출력

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

std::priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>>
    min_heap;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    unsigned int x;
    cin >> x;
    if (x > 0) {
      // push
      min_heap.push(x);
    } else {
      // pop
      if (min_heap.empty()) {
        cout << 0 << '\n';
        continue;
      }
      cout << min_heap.top() << '\n';
      min_heap.pop();
    }
  }
  return 0;
}