/*
This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

//for example, k = 2, s = abcde => res = it can be ab, bc, cd, de
//for example, k = 3, s = aaaaaaabbbbbbbbbvfaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbb

//looks like a string manipulation problem, might need to do several passes
//don't think I've solved this problem or type of problem yet, so have to start from scratch
//this was indeed gonna be hard

//lets see if a nested for loop gets the job done
//maybe recursive?

//start at index i
    //iterate forward until condition no longer holds
    //replace result if better than previous best
    //halt if result length is as long as or longer than the remainder of the input

#include <iostream>

using namespace std;


//what is the longest legal substring starting at each index?
//for each index
    //find the longest string
string doTheThing(string input, int k) {
    string res;// = "";
    if (input.length() == 0)
        return res;

    for (int i = 0; i < input.length() - 1; i++) {
        string distinct_letters;
        string temp_res;// = input.at(i);

        //cases: 2x2 matrix         //distinct < k,                //distinct = k
            //new letter,           add to distinct and tempres    return tempres
            //used letter,          add to tempres                  add to tempres
            
          
        //find longest substring starting at i
        for (int ii = i; ii < input.length() - 1; ii++) {
            char char_at_ii = input.at(ii);
            bool new_letter = distinct_letters.find(char_at_ii) == string::npos;  //is the letter seen before
            bool distinct_full = distinct_letters.length() == k;  //are new letters still allowed

            if (new_letter && distinct_full) { //new letter and unique letters is capped
                // cout << "substring about to become illegal"<< endl;
                break;
            } 

            if (new_letter && !distinct_full) {             //register new letter, and continue legally
                // cout << "new letter legally found"<< endl;
                distinct_letters.push_back(char_at_ii);
                temp_res.push_back(char_at_ii);
            }

            if (!new_letter) {          //if letter is seen before, it's legal to simply continue
                temp_res.push_back(char_at_ii);
            }
        }

        if (temp_res.length() > res.length()) {
            res.assign(temp_res);
        }

    }

    return res;
}

int main() {

    string s = "abcbadjfghjtdyb";
    int k = 2;
    cout << doTheThing(s, k) << endl;

    s.assign("aaaaaaabbbbbbbbbvfaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbb");
    k = 3;
    cout << doTheThing(s, k) << endl;
    
    k = 0;
    cout << doTheThing(s, k) << endl;

    k = 0;
    s.assign("");
    cout << doTheThing(s, k) << endl;

    return 0;
}