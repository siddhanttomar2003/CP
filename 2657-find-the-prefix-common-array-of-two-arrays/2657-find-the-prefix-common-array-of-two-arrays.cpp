class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, int>mp1, mp2;
        int n = A.size();
        int count = 0;
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            int a = A[i], b = B[i];
            if(mp2.find(a) != mp2.end()){
                count++;
            }
            if(mp1.find(b) != mp1.end())count++;
            if(a == b)count++;
            mp1[a]++,mp2[b]++;
            ans[i] = count;
        }
        return ans;
    }
};