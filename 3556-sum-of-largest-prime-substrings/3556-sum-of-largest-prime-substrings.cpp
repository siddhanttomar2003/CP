class Solution {
public:
typedef long long ll;
    bool check(ll a){
        if(a==1)return false;
        for(ll i=2;i<=sqrtl(a);i++){
            if(a%i==0)return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long ans=0;
        set<long long>vis;
        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                long long a=stoll(temp);
                if(check(a))vis.insert(a);
            }
        }
        vector<ll>f_ans;
        for(auto it:vis){
            f_ans.push_back(it);
        }
        int d=f_ans.size();
        for(int i=d-1;i>=max(0,d-3);i--)ans+=f_ans[i];
        return ans;
    }
};