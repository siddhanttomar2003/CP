class Solution {
public:
  

    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<32;i++){
            if(c&(1<<i)){
                if((a&(1<<i))<1){
                    if((b&(1<<i))<1)ans++;
                }
            }
        
            else{
                if((a&(1<<i))>0)ans++;
                if((b&(1<<i))>0)ans++;
            }
        }
        return ans;
    }
};