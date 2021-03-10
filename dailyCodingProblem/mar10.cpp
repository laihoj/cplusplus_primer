/*
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), 
    return the original sentence in a list. 
If there is more than one possible reconstruction, 
    return any of them. 
If there is no possible reconstruction, 
    then return null.

For example, given the set of words 
'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", 
    you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 
'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", 
    return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

//our function returns a list of a list of strings (list of chars)

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

//for each word in the dictionary, check if the sentence begins with that word
//if so, then return that match
//also conveniently, drop the first so many letters in that sentence

//performance: O(A*B*C) 
//where A is the length of the longest word in dict, B is the size of dict, and C is length of the sentence
pair<string, string> findFirstMatchingWord(vector<string> dict, string sentence) {
    pair<string, string> res;
    for(auto &word: dict) {
        if(sentence.rfind(word, 0) == 0) { //see if sentence begins with the word
            sentence.erase(0, word.length()); //drop the word in the sentence

            res = make_pair(word, sentence);
            return res;
        }
    }
    return res;
}

vector<string> doTheThing(vector<string> dict, string sentence) {
    vector<string> res;
    string temp = sentence;

    while(sentence.length() > 0) {
        pair<string, string> match = findFirstMatchingWord(dict, sentence);
        res.push_back(match.first);
        sentence = match.second;
    }

    return res;
}

int main() {
    vector<string> set_of_words_1 {"quick", "brown", "the", "fox"};
    string s_1 = "thequickbrownfox";

    //cout << findFirstMatchingWord(set_of_words_1, s_1).first << endl;
    //cout << findFirstMatchingWord(set_of_words_1, s_1).second << endl;

    vector<string> result = doTheThing(set_of_words_1, s_1);

    
    
    for (auto &set: result) {
            cout << set << " ";
    }
    cout << endl;

    vector<string> set_of_words_2 {"bed", "bath", "bedbath", "and", "beyond"};
    string s_2 = "bedbathandbeyond";

    vector<string> result_2 = doTheThing(set_of_words_2, s_2);

    for (auto &set: result_2) {
            cout << set << " ";
    }
    cout << endl;

    return 0;
}