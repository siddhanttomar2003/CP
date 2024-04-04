typedef pair<int,string> pis;
class myCompare{
    public:
    bool operator() (pis &p1,pis&p2){
        if(p1.first==p2.first)return p1.second<p2.second;
        return p1.first>p2.first;
    }
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        priority_queue<pis,vector<pis>,myCompare>min_heap;
        for(auto it:mp){
            min_heap.push({it.second,it.first});
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        vector<string>ans;
        while(min_heap.size()>0){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};