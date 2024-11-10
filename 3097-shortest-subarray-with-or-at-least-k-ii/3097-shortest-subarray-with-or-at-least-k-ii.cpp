class Solution {
public:
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //Most importent observation here is that  bitwiseOR(a,b)>=max(a,b);
        // so when ever we find the window have value greater than or eqaul to k . we can trim the window;
        
        vector<int>one(32,0);//stores number of one at each bit in a window
        int i=0;
        int ans=1e9;
        for(int j=0;j<nums.size();j++)
        {
            for(int k=0;k<32;k++)
            {
                if(nums[j]&(1<<k))one[k]++;
            }
            long num=0;
            for(int k=0;k<32;k++)if(one[k])num+=(long)pow(2,k);
            
            while(num>=k&&i<=j)
            {
                ans=min(ans,j-i+1);
                for(int k=0;k<32;k++)
                 {
                    if(nums[i]&(1<<k))one[k]--; 
                 }
                long long newNum=0;
                for(int k=0;k<32;k++)if(one[k])newNum+=(long)pow(2,k);
                
                num=newNum;
                i++;
            }
        }
        return ans==1e9?-1:ans;
    }
};