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





//can do some clever things on the first run to improve best case
//to find some edge cases: 
// - false if all i are even and k is odd
// - false if k > sum(i)

int twoNumbersInListAddToK(int list[], int size, int k) {
    for (int i = 0; i < size; i++) {
        for (int ii = i; ii < size; ii++) {
            if (i != ii) {
                if (list[i] + list[ii] == k) {
//                    std::cout << list[i] << " " << list[ii]  << std::endl; //troubleshooting
                    return 1;
                }
            }
        }
    }
    return 0;
}

#include <vector>


int twoNumbersInListAddToKSinglePass(int list[], int size, int k) {
    //get each partition of length 2 of k
        //generate each pair a, b such that a + b = k
            //k = 17, => pairs = {(0, 17), (1, 16), (2, 15), ..., (8, 9)}
            //note that len(pairs) ~= k/2
                //if k is even, (8) => ((0, 8), (1, 7), (2, 6), (3, 5), (4, 4)) => len(pairs(8)) = 5 = k/2+1
                //if k is odd, (7) => ((0, 7), (1, 6), (2, 5), (3, 4)) => len(pairs(7)) = 4 = ceil(k/2)
    unsigned int numPairs = (k%2) ? (k + 2 - 1) / 2/*true is odd*/ :  /*false is even*/ k / 2 + 1;
    std::vector<std::vector<int>> ls;
    ls.resize(numPairs, std::vector<int>(2));
    for (int i = 0; i < numPairs; i ++) {
        ls[i][0] = i;
        ls[i][1] = k - i;
    }
    std::vector<int> keepingTrack(numPairs, 0);

    //iterate the list such that each item in list i is removed from each pair, if present
    for (int i = 0; i < size; i++) {
        for (int ii = 0; ii < numPairs; ii++) {
            if (list[i] == ls[ii][0]) {
                keepingTrack[ii] += 1;
                ls[ii][0] = -1; //so that value not counted twice
            } else if (list[i] == ls[ii][1]) {
                keepingTrack[ii] += 1;
                ls[ii][1] = -1;
            }
            if (keepingTrack[ii] == 2)
                return 1;
        }
    }


    //by the time any pair has both numbers removed, return true
    //else return false

    return 0;
}

int main() {
    // int res = 
    
    int list1 [4] = {10, 15, 3, 7};
    int  k = 17;

    std::cout << twoNumbersInListAddToK(list1, 4, k)  << std::endl;
    std::cout << twoNumbersInListAddToKSinglePass(list1, 4, k) << std::endl;
    


    int list2 [10] = {10, 15, 2, 7, 10, 10, 15, 2, 7, 10};
    int k2 = 18;

    std::cout << twoNumbersInListAddToK(list2, 10, k2) << std::endl;
    std::cout << twoNumbersInListAddToKSinglePass(list2, 10, k2) << std::endl;
    
    

}
