class Solution {
public:
    int maxDistance(string S, int k) {
        int ans=0;
        int w=0,e=0,n=0,s=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='W')w++;
            else if(S[i]=='E')e++;
            else if(S[i]=='S')s++;
            else n++;
            int curr_dis=abs(w-e)+abs(s-n);
            int fixed_x=min(w,e);
            int fixed_y=min(s,n);
            int rem_x=max(w,e);
            int rem_y=max(s,n);
            if(fixed_x+fixed_y>=k){
                curr_dis+=2*k;
            }
            else {
                curr_dis+=(2*(fixed_x+fixed_y));
                // int rem=(k-((fixed_x+fixed_y)));
                // if(rem_x+rem_y>=rem){
                //     curr_dis+=rem;
                // }
                // else {
                //     curr_dis+=(rem_x+rem_y);
                // }
            }
            ans=max(ans,curr_dis);
        }
        return ans;
    }
};