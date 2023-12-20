class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int i=0;
        int count=0;
        int n=v.size();
        while(k>0&&i<n){
         k-=v[i];
         if(k>=0)count++;
         else break;
         i++;
        }
        return n-count;
    }
};