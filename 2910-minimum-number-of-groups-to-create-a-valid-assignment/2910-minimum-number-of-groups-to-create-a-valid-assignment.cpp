class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        int n=balls.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[balls[i]]++;
        }
        int boxes=INT_MAX;
        int minireq=INT_MAX;
        for(auto it:mp){
           minireq=min(minireq,it.second);
        }
        cout<<minireq<<endl;
       for(int i=1;i<=minireq;i++){
        int curr=0;
        for(auto it:mp){
            
            if(it.second%(i+1)==0)
               curr+=it.second/(i+1);
            else if(i<=(it.second%(i+1)+it.second/(i+1))) curr+=(it.second/(i+1)+1); 
            else {
                curr=1e9;break;
            }
        }
        boxes=min(boxes,curr);
       }
        return boxes;
    }
};