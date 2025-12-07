// input:
// 첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32,
// 64, 128 중 하나이다. 색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로
// 둘째 줄부터 마지막 줄까지 주어진다. 하얀색으로 칠해진 칸은 0, 파란색으로
// 칠해진 칸은 1로 주어지며, 각 숫자 사이에는 빈칸이 하나씩 있다.
//
// output:
// 첫째 줄에는 잘라진 햐얀색 색종이의 개수를 출력하고, 둘째 줄에는 파란색
// 색종이의 개수를 출력한다.
#include <iostream>

using namespace std;

void find_paper(int size);
void checked(int size, int x, int y);

int N;
int map[128][128];
int white = 0;
int blue = 0;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  find_paper(N);

  cout << white << '\n' << blue << '\n';
  return 0;
}

void find_paper(int size) {
  if (size == 0) {
    return;
  }

  for (int i = 0; i < N / size; i++) {
    for (int p = 0; p < N / size; p++) {
      int invalid = 0;
      int pos_x = p * size;
      int pos_y = i * size;
      int first = map[pos_x][pos_y];
      if (first == -1) {
        continue;
      }
      for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
          if (map[pos_x + j][pos_y + k] == first) {
            continue;
          } else {
            invalid = 1;
            break;
          }
        }
        if (invalid)
          break;
      }
      if (!invalid) {
        if (first)
          blue++;
        else
          white++;
        checked(size, pos_x, pos_y);
      }
    }
  }
  find_paper(size / 2);
}

void checked(int size, int x, int y) {
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      map[i][j] = -1;
    }
  }
}