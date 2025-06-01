typedef long long ll;
class Solution {
public:
    void build(string &s, vector<string>&vis,vector<int>&nums, ll tar, ll pro,int i){
    
        if(i==nums.size()){
            if(tar==pro)vis.push_back(s);
            return;
        }
        if(pro*(ll)nums[i]<=tar){
            s+='1';
            build(s,vis,nums,tar,pro*(ll)(nums[i]),i+1);
            s.pop_back();
        }
        s+='0';
        build(s,vis,nums,tar,pro,i+1);
        s.pop_back();
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
        if(target==1){
            ll sum=accumulate(nums.begin(),nums.end(),0*1ll);
            if(sum==n)return true;
            return false;
        }
        vector<string>vis;
        string s="";
        ll pro=1;
        build(s,vis,nums,target,pro,0);
        ll c_pro=1;
        for(auto it:vis){
            c_pro=1;
            for(int i=0;i<n;i++){
                if(it[i]=='0'){
                    if(c_pro*(ll)nums[i]>target)break;
                    c_pro=c_pro*(ll)nums[i];
                }
                if(i==n-1 && c_pro==target)return true;
            }
            // cout<<it<<" "<<endl;
        }
        return false;
    }
};