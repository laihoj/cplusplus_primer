//medium problem?

/*
This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
*/

/*
object oriented implementation in c++
*/

using namespace std;

class Pair {    
    public:
        Pair(int f, int l) {
            first = f;
            last = l;
        }
        int getFirst() {
            return first;
        }

        int getLast() {
            return last;
        }
    private:
        int first, last;
};

int car(Pair p) {
    return p.getFirst();
};

int cdr(Pair p) {
    return p.getLast();
};

Pair cons(int a, int b) {
    Pair pair(a,b);
    return Pair(a, b);
}

#include <iostream>

int main() {

    cout << "car(cons(3, 4)), expecting 3, got " << car(cons(3, 4)) << endl;
    cout << "cdr(cons(3, 4)), expecting 4, got " << cdr(cons(3, 4)) << endl;
    return 0;
}