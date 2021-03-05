/*
This problem was asked by Facebook.

A builder is looking to build a row of N houses that can be of K different colors. 
He has a goal of minimizing cost while ensuring that 
no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost 
to build the nth house with kth color, 
return the minimum cost which achieves this goal.
*/

/*
for example
k=6 colors
n=4 houses

A,  B,  C,  D,  E, F
5,  10, 13, 21, 7, 30
3,  9,  3,  24, 2, 31
4,  11, 15, 26, 7, 25
3,  15, 12, 20, 7, 27

here the correct solution would be (0, A), (1, E), (2, A), (3, E) => 5 + 2 + 4 + 7 = 18
*/

#include <iostream>

using namespace std;

int main() {

    //dijkstra: convert matrix to graph
    //minimum_cost
    //iterate over each color
        //iterate over each house (excluding color index)
            //find minimum cost of house 
            //accumulate to minimum_cost
            //note index

    int input[4][6] = {
        {5,  10, 13, 21, 7, 30}, 
        {3,  9,  3,  24, 2, 31}, 
        {4,  11, 15, 26, 7, 25}, 
        {3,  15, 12, 20, 7, 27}
    };

    int minimum_total_cost = 0;
    for (int i = 0; i < sizeof(input[0])/sizeof(input[0][0]); i++) {
        //for each color find cheapest house
        //starting guess is house at index 0 to be cheapest
        int cheapest_house_in_color_i = input[0][i];
        int index_of_cheapest_house_in_color_i = 0;
        for (int ii = 1; ii < sizeof(input)/sizeof(input[0]); ii++) {
            
            if (ii != index_of_cheapest_house_in_color_i && input[i][ii] < cheapest_house_in_color_i) {
                cheapest_house_in_color_i = input[ii][i];
                index_of_cheapest_house_in_color_i = i;
            }
            
        }
        cout << "index_of_cheapest_house_in_color_i "<< index_of_cheapest_house_in_color_i 
            << " cheapest_house_in_color_i " << cheapest_house_in_color_i 
            << endl;
            minimum_total_cost += cheapest_house_in_color_i;
    }


    cout << minimum_total_cost << endl;
    return 0;
}