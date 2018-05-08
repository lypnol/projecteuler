#include <iostream>

using namespace std;

int solve() {
    int sum = 2;
    int fn = 2, fn_1 = 1, tmp;
    while (fn < 4000000) {
        tmp = fn_1;
        fn_1 = fn;
        fn = fn + tmp;
        if (fn%2 == 0) sum += fn;
    }

    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
