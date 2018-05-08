#include <iostream>

using namespace std;

int solve() {
    for (int a = 1; a <= 1000; a++) {
        for (int b = a; b <= 1000; b++) {
            int c = 1000 - (a+b);
            if (a*a + b*b == c*c) {
                return a*b*c;
            }
        }
    }
    return -1;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
