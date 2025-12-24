#include <climits>
#include <iostream>

int solve();

using namespace std;

int map[500][500];
int max_h = 0;
int min_h = 256;
int min_time = INT_MAX;
int min_pivot = 256;
int t = 0;
int block;

int n, m, h;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // 입력
  cin >> n >> m >> block;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> h;
      if (h > max_h) {
        max_h = h;
      }
      if (h < min_h) {
        min_h = h;
      }
      map[i][j] = h;
    }
  }

  solve();
  cout << min_time << " " << min_pivot << "\n";
}

int put(int y, int x) {
  if (block == 0) {
    return -1;
  }
  map[y][x]++;
  block--;
  t++;
  return 0;
}

void pop(int y, int x) {
  map[y][x]--;
  t += 2;
  block++;
}

int get_need_block(int height) {
  int need = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      need += height - map[i][j];
    }
  }
  return need;
}

void set_height(int height) {
  int act_count;

  t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      act_count = map[i][j] - height;

      if (act_count >= 0) {
        t += 2 * act_count;
      } else {
        t += -1 * act_count;
      }
    }
  }
}

int solve() {
  for (int pivot = max_h; pivot >= 0; pivot--) {
    int need;

    need = get_need_block(pivot);

    if (need > block)
      continue;

    set_height(pivot);
    if (t < min_time) {
      min_pivot = pivot;
      min_time = t;
    }
  }

  return -1;
}