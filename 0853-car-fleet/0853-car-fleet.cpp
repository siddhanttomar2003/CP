class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float,float>>ps;
        int n=position.size();
        for(int i=0;i<n;i++){
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end());
        stack<double>st;
        int count=0;
        for(int i=n-1;i>=0;i--){
            double dis=(double)target-ps[i].first;
            double t=dis/ps[i].second;
            if(st.size()==0){
                 st.push(t);
                 continue;
            }
            while(!st.empty() && t>st.top()){
                count++;
                st.pop();
            }
            if(st.size()==0)st.push(t);
        }
        int add=0;
        if(st.size()>0)add=1;
        return count+add;
    }
};
