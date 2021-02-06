/*
This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

//i like to start with a simple first guess that just works. Usually that yields insights for optimisations.

//could be recursive: take a number named cumSum, and a list of all non-adjacent numbers (NAN). then, for each pairing of cumSum and some NAN, repeat the earlier step
    //recursive: think base case and null case
    /*
    solver(int cumulativeSum, int[] nan)
        for i = 0, i++
            temp = nan[i]
            non_adjacent_numbers = concat(nan[before i - 1], nan[after i + i])

    */
//mega inefficient tho

//break down problem into creating subsets and performing cumulative sum computation
//in other words, compute all possible combinations, and then select the largest sum
//generally speaking, longer lists will more likely have larger sum
    //the two longest possible lists are those with indices [0,2,4,6,...] and [1,3,5,7,....]
//however, naturally the distances between two subsequent non-adjacent numbers can be different than just 1 step
//one way conceptually to create largest sum from a set where some elements must be excluded is to exclude the smallest members of that set.
//sorting the array would work, then sum the last half.
//however, then ofc we have lost info on adjacency.

//for the result to be a sum, at least two numbers must be used.
//we might have fully negative lists, where the largest sum ... isnt obvious on further thought. 

//what if we do one pass to calculate sum of all members as a starting value

//what if we approach this as a sort of graph problem?
    //how do graphs work again... 
//if process always goes one way, then can start anywhere but at last two elements
//sum(0,2,4,6,...) >= sum(0,4,6,...) so long as no neg numbers present
    //in other words, skipping the first adjacent number is never helpful, unless you skip also the first non-adjacent number (when all are pos)
    //case all elements are pos (do one pass to check)
    //generate all relevant lists. 
    //given [2, 4, 6, 2, 5]
        //(1) [2, 6, 5] 0,2,4
        //(2) [2, 2] 0,3
        //  [2, 5] 0,4 is strictly worse than (1) as in 0,2,4 if all pos
        //(3) [4,2] 1,3
        //(4) [4,5] 1,5
        //  [6, 5] 2,4 is strictly worse than (1) as in 0,2,4 if all pos

//how many subsets can be generated from a list of len(n)
//[0,1,2,3,4,5,...,n] ->
    //generate all subsets
    //exluce those subsets that violate adjacency
    //calculate sums
    //return get largest

//mby something like the following:
    //k = 0; cumulative_sum = 0;
    //step 1: take element at k or k + 1 (whichever is larger) then update k. cumulative_sum += input[k]
    //step 2->n: take element at k + 2 or k + 3 (whichever is larger) then update k. cumulative_sum += input[k]
    //repeat this way, and return whatever the value. 
    //Nice time and space performance, but no guarantee that will return correct values
        //suppose input = [-100, -200, 5,4,3,4,5,5,5,3,5,5,4]

//so long there are at least 2 positive non-adjacent values amidst the negative values 
    //then the correct solution is to exclude all negative values
    //and proceed to include only positive numbers (0 is positive)
//if there is 1 or fewer positive numbers, then any correct result will be the sum of exactly 2 elements
    //find 2 smallest (least negative)->actually biggest numbers. 
        //if non-adjacent, return their sum
        //if adjacent, take smallest, and find 3rd smallest number that is non-adjacent

//having a brain-wave: instead of at beginning or end, and search for next-biggest non-adjacent number
//copy array
//get index of biggest value = k
    //(one pass, compare subsequent integers and store index and value of current biggest)
//set values input[k-1] and input[k+1] to -1 or illegal. TODO handle edge case of biggest being first or last value
//find index of next biggest value
        

