class Twitter {
public:
    map<int,set<int>>adj;
    map<int,vector<pair<int,int>>>tw;
    int t;
    Twitter() {
        t=0;
    } 
    
    void postTweet(int userId, int tweetId) {
        tw[userId].push_back({t++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        adj[userId].insert(userId);
        vector<pair<int,int>>ans;
        for(auto it:adj[userId]){
            int size=tw[it].size();
            vector<pair<int,int>>&v=tw[it];
            for(int i=size-1;i>=0;i--){
                if(v[i].first>=t-10){
                  ans.push_back(v[i]);
                }
                else break;
            }
        }
        sort(ans.rbegin(),ans.rend());
        vector<int>f_ans;
        for(auto it:ans)f_ans.push_back(it.second);
        return f_ans;
    }
    
    void follow(int followerId, int followeeId) {
        adj[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        adj[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */