class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        long long ans=0;
        priority_queue<long long >pq;
        for(int i=0;i<g.size();i++){
            pq.push(g[i]);
        }
        while(pq.size()>0 && k--){
            long long num=pq.top();
            if(num==1)break;
            pq.pop();
            pq.push(sqrtl(num));
        }
        while(pq.size()>0){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};