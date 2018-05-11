#include <iostream>

using namespace std;

uint64_t solve() {
    uint64_t count = 0;
    int day = 0, d = 1, m = 1, y = 1900;

    while (!(d == 31 && m == 12 && y == 2000)) {
        if (d < 28) {
            d++;
        } else {
            // if february
            if (m == 2) {
                // if leap year
                if (y % 4 == 0 && !(y % 100 == 0 && y % 400 != 0)) {
                    if (d == 28) d++;
                    else {
                        d = 1;
                        m = m%12+1; if (m == 1) y++;
                    }
                } else {
                    d = 1;
                    m = m%12+1; if (m == 1) y++;
                }
            } else if (m == 9 || m == 4 || m == 6 || m == 11) {
                if (d < 30) d++;
                else {
                    d = 1;
                    m = m%12+1; if (m == 1) y++;
                }
            } else {
                if (d < 31) d++;
                else {
                    d = 1;
                    m = m%12+1; if (m == 1) y++;
                }
            }
        }
        day = (day+1)%7;
        if (day == 6 && d == 1 && y >= 1901) count++;
    }

    return count;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
