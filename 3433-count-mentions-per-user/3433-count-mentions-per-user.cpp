class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // to check offline use a map 
        map<int,vector<int>>mp;
        for(auto it:events){
            string Event_type=it[0];
            if(Event_type=="OFFLINE"){
                int time_stamp=stoi(it[1]);
                int id=stoi(it[2]);
                mp[id].push_back(time_stamp);
            }
        }
        for(auto it:mp){
            sort(mp[it.first].begin(),mp[it.first].end());
        }
        // for(auto it:mp){
        //     cout<<it.first<<" ->";
        //     vector<int>temp=it.second;
        //     for(int i=0;i<temp.size();i++)cout<<temp[i]<<" ";
        //     cout<<endl;
        // }
        vector<int>mentions(numberOfUsers);

        for(auto it:events){
            if(it[0]=="MESSAGE"){
                int curr_time=stoi(it[1]);
                string test=it[2];
                if(test=="ALL"){
                    for(int i=0;i<mentions.size();i++){
                        mentions[i]++;
                    }
                }
                else if(test=="HERE"){
                    for(int i=0;i<mentions.size();i++){
                        vector<int>temp=mp[i];
                        int s=temp.size();
                        if(s==0){
                            mentions[i]++;
                            continue;
                        }
                        auto iter=lower_bound(temp.begin(),temp.end(),curr_time)-temp.begin();
                        if(iter==s){
                            iter--;
                            if(temp[iter]+60<=curr_time)mentions[i]++;
                        }
                        else if(temp[iter]>curr_time){
                            iter--;
                            if(iter<0)mentions[i]++;
                            else {
                                if(temp[iter]+60<=curr_time)mentions[i]++;
                            }
                        }

                    }
                }
                else {
                    for(int i=0;i<test.size();i++){
                        string c="";
                        if(test[i]>=48 && test[i]<=57){
                            while(i<test.size() && test[i]>=48 && test[i]<=57){
                            c+=test[i];
                            i++;
                            }
                            int id=stoi(c);
                            mentions[id]++;
                        }
                    }
                }
            }
        }
        return mentions;

        
    }
};