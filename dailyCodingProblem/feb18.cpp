/*
This problem was asked by Google.

The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
*/

/*
pi is defined as the ratio of circle circumference by diameter. => 2 * pi * r
circle area is pi * r^2
circle equation is x^2 + y^2 = r^2

if i guess the value of pi as a starting point (to then further iterate on), what will look wrong?

suppose generate random points in a square between ([-x, x], [-y, y]).
Then so many points should be inside the circle (distance from center <= r)
Nah, that doesn't have much to do with pi //nvm
square area is 4*r^2, and circle area is pi*r^2
calculate points in SqA (all points) and CA (points of less distance than r). Those sums will have ratio of 4:pi 

how to get accuracy? More points? Bigger circle? 
Could make solution iterative with error margin. 
No, because error margin would require info on pi's value beforehand
Could look at digits, and if they don't change over so many iterations, then probably we're good

*/

// let's say r = 1
// Square has width 2, height 2

//not gonna bother with functions, instead everything goes procedurally in main

#include <iostream>

using namespace std;

int main() {

    float pi_guess = 3;

    int r = 1;

    int i = 1;
    int i_limit = 5000000;
    int points_in_circle = 0;
    while(i < i_limit) {
        //create random point inside square
        //check distance from middle
        //if inside circle, accumulate counter

        //x, y are values between -1 and 1
        //A_square = 4
        //A_circle = 3.1415...
        //origin at 0,0 is nice

        

        
        

        //estimate new value in batches of 10000 (arbitrary, suspected to improve performance)
        for (int ii = 0; ii < 10000; ii++) {
            float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (2*r)) - 1;
            float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (2*r)) - 1;
            float d = sqrt(x * x + y * y);
            // cout << "d " << d << endl;
            bool point_is_in_circle = d < 1;
            if (point_is_in_circle) //count how many points are in circle
                points_in_circle++;

            i++;
        }
        
        // cout  << endl;

        float new_estimate = 4.0 * points_in_circle / i; //calculate next estimate

        //check if new guess is close to previous guess, if so then we have reached sufficient accuracy
        float diff_prev_next_estimate = abs(new_estimate - pi_guess); 
        bool accurate_enough = diff_prev_next_estimate < 0.0001;
        if (accurate_enough && pi_guess > 0.1) // pi>0.1 helps against first iteration where float pi is close to 0
            break;

        pi_guess = static_cast <float> (new_estimate);

        cout << "pi_guess: " << pi_guess 
             << ", accuracy: " << diff_prev_next_estimate 
             << ", points in circle: " << points_in_circle 
             << ", i: " << i << endl;
        
    }

    cout << pi_guess << endl;

    return 0;
}