class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float,float>>ps;
        int n=position.size();
        for(int i=0;i<n;i++){
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end());
        int count=0;
        double last=(target-ps[n-1].first)/ps[n-1].second;
        for(int i=n-2;i>=0;i--){
            double dis=(double)target-ps[i].first;
            double t=dis/ps[i].second;
            if(t>last){
                count++;
                last=t;
            }
        }
        return count+1;
    }
};
