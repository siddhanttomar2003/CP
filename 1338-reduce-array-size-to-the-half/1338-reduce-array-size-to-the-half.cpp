class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>v;
        for(auto it:mp){
            v.push_back(it.second);
            
        }
        sort(v.begin(),v.end());
        int count=0;
        int sum=0;
        for(int i=v.size()-1;i>=0;i--){
         sum+=v[i];
         count++;
         if(sum>=arr.size()/2)break;
        }
        return count;
    }
};