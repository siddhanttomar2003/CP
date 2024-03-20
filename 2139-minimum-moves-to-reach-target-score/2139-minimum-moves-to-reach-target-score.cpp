class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count=0;
         while(target>0&&maxDoubles>0){
            if(target==1)return count;
            if(target&1){
                target-=1;
                count++;
            }
            else{
                target/=2;
                count++;
                maxDoubles--;
            }
         }
        if(target!=1)count+=target-1;
        return count;
    }
};