class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        long long rem_sum=k%sum;
        int pos=-1;
        for(int i=0;i<n;i++){
            if(chalk[i]>rem_sum)return i;
            else rem_sum-=chalk[i];
        }
        return pos;

    }
};