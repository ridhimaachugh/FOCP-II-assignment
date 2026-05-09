#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> freq(1001, 0);

        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        long long alex = 0, bob = 0;
        int turn = 0;

        
        for (int val = 1000; val >= 1; val--) {
            if (freq[val] == 0) continue;

            if (freq[val] == 1) {
                if (turn == 0) alex += val;
                else bob += val;

                turn ^= 1; 
            } 
            else {
                if (turn == 0) {
                    alex += val;
                    bob += val;
                } else {
                    bob += val;
                    alex += val;
                }
            }
        }

        if (alex > bob) cout << "Alex\n";
        else cout << "Bob\n";
    }

    return 0;
}
