class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int op=0;
        int n=nums.size();
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        for(int i=0;i<n;i++){
             pq.push(nums[i]*1ll);
        }
        while(pq.size()>0 && pq.top()<k){
            long long num1=pq.top();
            pq.pop();
            long long num2=pq.top();
            pq.pop();
            long long nnum=min(num1,num2)*2*1ll + max(num1,num2);
            pq.push(nnum);
            op++;
        }
        return op;
    }
};