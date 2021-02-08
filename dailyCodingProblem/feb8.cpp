/*
This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.

*/

//scheduler keeps track of millis
//class scheduler
    // current time
    // schedule
//scheduler.schedule(function f, int n) 
    // {setStart function at current time + n}

//scheduler for parallel computing or sequential jobs?
//if sequential, then keep checking if time to start immediate next job is reached
    //keep polling time
// would be nice to use interrupts and an event-based structure
// job scheduler might do other things, too, like assign priority

//lets do sequential job scheduler for single core

#include <iostream>
#include <sys/time.h>
#include <vector>
#include <functional>


using namespace std;
struct timeval tp;

//scheduler allows a delayed callback to some function
class Scheduler {
    private:
        vector<pair<std::function<void (void)>, long int>> jobs; //ordered list with a value pair of function and time
    public:
        //get millis of now
        long int now() {
            //inspiration from https://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
            gettimeofday(&tp, NULL);
            long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
            return ms;
        };
        void schedule(std::function<void (void)> f, int n) {
            long int functionScheduledAt = now() + n; //calculate time at which function is scheduled
            pair< std::function<void (void)>, long int> job = make_pair(f, functionScheduledAt);

            if(jobs.size()) {   //if scheduler has some jobs, 
            //find the first job scheduled after new job, insert before that job
                bool inserted = false;
                for (int i = 0; i < jobs.size(); i++) 
                    if (jobs[i].second > functionScheduledAt) {
                        jobs.insert(jobs.begin() + i, job);
                        inserted = true;
                    }
                if (!inserted) //otherwise, schedule job to end
                    jobs.push_back(job);
            }
            else    //if scheduler empty, add job to begin
                jobs.insert(jobs.begin(), job);
        };
        //peek at the next job to be scheduled
        pair<std::function<void (void)>, long int> nextJob() {
            return jobs[0];
        };
        //scheduler polls schedule continuously until all jobs completed
        void start() {
            while(jobs.size()) { //so long as there are jobs scheduled
                if(jobs[0].second < now()) { //and the starting point of the first schedule has passed
                    //execute
                    jobs[0].first();
                    jobs.erase(jobs.begin());
                }
            }
        };
        //get size of schedule
        int size() {
            return jobs.size();
        }
    
        
};

void myFunc()
{
    cout << "hello" << endl;
}

void myFunc2()
{
    cout << "hello 2" << endl;
}

int main() {
    Scheduler s;

    s.schedule(myFunc, 1000);
    s.schedule(myFunc2, 1100);
    s.schedule(myFunc, 2000);
    cout << s.size() << endl;


    s.start();

    return 0;
}