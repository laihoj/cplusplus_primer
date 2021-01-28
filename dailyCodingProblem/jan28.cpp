/*
This problem was asked by Uber.

Given an array of integers, return a new array 
such that each element at index i of the new array 
is the product of all the numbers in the original array 
except the one at i.

For example, if our 
input was [1, 2, 3, 4, 5], the 
expected output would be [120, 60, 40, 30, 24]. 

If our input was [3, 2, 1], 
the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <vector>
#include <iostream>


// Using division:
// calculate cumulative multiplication (cm) of input in one pass
// make another pass where output[i] = cm / input[i]
// bam, done


//Follow-up: what if you can't use division?
//nested for loop passing input
//implementation uses O(n^2) time
void doTheThing(int input[], int size) {
    std::vector<int> output(size);
    for(int i = 0; i < size; i++) {
        int temp_mult = 1;
        for(int ii = 0; ii < size; ii++) {
            if (ii != i) 
                temp_mult *= input[ii];
        }
        output[i] = temp_mult;
    }

    for(int i = 0; i < size; i++) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int test1[5] = {1, 2, 3, 4, 5};
    doTheThing(test1, 5);

    int test2[4] = {3, 2, 1};
    doTheThing(test2, 3);


    return 0;
}