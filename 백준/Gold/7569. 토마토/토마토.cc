#include <iostream>
#include <queue>

#define MAX 100

using namespace std;

typedef struct point {
  int z;
  int y;
  int x;
} point;

int X, Y, Z;

int board[MAX][MAX][MAX];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void print() {
  cout << "==========\n";
  for (int z = 0; z < Z; z++) {
    cout << "\nfloor: " << z << '\n';
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        cout << board[z][y][x] << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
  }
}

void bfs() {
  queue<point> q;
  point cur;

  for (int z = 0; z < Z; z++) {
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        if (board[z][y][x] == 1) {
          q.push({z, y, x});
        }
      }
    }
  }

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int i = 0; i < 6; i++) {
      int nz = cur.z + dz[i];
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      if (nx < 0 || nx >= X || ny < 0 || ny >= Y || nz < 0 || nz >= Z ||
          board[nz][ny][nx] != 0)
        continue;

      q.push({nz, ny, nx});
      board[nz][ny][nx] = board[cur.z][cur.y][cur.x] + 1;
    }
  }
}

int solve() {
  int time = 0;

  bfs();

  for (int z = 0; z < Z; z++) {
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        if (board[z][y][x] == 0) {
          return -1;
        }
        if (board[z][y][x] > time) {
          time = board[z][y][x];
        }
      }
    }
  }

  return time - 1;
}

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> X >> Y >> Z;
  for (int z = 0; z < Z; z++) {
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        int n;
        cin >> n;
        board[z][y][x] = n;
      }
    }
  }

  cout << solve() << '\n';
}