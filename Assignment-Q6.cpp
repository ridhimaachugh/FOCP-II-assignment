#include <iostream>
#include <map>
using namespace std;

class Bank {
    map<int, double> accounts;

public:
    bool CREATE(int X, int Y) {
        if (accounts.find(X) == accounts.end()) {
            accounts[X] = Y;
            return true;
        }
        accounts[X] += Y;
        return false;
    }

    bool DEBIT(int X, int Y) {
        if (accounts.find(X) == accounts.end() || accounts[X] < Y) {
            return false;
        }
        accounts[X] -= Y;
        return true;
    }

    bool CREDIT(int X, int Y) {
        if (accounts.find(X) == accounts.end()) {
            return false;
        }
        accounts[X] += Y;
        return true;
    }

    double BALANCE(int X) {
        if (accounts.find(X) == accounts.end()) {
            return -1;
        }
        return accounts[X];
    }
};

int main() {
    Bank b;

    cout << b.CREATE(101, 5000) << endl;   // true
    cout << b.CREDIT(101, 2000) << endl;   // true
    cout << b.DEBIT(101, 1000) << endl;    // true
    cout << b.BALANCE(101) << endl;        // 6000
    cout << b.BALANCE(102) << endl;        // -1

    return 0;
}
