class Solution {
public:
    typedef long long ll;
    int cal(int num){
        string ans = "";
        int a = num;
        while(a){
            ans += (a % 2) + 48;
            a /= 2;
        }
        reverse(ans.begin(), ans.end());
        // cout << ans << endl;
        while(ans.size() > 0 && ans.back() == '0')ans.pop_back();
        reverse(ans.begin(), ans.end());
        ll curr = 1;
        int b = 0;
        for(int i = ans.size() - 1; i >= 0; i--){
            if(ans[i] == '1')b += curr;
            curr *= 2;
        }
        return b;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>>v;
        for(int i = 0; i < n; i++){
            v.push_back({nums[i], cal(nums[i])});
        }
        // for(int i = 0; i < v.size(); i++)cout << v[i].second << " ";
        // return nums;
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
        vector<int>ans;
        for(auto it : v)ans.push_back(it.first);
        return ans;
    }
};