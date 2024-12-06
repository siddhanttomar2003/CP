class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxSum) {
        long long sum=0;
        int ans=0;
        set<int>st(b.begin(),b.end());
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end() && sum+i<=maxSum){
                ans++;
                sum+=i;
            }
           
        }
        return ans;
    }
};