#include <vector>
using namespace std;

class ExamTracker {
private:
    vector<int> times;
    vector<long long> prefix;

public:
    ExamTracker() {}
    
    void record(int time, int score) {
        times.push_back(time);
        if (prefix.empty()) {
            prefix.push_back(score);
        } else {
            prefix.push_back(prefix.back() + score);
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        int left = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int right = upper_bound(times.begin(), times.end(), endTime) - times.begin() - 1;
        
        if (left > right) return 0;
        
        return prefix[right] - (left > 0 ? prefix[left - 1] : 0);
    }
};
/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
