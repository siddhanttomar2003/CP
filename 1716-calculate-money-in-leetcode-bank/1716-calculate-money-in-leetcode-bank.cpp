class Solution {
public:
    int totalMoney(int n) {
        int count=0;
        int ans=0;
        int a=1;
        while(a<=n){
         if(a%7==1){
             count++;
             ans+=count;
         }
         else if(a%7==0){
             ans+=count+7-1;
         }
         else {
             ans+=count+a%7-1;
         }
         a++;
        }
        return ans;

         
        }
};