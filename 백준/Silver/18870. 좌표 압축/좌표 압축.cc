#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
vector<int> v2;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int n;

    cin >> n;
    arr.push_back(n);
  }
  v2 = arr;

  sort(v2.begin(), v2.end());
  v2.erase(unique(v2.begin(), v2.end()), v2.end());

  for (int i = 0; i < N; i++) {
    cout << lower_bound(v2.begin(), v2.end(), arr[i]) - v2.begin() << " ";
  }
  cout << "\n";
}