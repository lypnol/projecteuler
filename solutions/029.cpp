#include <iostream>
#include <vector>
#include <unordered_map>
#define MAXN   101

using namespace std;
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

bool equal(int a1, int a2, int b1, int b2, unordered_map<int, int>* factorized) {
    unordered_map<int, int>::iterator itr;
    if (factorized[a1].size() != factorized[a2].size()) return false;
    for (itr = factorized[a1].begin(); itr != factorized[a1].end(); itr++) {
        if (factorized[a2].find(itr->first) != factorized[a2].end() && 
            factorized[a2][itr->first]*b2 == itr->second*b1) continue;
        return false;
    }
    return true;
}

int solve() {
    int x = 2, y = 100;
    unordered_map<int, int> factorized[y+1];
    sieve();

    for (int n = 2; n <= y; n++) {
        vector<int> factors = getFactorization(n);
        factorized[n][factors[0]] = 1;
        for (int i = 1; i < factors.size(); i++) {
            if (factors[i] == factors[i-1]) factorized[n][factors[i]]++;
            else factorized[n][factors[i]] = 1;
        }
    }

    double count = 0;
    for (int a1 = x; a1 <= y; a1++)
    for (int b1 = x; b1 <= y; b1++) {
        int freq = 1;
        for (int a2 = x; a2 <= y; a2++)
        for (int b2 = x; b2 <= y; b2++)
        {
            if (a1 == a2 && b1 == b2) continue;
            if (equal(a1, a2, b1, b2, factorized)) freq++;
        }
        count += 1/(double)freq;
    }

    return (int)round(count);
}

int main() {
    cout << solve() << "\n";
    return 0;
}
