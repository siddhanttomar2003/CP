class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       int count=0;
       int n=arr.size();
       vector<int>ans;
       priority_queue<pair<double,pair<int,int>>>q;
       for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
         double a=arr[j];
         double b=arr[i];
         q.push({a/b,{arr[j],arr[i]}});
         if(q.size()>k){
            q.pop();
         }
        }
       }
       ans.push_back(q.top().second.first);
       ans.push_back(q.top().second.second);
       return ans;
    }
};