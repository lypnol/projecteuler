#include <iostream>

using namespace std;

uint64_t solve() {
    uint64_t sum = 1;
    uint64_t size = 3;
    while (size <= 1001) {
        uint64_t topleft = size*size;
        uint64_t topright = topleft - size + 1;
        uint64_t bottomright = topright - size + 1;
        uint64_t bottomleft = bottomright - size + 1;
        sum += topleft + topright + bottomright + bottomleft;
        size += 2;
    }
    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
