#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class MovieTicket {
    map<int, set<int>> bookings;
    const int CAPACITY = 100;

public:
    bool BOOK(int X, int Y) {
        if (bookings[Y].size() >= CAPACITY || bookings[Y].count(X)) {
            return false;
        }
        bookings[Y].insert(X);
        return true;
    }

    bool CANCEL(int X, int Y) {
        if (bookings[Y].erase(X) > 0) {
            return true;
        }
        return false;
    }

    bool IS_BOOKED(int X, int Y) {
        return bookings[Y].count(X);
    }

    int AVAILABLE_TICKETS(int Y) {
        return CAPACITY - bookings[Y].size();
    }
};

int main() {
    MovieTicket m;

    cout << m.BOOK(1, 101) << endl;
    cout << m.BOOK(2, 101) << endl;
    cout << m.IS_BOOKED(1, 101) << endl;
    cout << m.AVAILABLE_TICKETS(101) << endl;
    cout << m.CANCEL(1, 101) << endl;
    cout << m.AVAILABLE_TICKETS(101) << endl;

    return 0;
}
