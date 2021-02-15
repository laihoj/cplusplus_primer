/*
This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. 
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. 
i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Log {
    private:
        string order_id;
    public:
        Log() {
            order_id = "";
        }
        Log(string s) {
            order_id = s;
        }
};

void record(string order_id);
struct Log get_last(int i);

typedef struct Log log;

class Logger {
    
    public:
        Log logArray[0];
        int size = 0;
        
        // Logger() : {};
        void record(string order_id) {
            Log tempArray [size + 1];// = logArray;
            // copy(begin(logArray), end(logArray), begin(tempArray));

            // logArray = ;
        };
    
    
    private:
        void record(string order_id);
};



/**fail
 * todo
 * figure out this syntax: Logger() : {};
 * study difference between std::array, std::vector, std::deque, etc
 * study difference between std::array and [] and new []
 * 
 */


int main() {
    return 0;
}