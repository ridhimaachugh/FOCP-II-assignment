#include <iostream>

using namespace std;

long long getXor(long long n) {
    long long rem = n % 4;
    if (rem == 0) return n;
    if (rem == 1) return 1;
    if (rem == 2) return n + 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    if (!(cin >> L >> R)) return 0;

    long long ans = getXor(R) ^ getXor(L - 1);

    if (ans % 2 == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }

    return 0;
}
