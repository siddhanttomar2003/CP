class Solution {
public:
   
    int ladderLength(string start, string end, vector<string>& wordList) {
        map<string,vector<string>>adj;
        set<string>words(wordList.begin(),wordList.end());
        if(words.find(end)==words.end())return 0;
        wordList.push_back(start);
        map<string,int>dis;
        for(auto it:wordList){
            string temp=it;
            dis[temp]=1e9;
             for(int i=0;i<temp.size();i++){
                for(int j=0;j<26;j++){
                    char c= temp[i];
                    temp[i]=(char)(97+j);
                    if(words.find(temp)!=words.end()){
                        adj[it].push_back(temp);
                    }
                    temp[i]=c;
                }
             }
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        dis[start]=0;
        pq.push({0,start});
        while(pq.size()>0){
            int curr_dis=pq.top().first;
            string par=pq.top().second;
            pq.pop();
            for(auto it:adj[par]){
                if(dis[it]>curr_dis+1){
                    dis[it]=curr_dis+1;
                    if(it==end)return curr_dis+2;
                    pq.push({curr_dis+1,it});
                    
                }
            }
        }
        return 0;
    }
};