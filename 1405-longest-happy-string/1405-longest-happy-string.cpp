class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        bool check_full = false;
        int maxi = max({a, b, c});
        int sum = a + b + c;
        sum -= maxi;
        char m, r1,r2;
        int req = maxi/2 - 1  + maxi%2;
        if (sum >= req)
            check_full = true;
        int rem1 = 0;
        int rem2 = 0;
        if (a == maxi) {
            m='a';
            rem1 = b; r1='b';
            rem2 = c;r2='c';
        } else if (b == maxi) {
            m='b';
            rem1 = a; r1='a';
            rem2 = c; r2='c';
        } else {
            m='c';
            rem1 = a; r1='a';
            rem2 = b; r2='b';
        }
        if (!check_full) {
            maxi=(rem1+rem2)*2+2;
        }
        string ans="";
        while(rem1+rem2>req){
            if(rem1==0 || rem2==0)break;
             ans+=r1;
             rem1--;
             if(rem1+rem2>req){
                ans+=r2;
                rem2--;
             }
        }
        cout<<maxi<<endl;
        while(maxi>0 && rem1 || rem2){
            int re=maxi/2 -1 + maxi%2;
            if(rem1+rem2==re){
                if(rem1>0){
                    ans+=m;
                    if(maxi>1)ans+=m;
                    ans+=r1;
                    maxi--;
                    if(maxi>1)maxi--;
                    rem1--;
                }
                else {
                    ans+=m;
                    if(maxi>1)ans+=m;
                    ans+=r2;
                    maxi--;
                    if(maxi>1)maxi--;
                    rem2--;
                }
            }
            else {
                if(rem1>0){
                    ans+=m;
                    ans+=r1;maxi--;rem1--;
                }
                else if(rem2>0){
                    ans+=m;
                    ans+=r2;
                    maxi--;rem2--;
                }
            }
        }
        while(maxi){
            ans+=m;maxi--;
        }
        return ans;

   }
};