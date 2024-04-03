class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxh;
        for(int i=0;i<arr.size();i++){
            pair<int,int>p;
            p.first=abs(arr[i]-x);
            p.second=arr[i];
            maxh.push(p);
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<int>ans;
        while(maxh.size()>0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};