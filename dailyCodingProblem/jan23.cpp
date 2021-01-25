/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

//sounds like partitions

//simple solution
//compare each number to each other number
//double for loop
//start ii at i to not double compare

//complicateder solution
//partition k and check for any partition to be a subset of given list
//assuming list contents all positive


#include <iostream>

int list1 [4] = {10, 15, 3, 7};

int  k = 17;



//can do some clever things on the first run to improve best case
//to find some edge cases: 
// - false if all i are even and k is odd
// - false if k > sum(i)

int twoNumbersInListAddToK(int list[], int size, int k) {
    for (int i = 0; i < size; i++) {
        for (int ii = i; ii < size; ii++) {
            if (i != ii) {
                if (list1[i] + list1[ii] == k) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int res = twoNumbersInListAddToK(list1, 4, k);
    std::cout << res;
}
