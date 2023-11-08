class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>v;
        int maxi=arr[arr.size()-1];
        for(int i=arr.size()-1;i>0;i--){
          maxi=max(maxi,arr[i]);
          v.push_back(maxi);
        }
        reverse(v.begin(),v.end());

       
          
        v.push_back(-1);
      return v;
    }
};