class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[A[i]]=max(mp[A[i]],i);
            mp[B[i]]=max(mp[B[i]],i);
        }
     vector<int>f_ans(n);
     for(auto it:mp){
        f_ans[it.second]++;
     }
     int curr=f_ans[0];
     for(int i=1;i<n;i++){
        curr+=f_ans[i];
        f_ans[i]=curr;
     }
     return f_ans;

    }
};