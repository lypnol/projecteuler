#include <iostream>

using namespace std;

int solve() {
    int sum = 0;

    for (int i = 3; i < 1000; i++) {
        if (i%5 == 0 || i%3 == 0) sum += i;
    }
    
    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
