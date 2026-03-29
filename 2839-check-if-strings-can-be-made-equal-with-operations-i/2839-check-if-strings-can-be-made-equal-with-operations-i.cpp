class Solution {
public:
        bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    bool canBeEqual(string s1, string s2) {
                vector<int>odd1(26,0),odd2(26,0),even1(26,0),even2(26,0);
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(i&1){
                odd1[s1[i]-97]++;
                odd2[s2[i]-97]++;
            }
            else {
                even1[s1[i]-97]++;
                even2[s2[i]-97]++;
            }
        }
        bool f1=check(odd1,odd2);
        bool f2=check(even1,even2);
        return f1 && f2;
    }
};