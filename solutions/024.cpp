#include <iostream>

using namespace std;

string solve() {
    int n = 1000000, i;
    string perm = "0123456789";
    for (i = 1; i < n; i++) {
        next_permutation(perm.begin(), perm.end());
    }
    return perm;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
