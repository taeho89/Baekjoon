#include <iostream>

using namespace    std;

int    main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int    N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long    lt, wt, le, we;
        cin >> lt >> wt >> le >> we;
        if (lt * wt > le * we) {
            cout << "TelecomParisTech\n";
        } else if (lt * wt < le * we) {
            cout << "Eurecom\n";
        } else {
            cout << "Tie\n";
        }
    }
}