#include <iostream>

using namespace    std;

int    N;
int    arr[101];
int    target;

int    main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int    n;
        cin >> n;
        arr[i] = n;
    }
    
    cin >> target;
    
    int     cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == target) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}