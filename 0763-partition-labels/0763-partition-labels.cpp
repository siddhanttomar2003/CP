class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int>start(26,-1),end(26,-1);
        for(int i=0;i<s.size();i++){
            int ind=s[i]-97;
            if(start[ind]==-1)start[ind]=i;
            end[ind]=i;
        }
        int i=0;
        while(i<s.size()){
            int curr=1;
            int curr_end=end[s[i]-97];
            while(i<curr_end){
                curr_end=max(curr_end,end[s[i]-97]);
                i++;
                curr++;
            }
            ans.push_back(curr);
            i++;
        }
        return ans;
    }
};