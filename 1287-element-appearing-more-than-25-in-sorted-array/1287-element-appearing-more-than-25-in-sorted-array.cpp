class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int ans=arr[0];
        for(auto it:mpp){
            if(it.second>n/4)ans=it.first;
        }
        return ans;
        
    }
};