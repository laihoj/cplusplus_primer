/*
This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/


//lists A and B must intersect at some point
//assuming node values are unique identifiers

//summarise contents of one list into a constant space variable. Never mind
//convert A into string "3 7 8 10". nvm

//create new data structure (hashmap) 
    //and one item for one list at a time add to hashmap, 
    //and compare hashmap size before after each step


#include <iostream>
#include <map>


using namespace std;

int main() {

    int A[6] = {3, 7, 9, 10, 12, 6};
    int B[6] = {99, 1, 8, 19, 12, 5};
    map<int, bool> thing;
    for (auto x : A) {
        thing[x] = true;
    }
    unsigned int length = 6;

    for (auto x : B) {
        thing[x] = true;
        if(thing.size() == length) {
            cout << x << endl;
            break;
        }
        length = thing.size();
    }
    return 0;
}