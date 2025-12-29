#include <iostream>

using namespace    std;

int    main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int    sum = 0;    
    for (int i = 0; i < 6; i++) {
        int    n;
        cin >> n;
        sum += n;
    }
    cout << sum * 5 << '\n'; 
}