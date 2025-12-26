#include <iostream>

using namespace std;

int N;
int arr[200000];
int s[10];

int count() {
  int cnt = 0;
  for (int i = 1; i < 10; i++) {
    if (s[i] > 0) {
      cnt++;
    }
  }
  return cnt;
}

int solve() {
  int max = 1;
  int left = 0;
  int right = 0;

  while (right < N) {
    s[arr[right]]++;
    while (left < right) {
      if (count() <= 2) {
        if (right - left + 1 > max) {
          max = right - left + 1;
        }
        break;
      }
      s[arr[left]]--;
      left++;
    }
    right++;
  }
  return max;
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cout << solve() << '\n';
  return 0;
}