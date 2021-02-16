/*
This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. 
Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

//this is a hard mathsy question, I'd refresh my knowledge on combinations and permutations for this.
//it also looks like a question about partitions, 
    //for which if the set of positive integers X is all positive integers (or general case), 
    //then there is a known formula by Ramanujan which really accurately predicts the number of partitions (doesn't solve)

//generate all combinations that sum to N, then for those combos, generate all permutations. 
//Or just generate all permutations in the first place
    //how to generate all combinations algorithmically?
    //might like to do recursive but that might be pretty nuts qua memory for larger numbers
    //base case and other case
    
        /*
        N = 4
        res = 0
        X = {1, 3, 5}

        recursolve(N, X):
            for(x in X):
                if N - x > 0:
                    recursolve(N - x, X) //set not illegal yet, proceed
                elif N - x < 0: //set didn't add up to N
                    return 0
                elif N - x == 0: //set adds up to N
                    return 1;
        */

#include <iostream>
#include <vector>

using namespace std;

int numberOfUniqueOrderedWaysToClimbStairs(int N, vector<int> X) {
    int res = 0;

    // for (unsigned int i = 0; i < sizeof(X) / sizeof(X[0]); i = i + 1) {
    for(const int &x : X) {
        if (N - x > 0 ) {
            res += numberOfUniqueOrderedWaysToClimbStairs(N - x, X);
        //} else if (N - x < 0 ) { //nvm, not needed

        } else if (N - x == 0) {
            res += 1;
        }

        // cout << x << endl;
    }
        // return 0;
    // }
    return res;
}

int main() {

    int N = 21;
    vector<int> X = {1, 2, 3, 4, 5, 6};
    

    auto start = std::chrono::system_clock::now();
    cout << numberOfUniqueOrderedWaysToClimbStairs(N, X) << endl;
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "N = " << N
              << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";


    return 0;
}