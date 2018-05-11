#include <iostream>
#include <unordered_set>
#include <vector>
#define N 30000

using namespace std;

uint64_t d(uint64_t n) {
    uint64_t sum = 1, i;
    for (i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (n/i != i) sum += n/i;
        }
    }
    return sum;
}

uint64_t solve() {
    unordered_set<uint64_t> seen;
    vector<uint64_t> abundants;

    for (uint64_t n = 12; n < N; n++) {
        if (d(n) > n) abundants.push_back(n);
    }
    
    for (int i = 0; i < abundants.size(); i++) {
        for (int j = i; j < abundants.size(); j++) {
            uint64_t s = abundants[i]+abundants[j];
            seen.insert(s);
        }
    }

    uint64_t sum = 0;
    for (uint64_t n = 1; n <= N; n++) {
        if (seen.find(n) == seen.end()) sum += n;
    }

    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
