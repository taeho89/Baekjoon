#include <iostream>
#include <deque>

using namespace std;

int main(void) {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    string cmd;
    int size;
		string	line;
    deque<int> d;
    cin >> cmd >> size >> line;
		int	n = 0;
		for (int j = 0; j < line.length(); j++) {
			if (line[j] == '[' || line[j] == ']') continue ;
			if (line[j] >= '0' && line[j] <= '9') {
				n = n * 10 + line[j] - '0';
			}
			if (line[j] == ',') {
				d.push_back(n);
				n = 0;
			}
		}
		if (n != 0) {
			d.push_back(n);
		}

    int pos = 1;
		int	flag = 0;
    for (int j = 0; j < cmd.length(); j++) {
      if (cmd[j] == 'R') {
        pos *= -1;
      } else if (cmd[j] == 'D') {
				if (d.empty()) {
					flag = 1;
					break ;
				}
				if (pos > 0) {
					d.pop_front();
				} else {
					d.pop_back();
				}
      } else {
				flag = 1;
				break ;
      }
    }

		if (flag) {
			cout << "error\n";
			continue ;
		}

		cout << "[";
		if (!d.empty()) {
			if (pos > 0) {
				for (deque<int>::iterator it = d.begin(); it != d.end() - 1; it++) {
					cout << *it << ",";
				}
				cout << *(d.end() - 1);
			}
			else {
				for (deque<int>::iterator it = d.end() - 1; it != d.begin(); it--) {
					cout << *it << ",";
				}
				cout << *d.begin();
			}
		}
		cout << "]\n";
  }
}
