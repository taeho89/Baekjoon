#include <iostream>

using namespace    std;

int    main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int    r;
    cin >> r;
    if (r >= 620 && r <= 780) {
        cout << "Red" << '\n';
    } else if (r >= 590 && r < 620) {
        cout << "Orange" << '\n';
    } else if (r >= 570 && r < 590) {
        cout << "Yellow" << '\n';
    } else if (r >= 495 && r < 570) {
        cout << "Green" << '\n';
    } else if (r >= 450 && r < 495) {
        cout << "Blue" << '\n';
    } else if (r >= 425 && r < 450) {
        cout << "Indigo" << '\n';
    } else if (r >= 380 && r < 425) {
        cout << "Violet" << '\n';
    }
}