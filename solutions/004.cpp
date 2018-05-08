#include <iostream>

using namespace std;

bool is_palindrome(int n) {
    string str = to_string(n);
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size()-1-i]) return false;
    }
    return true;
}

int solve() {
    int max = 0;
    for (int a = 999; a >= 100; a--) {
        for (int b = a; b >= 100; b--) {
            int n = a*b;
            if (is_palindrome(n)) {
                max = (max<n)?n:max;
            }
        }
    }
    return max;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
