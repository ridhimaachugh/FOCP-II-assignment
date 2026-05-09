#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000000;
int distinct_prime_count[MAXN + 1];

void sieve() {
    for (int i = 2; i <= MAXN; ++i) {
        if (distinct_prime_count[i] == 0) {
            for (int j = i; j <= MAXN; j += i) {
                distinct_prime_count[j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n";
        } else {
            cout << (1LL << distinct_prime_count[n]) << "\n";
        }
    }

    return 0;
}
