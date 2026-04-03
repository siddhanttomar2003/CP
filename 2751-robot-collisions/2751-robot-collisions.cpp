class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        vector<pair<int, int>>v;
        int n = p.size();
        for(int i = 0; i < n; i++){
            v.push_back({p[i], i});
        }
        sort(v.begin(), v.end());
        stack<int>st;
        for(int i = 0; i < n; i++){
            int pos = v[i].second;
            // cout << pos << " ";
            char dir = d[pos];
            if(dir == 'L'){
                while(st.size() > 0 && d[st.top()] == 'R' && h[st.top()] < h[pos]){
                    h[st.top()] = 0;
                    st.pop();
                    h[pos] -= 1;
                }
                if(st.size() > 0 && d[st.top()] == 'R'){
                    if(h[st.top()] == h[pos]){
                        h[st.top()] = 0;
                        st.pop();
                        h[pos] = 0;
                    }
                    else {
                        h[pos] = 0;
                        h[st.top()] -= 1;
                    }
                }
            }
            else {
                st.push(pos);
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
          if(h[i] > 0)ans.push_back(h[i]);
        }
        return ans;
    }
};