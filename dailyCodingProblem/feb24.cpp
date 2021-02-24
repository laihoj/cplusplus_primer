/*
This problem was asked by Google.

Given an array of integers and a number k, 
where 1 <= k <= length of the array, 
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. 
You can modify the input array in-place and you do not need to store the results. 
You can simply print them out as you compute them.
*/

//easy solution: nested for loops. 
    //O(k) space but O(n^2) time worst case (k == array.length)
    //actually case k == array.length time is O(n) (one pass)
    //case k == length / 2 => 
    //time complexity (k * (length - k + 1)) => k*input - k^2 + k, 1 < k < input
    //[6], 3 => [0-2],[1-3],[2-4],[3-5] <= 3 * 4 == 3 * (length + 1 - 3)
    //[6], 1 => [0],[1],[2],[3],[5],[5] <= 1 * 6 == 1 * (length + 1 - 1)
    //[6], 6 => [0-5] <= 6 * 1 == 6 * (length + 1 - 6)
    //nearly linear performance when k is small or k is close to input.length
    //when input is very large, then k * (input - k + 1) is approx == k * input

// for int i = 0 until array.length 
// int max of subarray = 0
// for int ii = i until min(i + 3, array.length)
    // if array(ii) > max of subarray ? max = array(ii)
// cout << max of subarray << endl;

//hmm more sophisticated:
//i (first value of subarray) is no longer used after subarray assessed
//i in array can be modified

//how to calculate this in one pass?
//can I pull a mathsy sneaky?
//guess: rolling cumulative sum: add new value, subtract old value
//what can i keep track of 
    //index of largest value
    //

//experimental attempt for a single pass // i dont think this is fruitful
//current subarray sum = 0 
//current subarray max = 0
//value to remove
//for i in input
    //if input(i) > max
        //max = input(i)
    //if i >= k                         //we have departed the previous subarray
        //value to remove = input(i-k)
        //sum -= value to remove
    //sum += input(i)

#include <iostream>

using namespace std;

int main() {

    const int array_length = 6;
    int input[array_length] = {10, 5, 2, 7, 8, 7};
    int k = 3;
    for (int i = 0; i < array_length - k + 1; i++) {
        int temp_max = 0;
        for (int ii = i; ii < min(i + k, array_length); ii++) 
            (input[ii] > temp_max) ? temp_max = input[ii] : 1;
        cout << temp_max << endl;
    }

    return 0;
}