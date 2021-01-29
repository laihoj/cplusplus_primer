/*
This problem was asked by Stripe.

Given an array of integers, 
    find the first missing positive integer in LINEAR TIME and CONSTANT SPACE. 
In other words, find the lowest positive integer that does not exist in the array. 
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include <iostream>


// I will consider 0 negative for this exercise because of provided example
/* guess 1
// first solution would be to have an index starting at 0 incremented by 1 in each step
    // compare the value of each item in the array to the index
        // if value == index, return index
        // else index ++
    // return index
//this solution will at worst have O(n^2) time complexity
*/



// first guess gives some insights: negative values can be discarded





/* guess 2

// if array is sorted, then lowest missing positive integer can be found in linear time

// for index = 1, i = 0 in Z+, i++
    // if input[i] == index
    // else if input[i] == index + 1
        // index ++
    // else return index++

// if I find a linear time sorting algorithm of constant space, then I can 

*/


//
/*
input = [1,2,2,2,2,2,2,2,4]

step 1
i = 0
index = 1
input[i] = 1 == index

step 2
i = 1
index = 1
input[i]= 2 == index + 1
index++

step 3
i = 2
index = 2
input[i] = 2 == i

...

step n
i = n-1
index = 2
input[i] = 4 != index AND != index +1
return i++

*/

/*
linear time sort:
// pass 1: find largest integer in input
// create array of size largest integer
// pass 2: for i = 0 until size
    // if input[i] > 0
        // input[i] ++
//
*/

/*
never mind sorting
input = [-1, -100, 0 1,2,2, 6,2,2,2,2,2,4] //messy input
int counter[input.len] //init array of length(input) with
for i = 0 while i < input.len //first pass: count occurrences of positive integers
    if input[i] > 0
        counter[i] ++
for i = 0 while i < input.len //second pass: find first index with 0 occurrences
    if counter[i] == 0
        return i
return i++ //if no index with 0 occurrences was found, return the next index
time complexity O(2n)
space complexity O(n)

*/

using namespace std;
#include <vector>

int findTheLowestPositiveIntegerThatDoesNotExistInTheArray(int input[], size_t arraySize) {
    vector<int> counter(arraySize, 0);

    int i = 0;
    for (i = 0; i < arraySize; i++) 
        if (input[i] > 0) //bother counting only positive values 
            counter[input[i]]++; //consider input value index for counter

    for (i = 1; i < arraySize; i++) 
        if (counter[i] == 0)
            return i;

    return i++;
}


int main() {
    int input[] = {-1, -100, 0, 1,2,2, 6,2,2,2,2,2,4}; //messy input
    int length = sizeof(input)/sizeof(input[0]);
    cout << findTheLowestPositiveIntegerThatDoesNotExistInTheArray(input, length) << endl;

    int input2[] = {4,56,8,90,5,2,1,45,89,0,0,-1, 1, 2, 3}; //messy input
    int length2 = sizeof(input2)/sizeof(input2[0]);
    cout << findTheLowestPositiveIntegerThatDoesNotExistInTheArray(input2, length2) << endl;

    return -1;
}
