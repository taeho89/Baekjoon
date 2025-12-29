#include <iostream>

using namespace    std;

int    main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int a, b, c;
    cin >> a >> b >> c;
    if (c == a + b) {
        cout << "correct!" << '\n';
    } else {
        cout << "wrong!" << '\n';
    }
}