class FindSumPairs {
public:
    vector<int>arr1,arr2;
    map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(auto it : nums2)mp[it]++;
    }
    
    void add(int index, int val) {
        int curr_val = arr2[index];
        mp[curr_val]--;
        if(mp[curr_val] == 0)mp.erase(curr_val);
        arr2[index] += val;
        mp[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0; i < arr1.size(); i++){
            int tar = tot - arr1[i];
            if(mp.find(tar) != mp.end())ans += mp[tar];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */