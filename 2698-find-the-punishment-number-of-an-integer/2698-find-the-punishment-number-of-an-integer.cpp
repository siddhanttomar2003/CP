class Solution {
public:
    bool cal(int i, string &temp, int a, int curr){
        if(i==temp.size()){
             return curr==a;
        }
        bool ans=false;
        int num=0;
        for(int j=i;j<temp.size();j++){
            num=num*10+(temp[j]-48);
            ans|=cal(j+1,temp,a,curr+num);
        }
        return ans;
    }
    bool check(int a){
       string temp=to_string(a*a);
       return cal(0,temp,a,0);
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(check(i)){
                ans+=(i*i);
            }
        }
        return ans;
    }
};