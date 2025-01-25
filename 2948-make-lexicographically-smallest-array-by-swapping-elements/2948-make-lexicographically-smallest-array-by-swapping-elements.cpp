class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>ans;
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int count=0;
        map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        mp[count].push(temp[0]);
        map<int,int>ele_ind;
        ele_ind[temp[0]]=count;
        for(int i=1;i<n;i++){
            if(temp[i]-temp[i-1]<=limit){
              mp[count].push(temp[i]);
              ele_ind[temp[i]]=count;
            }
            else {
                count++;
                mp[count].push(temp[i]);
                ele_ind[temp[i]]=count;
            }
        }
        for(int i=0;i<n;i++){
             ans.push_back(mp[ele_ind[nums[i]]].top());
             mp[ele_ind[nums[i]]].pop();
        }
        return ans;

    }
};