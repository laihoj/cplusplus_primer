/*
This problem was asked by Facebook.

Given a stream of elements too large to store in memory, 
pick a random element from the stream with uniform probability.
*/

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
//if stream not too large to store in memory, then just
//load stream to an array
//select array[rand(0, array.length)]

//instead, select some element, and then 
//look at elements one at a time and with probablity of (1 / length) select that new element instead

int main() {
      srand (time(NULL));

    int stream[] = {1, 4, 6, 3, 2, 77, 8, 1, 4, 2, 4, 6, 7}; //stream represented here as list for convenience
    int stream_ends_at = (sizeof(stream) / sizeof(*stream));

    int selected_element = stream[0];
    for (int i = 1; i < stream_ends_at; i++) { //keep reading elements from stream until it ends
        int next_element = stream[i]; //get the next element
        int random_int = 1 + (rand() % static_cast<int>(i - 1 + 1)); //generate random integer between 1 and i

        if (random_int == 1) { //probability for any element to be selected is 1 / i
            selected_element = next_element;
        }
    }
    cout << selected_element << endl;
    return 0;
}