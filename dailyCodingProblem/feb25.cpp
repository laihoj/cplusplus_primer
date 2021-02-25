/*
This problem was asked by Snapchat.

Given an array of time intervals (start, end) 
for classroom lectures (possibly overlapping), 
find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

//start and end are in integer minutes
//construct a schedule given the lecture timings
//schedule is array of length max end

//time complexity is linear with number of lectures by duration of lectures
//space complexity is linear to length time in a day

#include <iostream>
#include <vector>
#include <utility>      // std::pair, std::make_pair


using namespace std;

int main() {
    pair<int, int> lect_1 = make_pair(30,75);
    pair<int, int> lect_2 = make_pair(0,50);
    pair<int, int> lect_3 = make_pair(60,150);

    pair<int, int> lectures[] = { lect_1, lect_2, lect_3 } ; //given this array, should return 2

    int schedule[150] = {0}; //schedule stores how many lectures overlap at any moment

    for(pair<int, int> lecture: lectures) {
        cout << "lecture from " << lecture.first <<" to " << lecture.second << endl;
        for(int i = lecture.first - 1; i < lecture.second; i++) {
            schedule[i] = schedule[i] + 1;
        }
    }

    //find max number in array
    int max_overlap = 0;
    for(int overlap: schedule) {        
        (overlap > max_overlap) ? max_overlap = overlap : 1;
    }

    cout << max_overlap << endl;
    
    return 0;
}
