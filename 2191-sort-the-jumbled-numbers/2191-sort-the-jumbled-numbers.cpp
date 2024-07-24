class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>ans;
        map<pair<int,int>,int>mpp;
        for(int i=0;i<n;i++){
         string a=to_string(nums[i]);
         int num=0;
         for(int j=0;j<a.size();j++){
            int tempi=mapping[a[j]-48];
            num=num*10+tempi;
         }
        //  int num=stoi(temp);
         ans.push_back({num,i});
         mpp[{num,i}]=nums[i];
        }
        sort(ans.begin(),ans.end());
        vector<int>fans;
        for(int i=0;i<n;i++){
            fans.push_back(mpp[ans[i]]);
        }
        return fans;
    }
};