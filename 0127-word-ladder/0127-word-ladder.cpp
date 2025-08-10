class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int>mp;
        for(auto it : wordList){
            mp[it]++;
        }
        mp[beginWord]++;
        if(mp.find(endWord) == mp.end())return 0;
        queue<pair<int,string>>q;
        map<string,int>dis;
        q.push({0, beginWord});
        dis[beginWord] = 0;
        while(q.size() > 0){
            int curr = q.front().first;
            string temp = q.front().second;
            q.pop();
            for(int i = 0; i < temp.size(); i++){
                 for(int j = 0; j < 26; j ++){
                    char c = temp[i];
                    temp[i] = (char)(j + 97);
                    if(mp.find(temp) != mp.end() && dis.find(temp) == dis.end()){
                        if(temp == endWord)return curr + 2;
                        dis[temp]++;
                        q.push({curr + 1, temp});
                    }
                    temp[i] = c;
                 }
            }
        }
        return 0;
    }
};