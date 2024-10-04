class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int i=0; int j=n-1;
        long long fir=skill[i]+skill[j];
        ans+=(skill[i]*skill[j]*1ll);
        i++;j--;
        while(i<j){
            long long curr=skill[i]+skill[j];
            if(curr!=fir)return -1;
            ans+=(skill[i]*skill[j]*1ll);
            i++;j--;
        }
        return ans;
    }
};