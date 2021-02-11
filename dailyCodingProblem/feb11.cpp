/*
This problem was asked by Twitter.

Implement an autocomplete system. 
That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/

//create a preprocessed dictionary (map) of string, strings mappings
//for each word in set of strings
    //for each subset of the word that follows the logic 
        //deal => d, de, dea, deal
    //add to map at key of subset the word

//now the user may query this dictionary by a strint to receive all possible outputs 

//[dog, deer, deal] becomes
//map[d] => dog             // append to map[d] dog
//map[do] => dog            // append to map[do] dog
//map[dog] => dog           // append to map[dog] dog
//map[d] => dog, deer       // append to map[d] deer
//map[de] => deer           // append to map[de] deer
//map[dee] => deer          // append to map[dee] deer
//map[deer] => deer         // append to map[deer] deer
//map[d] => dog, deer, deal // append to map[d] deal
//map[de] => deer, deal     // append to map[de] deal
//map[dea] => deal          // append to map[dea] deal
//map[deal] => deal         // append to map[deal] deal

//end result is dictionary with content
    //map[d] => dog, deer, deal
    //map[do] => dog
    //map[dog] => dog
    //map[de] => deer, deal
    //map[dee] => deer
    //map[deer] => deer
    //map[dea] => deal
    //map[deal] => deal

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>




using namespace std;

vector<string> strings{"dog", "deer", "deal"};

// vector<string> autoCompletion(string s, vector<string> dictionary) {
//     sort(dictionary.begin(), dictionary.end());

// };

int main() {
    map<string, list<string>> preprocessedStrings;
    for(int i = 0; i < 3; i++) {
        string word = strings[i];
        for(int ii = 0; ii < word.length() + 1; ii++) {
            preprocessedStrings[word.substr(0, ii)].push_back(word);
        }   
    }

    cout << "de => [";
    for (auto s : preprocessedStrings["de"])
        cout << s << ", ";
    cout << "]\n";

    cout << "d => [";
    for (auto s : preprocessedStrings["d"])
        cout << s << ", ";
    cout << "]\n";

    cout << "deer => [";
    for (auto s : preprocessedStrings["deer"])
        cout << s << ", ";
    cout << "]\n";
    
    return 0;
}