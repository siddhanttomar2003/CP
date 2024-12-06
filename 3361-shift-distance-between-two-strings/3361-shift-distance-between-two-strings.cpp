class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans=0;
        for(int i=0;i<s.size();i++){
            long long curr1=0;
            long long curr2=0;
            int num1=s[i]-97;
            int a=num1;
            int num2=t[i]-97;
            int b=num2;
            if(a==b){
                continue;
            }
            while(a!=b){
                curr1+=nextCost[a];
                a=(a+1)%26;
            }
            while(num1!=num2){
                curr2+=previousCost[num1];
                num1-=1;
                if(num1<0)num1=25;
            }
            ans+=(min(curr1,curr2));
        }
        return ans;
    }
};