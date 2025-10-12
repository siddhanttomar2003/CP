typedef long long ll;
class ExamTracker {
public:
    map<ll, ll>mp;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        int t = time;
        auto it = mp.lower_bound(t);
        if(it != mp.begin()){
            auto it2 = prev(it);
            ll sum = it2 -> second;
            mp[time] = (ll)score + sum;
        }
        else {
            mp[time] = (ll)score;
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        ll start = 0, end = 0;
        auto it = mp.upper_bound(startTime - 1);
        if(it != mp.begin()){
            auto it3 = prev(it);
            start = it3 -> second;
        }
        auto it2 = mp.upper_bound(endTime);
        if(it2 != mp.begin()){
            auto it3 = prev(it2);
            end = it3 -> second;
        }
        return end - start;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */