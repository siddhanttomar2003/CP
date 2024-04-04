class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      sort(nums1.begin(),nums1.end());
      sort(nums2.begin(),nums2.end());
      vector<int>ans;
      int i=0;int j=nums1.size();
      int s=0;int e=nums2.size();
      while(i<j&&s<e){
        if(nums1[i]==nums2[s]){
             ans.push_back(nums1[i]);
             i++;s++;
        }
        else if(nums1[i]>nums2[s])s++;
        else i++;
      }
        return ans;     
    }
};