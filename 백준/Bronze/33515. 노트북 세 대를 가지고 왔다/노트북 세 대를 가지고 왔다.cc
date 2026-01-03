#include <iostream>

using namespace std;

int    main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int t1, t2;
    cin >> t1 >> t2;
    cout << min(t1, t2);
    return 0;
}