class Solution {
public:
    bool check (vector<int>& nums1, vector<int>& nums2,int num){
        int skip=0;
        int i=0;int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]+num==nums2[j]){
                i++;j++;
            }
            else {
                i++;
                skip++;
            }
            if(skip>2)return false;
        }
        return true;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
         // store all the difference between every element it's intutive
          unordered_map<int,int>mp;
          for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                mp[nums2[j]-nums1[i]]++;
            }
          }
          // now we have to check for every possible value in map such that if
          // there exists min value for which we can eliminate two elements 
          int mini=INT_MAX;
          for(auto  it: mp){
             if(check(nums1,nums2,it.first))mini=min(mini,it.first);
          }
          return mini;
        
    }
};