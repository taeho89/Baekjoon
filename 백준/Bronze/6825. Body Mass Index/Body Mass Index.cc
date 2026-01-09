#include <iostream>

using namespace    std;

int    main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    double    h, w;
    
    cin >> w >> h;
    double bmi;
    bmi = w / (h * h);
    if (bmi > 25) {
        cout << "Overweight";
    } else if (bmi >= 18.5 && bmi <= 25) {
        cout << "Normal weight";
    } else {
        cout << "Underweight";
    }
    return 0;
}