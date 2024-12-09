class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int>p1,vector<int>p2){
            return p1[1]<p2[1];
        });
        int n=pairs.size();
        int count=1;
        int last=pairs[0][1];
        for(int i=1;i<n;i++){
            int start=pairs[i][0];
            int end=pairs[i][1];
            if(start>last){
                count++;
                last=end;
            }
        }
        return count;

    }
};