class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        for(auto it:tasks){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)pq.push({it.second,it.first});
        int curr=0;
        
        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            vector<pair<int,char>>v;
            it.first--;
            curr++;
            bool check=false;
            if(it.first==0)check=true;
            else v.push_back(it);
            for(int i=0;i<n;i++){
                if(!pq.empty()){
                    auto it2=pq.top();
                    pq.pop();
                    it2.first--;
                    if(it2.first!=0){
                    v.push_back(it2);
                    }
                    curr++;
                }
                else if(check && pq.empty())return curr;
                else {
                   curr++;
                }
            }
            for(int i=0;i<v.size();i++)pq.push(v[i]);
        }
        return curr;
    }
};