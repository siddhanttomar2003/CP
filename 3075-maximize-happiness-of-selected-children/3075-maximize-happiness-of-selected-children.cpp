class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>q;
        for(int i=0;i<happiness.size();i++){
            q.push(happiness[i]);
        }
        int count=0;
        long long ans=0;
        while(k){
           int add=q.top();
           if(add>0)add=q.top()-count;
           if(add<0)add=0;
           ans+=add;
           count++;
           k--;
           q.pop();
        }
        return ans;

    }
};