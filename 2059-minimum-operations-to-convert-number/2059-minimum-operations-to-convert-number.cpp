typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<ll>steps(1001,1e9);
        priority_queue<vl,vector<vl>,greater<vl>>pq;
        pq.push({0,start});
        steps[start]=0;
        while(pq.size()>0){
            ll num=pq.top()[1];
            int step=pq.top()[0];
            pq.pop();
            for(int i=0;i<nums.size();i++){
                if(((ll)nums[i]+num)==goal || (num-(ll)nums[i])==goal || (num^((ll)nums[i]))==goal)return step+1;
                ll add=((ll)nums[i])+num;
                ll sub=num-((ll)nums[i]);
                if(add<=1000 && add>=0 && steps[add]>1+step){
                    steps[add]=1+step;
                    pq.push({steps[add],add});
                }
                if(sub>=0 && sub<=1000 && steps[sub]>1+step){
                    steps[sub]=1+step;
                    pq.push({steps[sub],sub});
                }
                ll xori = num ^ ((ll)(nums[i]));
                if(xori<=1000 && xori>=0 && steps[xori]>1+step){
                    steps[xori]=1+step;
                    pq.push({steps[xori],xori});
                }
            }
        }
        return -1;
    }
};