#include <iostream>
#include <fstream>
#include <algorithm>
#define N 5163

using namespace std;

void load_names(string* names) {
    ifstream file = ifstream("resources/p022_names.txt");
    string name;
    int i = 0;
    while (getline(file, name, ',')) {
        names[i] = name.substr(1, name.size()-2);
        i++;
    }
    file.close();
}

uint64_t score(string s) {
    uint64_t c = 0;
    for (int i = 0; i < s.size(); i++) c += (s.at(i)-'A'+1);
    return c;
}

uint64_t solve() {
    string names[N];
    uint64_t sum = 0;

    load_names(names);
    sort(names, names+N);

    for (uint64_t i = 0; i < N; i++) {
        sum += score(names[i])*(uint64_t)(i+1);
    }

    return sum;
}

int main() {
    cout << solve() << "\n";
    return 0;
}
